all: clean strassen

strassen: strassen.c
	gcc strassen_helper.c strassen.c -o strassen -I.

clean:
	rm -f strassen