#pragma once

#include <SDL2/SDL.h>

class Game {
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		bool isRunning;
	
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
