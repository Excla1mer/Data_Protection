#include "../libs/headers.h"

int main(int argc, char **argv)
{
	uint8_t hash_key[16];
	uint8_t *tmp;
	char *file_name = argv[1];

	srand(time(NULL));

	if (file_name == NULL)
	{
		perror("Enter file_name");
		return -1;
	}

	file = fopen(file_name, "rb");

	fseek(file, 0, SEEK_END);
	long lsize = ftell(file);
	rewind(file);

	tmp = (uint8_t *)malloc(sizeof(uint8_t) * lsize);
	fread(tmp, sizeof(uint8_t), lsize, file);
	fclose(file);

	// p = 23;
	// x = 7;
	// g = 5;

	while(1)
	{
		q = random() % 90000; // q 
		if(isPrime(q))
		{
			p = 2 * q + 1;
			if(isPrime(p) && p > 255)
				break;
		}
	}

	while(1)
	{
		g = random();
		if(powMod(g, q, p) != 1 )
			break;
	}
	x = rand() % p; // Закрытый ключ
	y = powMod(g, x, p); // Открытый ключ
	printf("p = %lld g = %lld \n", p, g);
	md5((uint8_t *)tmp, lsize, hash_key);

	uint64_t s[16];
	printf("hash_key: ");
	for (int i = 0; i < 16; i++)
        printf("%2.2x", hash_key[i]);

	printf("\n");
	ElGamal_sign(hash_key, p, x, g, s);
	for (int i = 0; i < 16; i++)
		printf("s[%d] = %ld ", i, s[i]);

	printf("\n=====left=====\n");
	uint64_t left[16];
	uint64_t right[16];
	for (int i = 0; i < 16; ++i)
	{
		left[i] = powMod(powMod(y, r, p) * powMod(r, s[i], p), 1, p); 
	}
	for (int i = 0; i < 16; ++i)
	{
		right[i] = powMod(g, hash_key[i], p); 
	}
	for (int i = 0; i < 16; i++)
		printf(" %lX ", left[i]);

	printf("\n=====right=====\n");

	for (int i = 0; i < 16; i++)
		printf(" %lX ", right[i]);

	printf("\n");
	return 0;
}