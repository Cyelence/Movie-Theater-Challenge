EXE	= main

all: main

main: main.cpp Seating.cpp
	g++ -std=c++11 $^ -o $@

clean:
	rm -rf ${EXE}