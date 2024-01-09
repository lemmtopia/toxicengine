CC = g++
CFLAGS = -Wall -Wfatal-errors
SRCFILES = ./src/*.cpp ./src/Game/*.cpp ./src/Logger/*.cpp
LFLAGS = -lSDL2
EXEC = toxic

build:
	$(CC) $(CFLAGS) $(SRCFILES) -o $(EXEC) $(LFLAGS)

run:
	./$(EXEC)

clean:
	rm ./$(EXEC)
