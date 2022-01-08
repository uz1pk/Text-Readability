fleschIndex: fleschIndex.o main.o
	gcc -Wall -std=c99 -lm fleschIndex.o main.o -o fleschIndex
	
fleschIndex.o: fleschIndex.c fleschIndex.h
	gcc -Wall -std=c99 -lm -c fleschIndex.c

main.o: main.c fleschIndex.h
	gcc -Wall -std=c99 -lm -c main.c

clean:
	rm *.o fleschIndex
