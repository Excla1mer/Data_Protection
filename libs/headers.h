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

int ElGamal_sign(uint8_t hash_key[16], uint64_t p, uint64_t x, uint64_t g, uint64_t s[16]);

int rsa_sign(char * sourceFile);

int gost(uint64_t q, char * sourceFile);

FILE * file;
FILE * file1;
FILE * file2;

void md5(const uint8_t *initial_msg, size_t initial_len, uint8_t *digest);