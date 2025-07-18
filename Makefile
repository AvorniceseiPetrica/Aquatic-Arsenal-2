exe=aa2

sources_path=AA2/src/
SDL_include_path=SDL/include
AA2_include_path=AA2/include
SDL_libraries_path=SDL/lib

SOURCES=$(sources_path)main.cpp \
		$(sources_path)AA2_Game.cpp \
		$(sources_path)AA2_Tile.cpp \
		$(sources_path)AA2_TileManager.cpp \
		$(sources_path)AA2_Map.cpp \
		$(sources_path)AA2_TextureLoader.cpp \
		$(sources_path)AA2_Entity.cpp \
		$(sources_path)AA2_Creature.cpp \
		$(sources_path)AA2_Player.cpp \
		$(sources_path)AA2_LevelManager.cpp \
		$(sources_path)AA2_GraphicsContext.cpp \
		$(sources_path)AA2_Camera.cpp \
		$(sources_path)AA2_GameContext.cpp \
		$(sources_path)AA2_GameState.cpp \
		$(sources_path)AA2_MenuState.cpp \
		$(sources_path)AA2_Level.cpp  

$(exe): $(SOURCES)
	g++ $(SOURCES) -Wall -o $(exe) -I$(SDL_include_path) -I$(AA2_include_path) -L$(SDL_libraries_path) -lSDL3 -lSDL3_image


.PHONY:
clean:
	rm -f $(exe)