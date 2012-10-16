TARGET = main
LIBS = `sdl-config --libs`
CFLAGS = -O3 `sdl-config --cflags`
CC = g++


all:
	$(CC) $(CFLAGS) -c src/engine/client/main.cpp -o objects/main.o
	$(CC) -o $(TARGET) objects/main.o $(LIBS)
	strip $(TARGET)
clean:
	rm *.o 
	rm $(TARGET)
