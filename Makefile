CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXEC = build.exe
OBJS = main.o LevelManager.o
DELETES = $(OBJS) $(EXEC)

all: clean compile LevelManager.o
	$(CC) $(OBJS) -o $(EXEC) $(LIBS)

LevelManager.o: levels/LevelManager.h
	$(CC) -c levels/LevelManager.cpp -o LevelManager.o

compile:
	$(CC) -c main.cpp

clean:
	rm -f $(DELETES)
