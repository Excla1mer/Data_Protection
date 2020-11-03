#include "headers.h"

//#define TXTFILE
#define PICFILE

int Shamir(
				uint64_t p,
				uint64_t c,
				uint64_t d,
				char * file_name)
{

	file = fopen(file_name, "rb");
	if (file == NULL)
	{
		printf("File does not exist!!!\n");
		return -1;
	}

	char * file_name1;
	file_name1 = (char *)malloc(sizeof(char) * (strlen(file_name) + 1));
	strcpy(file_name1, file_name);

#ifdef TXTFILE

	char * istr = strchr(file_name1, '_');
	int f;
	if(istr == NULL)
	{
		file_name1 = strcat(file_name1, "_1");
		f = 1;
	}

	if(istr != NULL)
	{
		switch(istr[1])
		{
			case '1':
				istr = strstr(file_name1, "_1");
				istr[1] = '2';
				f = 1;
				break;

			case '2':
				istr = strstr(file_name1, "_2");
				istr[1] = '3';
				f = 0;
				break;

			case '3':
				istr = strstr(file_name1, "_3");
				istr[1] = '4';
				f = 0;
				break;
		
			default :
				break;
		}
	}

	file1 = fopen(file_name1, "wb");
	uint8_t symb_c;
	int symb;
	uint8_t x;
	size_t size_f;

	//printf("Input file %s\n Output file %s\n", file_name, file_name1);
	//printf("FILE: %c\n", istr[1]);
	while(1)
	{
		fread(&symb_c, sizeof(uint8_t), 1, file);
		
		if(feof(file))
			break;
		

		if (f == 1)
		{
			//printf("%c\n", istr[1]);
			//printf("a = %hu c = %ld p = %ld ", symb_c, c, p);
			x = powMod(symb_c, c, p);
		}
		if (f == 0)
		{
			//printf("%c\n", istr[1]);
			//printf("a = %hu d = %ld p = %ld ", symb_c, d, p);
			x = powMod(symb_c, d, p);
		}

		//printf("x = %d \n", x);
		
		size_f = fwrite(&x, sizeof(uint8_t), 1, file1);

	}
#endif
#ifdef PICFILE
	uint8_t * tmp;
	uint32_t * array;
	uint32_t * array1;
	uint32_t symb_c;
	uint32_t x;
	size_t size_f;

	file1 = fopen("decrypted_Shamir", "wb");
	file2 = fopen("encrypted_Shamir", "wb");
	fseek(file, 0, SEEK_END);
	long lsize = ftell(file);
	rewind(file);
	tmp = (uint8_t *)malloc(sizeof(uint8_t) * lsize);
	array = (uint32_t *)malloc(sizeof(uint32_t) * lsize);
	array1 = (uint32_t *)malloc(sizeof(uint32_t) * lsize);
	fread(tmp, sizeof(uint8_t), lsize, file);
	for(int j = 0; j < lsize; j++)
	{
		array[j] = (uint32_t)tmp[j];
	}
	for(uint8_t i = 0; i < 4; i++)
	{
		switch(i)
		{
			case 0:
				for(int j = 0; j < lsize; j++)
				{
					array1[j] = powMod(array[j], Ca, p);
				}
				for(int j = 0; j < lsize; j++)
				{
					array[j] = array1[j];
				}
				break;

			case 1:
				for(int j = 0; j < lsize; j++)
				{
					array1[j] = powMod(array[j], Cb, p);
				}
				for(int j = 0; j < lsize; j++)
				{
					array[j] = array1[j];
				}
				break;

			case 2:
				for(int j = 0; j < lsize; j++)
				{
					array1[j] = powMod(array[j], Da, p);
				}
				for(int j = 0; j < lsize; j++)
				{
					array[j] = array1[j];
				}

				for(int j = 0; j < lsize; j++)
				{
					fwrite(&array[j], sizeof(uint8_t), 1, file2);
				}
				break;

			case 3:
				for(int j = 0; j < lsize; j++)
				{
					array1[j] = powMod(array[j], Db, p);
				}
				for(int j = 0; j < lsize; j++)
				{
					array[j] = array1[j];
				}
				break;

			default:
				printf("error\n");
				return -1;
		}
		
	}

	for(int j = 0; j < lsize; j++)
	{
		fwrite(&array[j], sizeof(uint8_t), 1, file1);
	}


#endif
	fclose(file);
	fclose(file1);
	return 0;


}