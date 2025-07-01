exec=main
sources_path=AA2/AA2_src/
include_path=SDL/SDL_include

main: $(sources_path)main.cpp $(sources_path)AA2_GameWindow.cpp
	g++ $(sources_path)main.cpp $(sources_path)AA2_GameWindow.cpp -Wall -I$(include_path) -IAA2/AA2_include -lSDL3 -o $(exec)

.PHONY:clean
clean:
	rm -f $(exec)