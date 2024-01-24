#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "../Logger/Logger.h"

typedef int Entity; // Just an ID.

struct IPool {
    protected:
        ~IPool() = default;
};

template <typename T>
class Pool: public IPool {
    private:
        std::map<Entity, T> data;
    
    public:
        std::map<Entity, T> GetData() { return data; }
        void Set(Entity entity, T component) { 
            if (data.find(entity) != data.end()) {
                data.emplace(entity, component);
            }

            data[entity] = component; 

            std::string message = "component added to entity " + std::to_string(entity);
            Logger::Log(message.c_str());
        }
};

template <typename T>
class System {
    protected:
        std::shared_ptr<Pool<T>> myPool;

    public:
        System(std::shared_ptr<IPool> pool) { myPool = pool; }
        ~System() = default;

        virtual void Update();
};

class Manager {
    private:
        std::vector<std::shared_ptr<IPool>> pools;
        int numEntities = 0;

    public:
        Manager();
        ~Manager() = default;

        template <typename T> std::shared_ptr<Pool<T>> CreatePool();
};


template <typename T> 
std::shared_ptr<Pool<T>> Manager::CreatePool() {
    std::shared_ptr<Pool<T>> newPool = std::make_shared<Pool<T>>();
    pools.push_back(newPool);

    Logger::Log("New pool!");
    return newPool;
}
