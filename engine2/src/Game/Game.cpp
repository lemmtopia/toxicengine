#include "Game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <memory>
#include <string>

#include "../Logger/Logger.h"
#include "../ECS/ECS.h"

#include "../Components/TransformComponent.h"
#include "../Systems/RenderSystem.h"

int lastFrameTime;

Game::Game() {
    Logger::Log("Game created");
    manager = std::make_unique<Manager>();
}

void Game::Initialize() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        Logger::Err("Could not initialize SDL.\n");
		return;	
	}

    window = SDL_CreateWindow("title",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            640, 480, 0);

    if (!window) {
        Logger::Err("Could not create the window.\n");
		return;	
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        Logger::Err("Could not create the renderer.\n");
		return;	
    }

    isRunning = true;
    lastFrameTime = SDL_GetTicks();
}

void Game::Run() {
	Setup();
    while (isRunning) {
        Step();
        Draw();
    }
}

void Game::Setup() {
    std::shared_ptr<Pool<TransformComponent>> pool1 = manager->CreatePool<TransformComponent>();
    TransformComponent tComponent = {20, 20, 1, 1, 0};

    pool1->Set(0, tComponent);

    for (auto c: pool1->GetData()) {
        std::string message = std::to_string(c.first) + ": " + std::to_string(c.second.x);
        Logger::Log(message.c_str());
    }
}

void Game::Step() {
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        isRunning = false;
    }

    float deltaTime = (SDL_GetTicks() - lastFrameTime) / 1000.0f;
    lastFrameTime = SDL_GetTicks();
}

void Game::Draw() {
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}
