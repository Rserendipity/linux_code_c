.PHONY:clean
.PHONY:all

all:click serve

click: click.cpp
	g++ -o $@ $^

serve: serve.cpp
	g++ -o $@ $^
	
clean:
	rm -rf click serve pipe