#ifndef ECS_H
#define ECS_H

#include <vector>

class Entity {
	private:
		int id;
	
	public:
		Entity(int id);
		~Entity() = default;

		int GetId();
};

/* Manager */
class Manager {
	private:
		int numEntities = 0;

	public:
		Manager();
		~Manager();
	
		Entity CreateEntity();
		void Update();
};

#endif
