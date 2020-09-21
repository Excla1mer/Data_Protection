
# all: *.o
# 	gcc *.o -o result
# 	rm *.o

# *.o: *.c
# 	gcc *.c -c -g -lm
all: main.o powMod.o ExtendedEuclied.o 
		gcc *.o -o result
		rm *.o
main.o: main.c
		gcc main.c -c -g
powMod.o: powMod.c
		gcc powMod.c -c -g

ExtendedEuclied.o: ExtendedEuclied.c
		gcc ExtendedEuclied.c -c -g

isPrime.o: isPrime.c
		gcc isPrime.c -c -g -lm



clean:
		rm *.o result
