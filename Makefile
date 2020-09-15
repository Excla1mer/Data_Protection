

all: main.o powMod.o
		gcc *.o -o result
		rm *.o
main.o: main.c
		gcc main.c -c -g
powMod.o: powMod.c
		gcc powMod.c -c -g

isPrime.o: isPrime.c
		gcc isPrime.c -c -g

clean:
		rm *.o result
