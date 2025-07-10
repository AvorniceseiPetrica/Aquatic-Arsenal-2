sources_path=AA2/
SDL_include_path=SDL/include
SDL_libraries_path=SDL/lib

main:
	g++ $(sources_path)main.cpp -Wall -o main -I$(SDL_include_path) -L$(SDL_libraries_path) -lSDL3 -lSDL3_image


.PHONY:
clean:
	rm -f main