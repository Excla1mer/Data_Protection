

lib: powMod.o ExtendedEuclied.o isPrime.o DiffiHellman.o BabyGiant.o Shamir.o
		ar rc libmy_lib.a *.o
		rm *.o

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


Shamir.o: Shamir.c
		gcc Shamir.c -c -g -lm

	
