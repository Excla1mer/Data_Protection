
lib: powMod.o ExtendedEuclied.o isPrime.o DiffiHellman.o BabyGiant.o Shamir.o vernam.o rsa.o ElGamal_sign.o md5.o
		ar rc libmy_lib.a *.o

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

vernam.o: vernam.c
		gcc vernam.c -c -g -lm

rsa.o: rsa.c
		gcc rsa.c -c -g -lm

ElGamal_sign.o: ElGamal_sign.c
		gcc -fPIC -I/usr/include/python2.7 -lpython2.7 ElGamal_sign.c -c -g -lm 

md5.o: md5.c
		gcc md5.c -c -g -lm

clean: 
	rm *.o
	rm libmy_lib.a