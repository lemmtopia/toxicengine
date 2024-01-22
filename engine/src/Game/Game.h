#pragma once

#include <SDL2/SDL.h>
#include <memory>

#include "../ECS/ECS.h"

class Game {
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		bool isRunning;

        std::unique_ptr<Registry> registry;
	
	public:
		Game();
		~Game() = default;

		void Initialize();
		void Run();

        void Setup();
        void Step();
        void Draw();
};
