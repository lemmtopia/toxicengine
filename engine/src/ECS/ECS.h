#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "../Logger/Logger.h"

#define MAX_COMPONENTS 32

typedef std::uint8_t Entity; // Just an ID

struct IComponent {
    protected:
        inline static int nextId;
};

template <typename T>
class Component: public IComponent {
    public:
        static int GetId() {
            static auto id = nextId++;
            return id;
        }
};

struct IPool {
    public:
        virtual ~IPool() {}
};

template <typename T>
class Pool: public IPool {
    private:
        std::vector<T> data;

    public:
        virtual ~Pool() = default;

        bool IsEmpty() { return data.empty(); }
        int GetSize() { return data.size(); }
        void Resize(int n) { data.resize(n); }
        void Clear() { data.clear(); }
        void Add(T object) { data.push_back(object); }
        void Set(int index, T object) { data[index] = object; }

        T& Get(int index) { return static_cast<T&>(data[index]); }
};
        
class Registry {
    private:
        std::vector<std::shared_ptr<IPool>> componentPools;
        int numEntities = 0;

    public:
        Registry();
        ~Registry() = default;

        Entity CreateEntity(); 

        template <typename T, typename ...TArgs> void AddComponent(Entity entity, TArgs&& ...args);
};

template <typename T, typename ...TArgs>
void Registry::AddComponent(Entity entity, TArgs&& ...args) {
    const auto componentId = Component<T>::GetId();
    
    if (componentId >= componentPools.size()) {
        componentPools.resize(componentId + 1, nullptr);
    }

    if (!componentPools[componentId]) {
        std::shared_ptr<Pool<T>> newComponentPool = std::make_shared<Pool<T>>();
        componentPools[componentId] = newComponentPool;
    }

    std::shared_ptr<Pool<T>> componentPool = std::static_pointer_cast<Pool<T>>(componentPools[componentId]);

    if (entity >= componentPool->GetSize()) {
        componentPool->Resize(numEntities);
    }

    T newComponent(std::forward<TArgs>(args)...);

    componentPool->Set(entity, newComponent);

    std::string message = "Component " + std::to_string(componentId) + " added to entity " + std::to_string(entity);
    Logger::Log(message.c_str());
}
