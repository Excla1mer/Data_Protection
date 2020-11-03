#include "headers.h"


int ElGamal(char * file_name, uint64_t C, uint64_t D)
{
	file = fopen(file_name, "rb");
	
	uint8_t * tmp;
	uint32_t * m;
	uint32_t * m1;
	uint32_t * e;
	uint32_t symb_c;
	uint32_t x;
	uint64_t k = rand() % (p-2);
	//uint64_t k = 7;
	uint64_t r = powMod(g, k, p);

	printf("k = %ld r = %ld \n", k, r);
	file1 = fopen("encrypted_ElGamal", "wb");
	file2 = fopen("decrypted_ElGamal", "wb");
	fseek(file, 0, SEEK_END);
	long lsize = ftell(file);
	rewind(file);
	tmp = (uint8_t *)malloc(sizeof(uint8_t) * lsize);
	m = (uint32_t *)malloc(sizeof(uint32_t) * lsize);
	m1 = (uint32_t *)malloc(sizeof(uint32_t) * lsize);
	e = (uint32_t *)malloc(sizeof(uint32_t) * lsize);
	fread(tmp, sizeof(uint8_t), lsize, file);

	for(int j = 0; j < lsize; j++)
	{
		m[j] = (uint32_t)tmp[j];
	}

	for(int j = 0; j < lsize; j++)
	{
		e[j] = powMod(m[j] * powMod(D, k, p), 1, p);
	}

	for(int j = 0; j < lsize; j++)
	{
		fwrite(&e[j], sizeof(uint8_t), 1, file1);
	}

	for(int j = 0; j < lsize; j++)
	{
		m1[j] = powMod(e[j] * powMod(r, (p - 1 - C), p), 1, p);
	}

	for(int j = 0; j < lsize; j++)
	{
		fwrite(&m1[j], sizeof(uint8_t), 1, file2);
	}


	return 0;
}