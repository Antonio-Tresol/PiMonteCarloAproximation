.PHONY: build run clean test

# The default target of this Makefile is build which builds the project.
default: build

# to compile the project, type 'make build'
build:
	mkdir -p build
	mkdir -p bin
	gcc -c src/main.c -o build/main.o
	gcc -c src/montecarlo_simulation.c -o build/montecarlo_simulation.o -I src
	gcc build/main.o build/montecarlo_simulation.o -o bin/main -lm -fopenmp

# To run the project, type 'make run'
run: build
	./bin/main

# To clean the project, type 'make clean'
clean:
	rm -rf build
	rm -rf bin

gitignore:
	echo bin >> .gitignore
	echo build >> .gitignore
	echo .vscode >> .gitignore