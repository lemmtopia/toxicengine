#pragma once

#include <SDL2/SDL.h>

#include <memory>

#include "../ECS/ECS.h"

class Game {
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		bool isRunning;

		std::unique_ptr<Manager> manager;
	public:
		Game();
		~Game();

		void Initialize();
		void Execute();
		void Destroy();

		void Setup();
		void Update();
		void Render();
};
