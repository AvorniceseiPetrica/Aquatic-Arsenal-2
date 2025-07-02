# Executable name
exec=aa2

# Paths where source files / headers are found
sources_path=AA2/AA2_src/
SDL_include_path=SDL/SDL_include
AA2_include_path=AA2/AA2_include

# Formatting what source files g++ will be working with | Format: (path)(filename)
source_files=$(sources_path)main.cpp $(sources_path)AA2_GameWindow.cpp $(sources_path)AA2_Game.cpp


# Compilation and linkage
$(exec): $(source_files)
	g++ $(source_files) -Wall -I$(SDL_include_path) -I$(AA2_include_path) -lSDL3 -o $(exec)


# Cleaning process
.PHONY:clean
clean:
	rm -f $(exec)