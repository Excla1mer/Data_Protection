#include "../libs/headers.h"

int main(int argc, char **argv)
{
	uint8_t hash_key[16];
	uint8_t *tmp;
	char *file_name = argv[1];

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

	p = 23;
	x = 7;
	g = 5;

	md5((uint8_t *)tmp, lsize, hash_key);

	printf("result = %d\n", ElGamal_sign(hash_key, p, x, g));

	for (int i = 0; i < 16; i++)
        printf("%2.2x", hash_key[i]);


	return 0;
}