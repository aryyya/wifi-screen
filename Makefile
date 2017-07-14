all:
	cc -Wextra -Wall -std=c11 -I./src src/*.c -o wifi-screen `sdl2-config --libs --cflags`
