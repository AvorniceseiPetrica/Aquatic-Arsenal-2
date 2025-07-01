exec=main
sources_path=AA2/AA2_src/

main: $(sources_path)main.cpp
	g++ $(sources_path)main.cpp -Wall -o $(exec)

.PHONY:clean
clean:
	rm -f $(exec)