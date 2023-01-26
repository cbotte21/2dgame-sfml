CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXEC = build.exe
OBJS = main.o LevelManager.o
DELETES = $(OBJS) $(EXEC)
FLAGS = -Wall -Werror -pedantic

all: clean compile LevelManager.o
	$(CC) $(OBJS) $(FLAGS) -o $(EXEC) $(LIBS)

LevelManager.o: levels/LevelManager.h
	$(CC) $(FLAGS) -c levels/LevelManager.cpp -o LevelManager.o

compile:
	$(CC) $(FLAGS) -c main.cpp

clean:
	rm -f $(DELETES)
