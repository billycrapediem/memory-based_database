

CFLAGS = -std=c99 -pedantic -Wall -Werror

PROGRAMS =


partOne:
	gcc $(CFLAGS) Tree.c -o Tree
main:
	gcc $(CFLAGS) Tree.c main.c table-driven-parser.c stack.c IntHashSet.c LinkedList.c -o main
	leaks --atExit --groupByType -- ./main
	make clean
bits:
	gcc $(CFLAGS) Tree.c main.c table-driven-parser.c stack.c IntHashSet.c LinkedList.c -o bits
clean:
	-rm $(PROGRAMS)


