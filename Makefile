CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXEC = build.exe
DELETES = main.o

all: compile
	$(CC) main.o -o $(EXEC) $(LIBS)

compile:
	$(CC) -c main.cpp

clean:
	rm -f $(DELETES) $(EXEC)
