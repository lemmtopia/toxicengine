#pragma once

#include <SDL2/SDL.h>

class Game {
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		bool isRunning;
	
	public:
		Game() = default;
		~Game() = default;

		void Initialize();
		void Run();

        void Step();
        void Draw();
};
