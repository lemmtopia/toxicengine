#include "ECS.h"

#include <string>
#include "../Logger/Logger.h"

Entity::Entity(int id) {
	this->id = id;
	
	std::string message = "Entity " + std::to_string(this->id) + " created.";
	Logger::Log(message.c_str());
}

int Entity::GetId() {
	return id;
}

Manager::Manager() {
	Logger::Log("Manager created.");
}

Manager::~Manager() {
	Logger::Log("Manager destroyed.");
}

Entity Manager::CreateEntity() {
	int entityId = numEntities;	
	numEntities++;

	Entity entity(entityId);
	return entity;
}

void Manager::Update() {

}
