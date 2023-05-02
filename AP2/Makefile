all: fatiterativo fatrecursivo fibiterativo fibrecursivo

fatiterativo:
	g++ -o bin/fatiterativo src/fatiterativo.cpp 

fatrecursivo:
	g++ -o bin/fatrecursivo src/fatrecursivo.cpp

fibiterativo:
	g++ -o bin/fibiterativo src/fibiterativo.cpp 

fibrecursivo:
	g++ -o bin/fibrecursivo src/fibrecursivo.cpp

run: all
	./bin/fatiterativo 5
	./bin/fatrecursivo 5
	./bin/fibiterativo 5
	./bin/fibrecursivo 5

clean:
	rm -f bin/**