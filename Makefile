

CFLAGS =

PROGRAMS = main



main:
	gcc $(CFLAGS) main.c relations.c -o main
	leaks --atExit --groupByType -- ./main
	-rm $(PROGRAMS)
bits:
	gcc $(CFLAGS)
clean:
	-rm $(PROGRAMS)


