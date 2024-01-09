#include <iostream>

#include "Game/Game.h"

int main(int argc, char* argv[]) {
	Game game;

	game.Initialize();
	game.Execute();
	game.Destroy();

	return 0;
}
