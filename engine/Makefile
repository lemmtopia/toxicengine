SRCFILES = src/*.cpp src/Game/*.cpp src/Logger/*.cpp src/ECS/*.cpp

build:
	g++ -Wall -Wfatal-errors $(SRCFILES) -o toxic -lSDL2 -lSDL2_image

run:
	./toxic

clean:
	rm ./toxic
