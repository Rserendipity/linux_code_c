.PHONY:clean
.PHONY:all

all:click server

click: click.cpp
	g++ -o $@ $^ -std=c++11

server: server.cpp
	g++ -o $@ $^ -std=c++11
	
clean:
	rm -rf click server