#include "ECS.h"

#include "../Logger/Logger.h"
#include <string>

Registry::Registry() {
    Logger::Log("Registry created");
}

Entity Registry::CreateEntity() {
    Entity entity = numEntities++;

    std::string message = "Entity " + std::to_string(entity) + " created.";
    Logger::Log(message.c_str());

    return entity;
}
