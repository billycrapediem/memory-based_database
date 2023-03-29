

CFLAGS =

PROGRAMS = main



main:
	gcc $(CFLAGS) main.c relations.c build_relation.c PartTwo_Three.c -o main
	leaks --atExit --groupByType -- ./main
	-rm $(PROGRAMS)
bits:
	gcc $(CFLAGS)
clean:
	-rm $(PROGRAMS)


