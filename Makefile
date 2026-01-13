JerryAssignemt: MainFirst.o Jerry.o
	gcc MainFirst.o Jerry.o -o JerryAssignemt

MainFirst.o: MainFirst.c Jerry.h Defs.h
	gcc -c MainFirst.c

Jerry.o: Jerry.c Jerry.h Defs.h
	gcc -c Jerry.c

clean:
	rm -f *.o JerryAssignemt
