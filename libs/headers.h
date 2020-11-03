#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <locale.h>

#define MAX 500

unsigned long long powMod(unsigned long long a, unsigned long long x, 
                          unsigned long long p);

int isPrime(long long p);


unsigned long long ExtendedEuclied(unsigned long long a, unsigned long long b);


unsigned long long DiffiHellman();

unsigned long long BabyGiant(unsigned long long a, unsigned long long y, 
	unsigned long long p);

unsigned long long a,x,y,p,b,g,q,Xa,Xb,Ya,Yb,Zab,Zba; // Lab1

uint64_t Ca, Cb, Da, Db, r, e, k; // Lab2




int Shamir(
				uint64_t p,
				uint64_t c,
				uint64_t d,
				char * file_name);

int vernam(char * sourceFile);

int rsa(char * sourceFile);

int ElGamal(char * file_name, uint64_t C, uint64_t D);


FILE * file;
FILE * file1;
FILE * file2;