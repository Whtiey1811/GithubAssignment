all: main

main: main.cpp
	g++ -o main main.cpp

clean:
	del main.exe
