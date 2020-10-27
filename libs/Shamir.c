#include "headers.h"

int Shamir(
				uint64_t p,
				uint64_t c,
				uint64_t d,
				char * file_name)
{
	file = fopen(file_name, "rb");

	if (file == NULL)
		return -1;

	char * file_name1;
	file_name1 = (char *)malloc(sizeof(char) * (strlen(file_name) + 1));
	strcpy(file_name1, file_name);

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
	//scanf("%d", &y);
	file1 = fopen(file_name1, "wb");
	uint8_t symb_c;
	int symb;
	uint8_t x;
	size_t size_f;
	// while ((symb = fgetc(file)) != EOF)
	// {
	// 	if (f == 1)
	// 		x = powMod(symb, c, p);
	// 	if (f == 0)
	// 		x = powMod(symb, d, p);
	// 	fwrite(&x, sizeof(char), 1, file1);
	// }
	//size_f = fwrite("H", sizeof(char), 1, file1);

	while(1)
	{
		fread(&symb_c, sizeof(uint8_t), 1, file);
		if(feof(file))
			break;
	
		//printf("symb = %d ", symb_c);

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

		//printf("x = %hu ", x);
		
		size_f = fwrite(&x, sizeof(uint8_t), 1, file1);
	}
	//fwrite("\0", sizeof(char), 1, file1);
	printf("\n");
	fclose(file);
	fclose(file1);
	return 0;


}