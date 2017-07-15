CXX_FLAGS = -Wextra -Wall -std=c++14 `sdl2-config --cflags`
LINKER_FLAGS = `sdl2-config --libs` -lSDL2_net

all:
	$(CXX) $(CXX_FLAGS) -I ./src ./src/*.cpp -o wifi-screen $(LINKER_FLAGS)

debug: CXX_FLAGS += -DDEV_MODE -g
debug: all	

clean:
	rm -rf ./wifi-screen *.dSYM
