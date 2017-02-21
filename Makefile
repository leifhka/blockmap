
compile:
	gcc -std=c99 -Wall -o blockmap blockmap.c -lcurses
run: 
	./blockmap

clean:
	rm -v ./blockmap
