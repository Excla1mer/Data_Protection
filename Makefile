
# all: *.o
# 	gcc *.o -o result
# 	rm *.o

# *.o: *.c
# 	gcc *.c -c -g -lm
all: main.o

lib: powMod.o ExtendedEuclied.o isPrime.o DiffiHellman.o BabyGiant.o
		
		ar rc libmy_lib.a *.o
		rm *.o
		mkdir libs
		mv libmy_lib.a ./libs/


main.o: main.c
		gcc main.c -o result -L./libs/ -lmy_lib -lm

powMod.o: powMod.c
		gcc powMod.c -c -g

ExtendedEuclied.o: ExtendedEuclied.c
		gcc ExtendedEuclied.c -c -g

isPrime.o: isPrime.c
		gcc isPrime.c -c -g -lm

DiffiHellman.o: DiffiHellman.c
		gcc DiffiHellman.c -c -g

BabyGiant.o: BabyGiant.c
		gcc BabyGiant.c -c -g -lm

clean:
		rm result
		rm -rf ./libs
