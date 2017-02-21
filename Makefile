
compile:
	gcc -Wall -o blockmap blockmap.c -lcurses
run: 
	./blockmap

clean:
	rm -v ./blockmap
