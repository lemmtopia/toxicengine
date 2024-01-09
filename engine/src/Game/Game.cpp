#include "Game.h"

#include "../Logger/Logger.h"

Game::Game() {

}

Game::~Game() {

}

void Game::Initialize() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		Logger::Err("Could not initialize SDL");
		return;
	}

	window = SDL_CreateWindow("title",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640, 480, 0);
	
	if (!window) {
		Logger::Err("Could not create the window");
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (!renderer) {
		Logger::Err("Could not create the renderer");
		return;
	}

	Logger::Log("Game initialized!");
	isRunning = true;
}

void Game::Execute() {
	Setup();
	while (isRunning) {
		Update();
		Render();
	}
}

void Game::Destroy() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::Setup() {

}

void Game::Update() {
	SDL_Event event;
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT) {
		isRunning = false;
	}
}

void Game::Render() {
	SDL_RenderClear(renderer);

	// TODO: Implement some drawing function calls

	SDL_RenderPresent(renderer);
}

