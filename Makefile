all:
	$(CXX) -Wextra -Wall -std=c++14 -I./src ./src/*.cpp -o wifi-screen `sdl2-config --libs --cflags`
