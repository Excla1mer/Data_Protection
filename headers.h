#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

unsigned long long powMod(unsigned long long a, unsigned long long x, 
                          unsigned long long p);

int isPrime(long long p);


unsigned long long ExtendedEuclied(unsigned long long a, unsigned long long b);


unsigned long long DiffiHellman();

unsigned long long BabyGiant(unsigned long long a, unsigned long long y, 
	unsigned long long p);

unsigned long long a,x,y,p,b,g,q,Xa,Xb,Ya,Yb,Zab,Zba;