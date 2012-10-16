all:
	gcc src/engine/client/main.cpp `sdl-config --libs --cflags` -I/usr/include/GL -lGL -lGLU
