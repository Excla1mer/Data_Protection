#include "headers.h"

int vernam(char * sourceFile){

	int i;
	if ((file = fopen(sourceFile, "rb")) == NULL)
		return -1;

// определяем размер файла
	fseek(file , 0 , SEEK_END);                          
	long lSize = ftell(file);                            
	rewind(file);                                       
	 
	char * buf = (char*) malloc(sizeof(char) * lSize);
	char * key = (char*) malloc(sizeof(char) * lSize); 

	fread(buf, sizeof(char), lSize, file);
//encoding
	for(i = 0; i < lSize; i++){
		key[i] = rand() % 255;
		buf[i] ^= key[i];
	}

	fclose(file);

	if ((file1 = fopen("codedFile_Vernam", "wb")) == NULL)
		return -2;
	fwrite(buf, sizeof(char), lSize, file1);
	fclose(file1);
//decoding
	for(i = 0; i < lSize; i++){
		buf[i] ^= key[i];
	}
	
	if ((file = fopen("decodedFile_Vernam", "wb")) == NULL)
		return -3;

	if ((file2 = fopen("Key_Vernam", "wb")) == NULL)
		return -2;

	for(i = 0; i < lSize; i++)
	{
		fwrite(&key[i], sizeof(char), lSize, file2);
	}

	fwrite(buf, sizeof(char), lSize, file);

	fclose(file);

	free(buf);
	free(key);
	return 0;
}
