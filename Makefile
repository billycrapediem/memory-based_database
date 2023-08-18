

CFLAGS = -std=c99

PROGRAMS = main



main:
	gcc $(CFLAGS) main.c relations.c build_relation.c PartTwo_Three.c -o main
	leaks --atExit --groupByType -- ./main
	-rm $(PROGRAMS)
project:
	gcc $(CFLAGS) main.c relations.c build_relation.c PartTwo_Three.c -o main
clean:
	-rm $(PROGRAMS)


