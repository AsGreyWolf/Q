TARGET = game
LIBS = `sdl-config --libs`
CFLAGS = -O3 `sdl-config --cflags`
CC = g++


all:
	$(CC) $(CFLAGS) -c src/engine/client/main.cpp -o game.o
	$(CC) -o $(TARGET) game.o $(LIBS)
	strip $(TARGET)
clean:
	rm *.o 
	rm $(TARGET)
