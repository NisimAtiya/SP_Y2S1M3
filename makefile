all:isort txtfind

isort:sortmain.c
	gcc -Wall -g -o isort sortmain.c

txtfind:txt.c
	gcc -Wall -g -o txtfind txt.c
clean:
	rm -f isort txtfind
.PHONY: clean all