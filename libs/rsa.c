#include "headers.h"


int euclied(int a, int b)
{
  int i;
  if(a < b){
    i = a;
    a = b;
    b = i;
  }
  int q, u[2], v[2], t[2];
  u[0] = a;
  u[1] = 0;
  v[0] = b;
  v[1] = 1;
  while(v[0] != 0) {
    q = u[0] / v[0];
    t[0] = u[0] % v[0];
    t[1] = u[1] - q * v[1];
    for(i = 0; i < 2; i++){
      u[i] = v[i];
      v[i] = t[i];
    }
  }
  if(u[1] < 0)
  	u[1] += a;
  return u[1];
}

int prime(int a, int b){
	while(1){
		int x = rand() % b + a;
		if (isPrime(x)){
			return x;
			break;
		}
	}
}

int rsa(char * sourceFile){
	int e, d, i;
	int p = prime(1, MAX);
	int q = prime(1, MAX);
	int n = p * q;
	int fi = (p - 1) * (q - 1);

	if ((file = fopen(sourceFile, "rb")) == NULL)
		return -1;

// определяем размер файла
	fseek(file , 0 , SEEK_END);                          
	long lSize = ftell(file);                            
	rewind(file);                                       
	 
	uint8_t * buf = (uint8_t*) malloc(sizeof(uint8_t) * lSize);
	uint64_t buf2[lSize];
	fread(buf, sizeof(uint8_t), lSize, file);
	for(i = 0; i < lSize; i++)
		buf2[i] = buf[i];
	while(1){
		e = prime(1, fi);
		if((e < fi) && (fi % e != 0))
			break;
	}
	d = euclied(fi, e);
	//encoding
	for(i = 0; i < lSize; i++){
		buf2[i] = powMod(buf2[i], e, n);
	}

	fclose(file);

	if ((file1 = fopen("codedFile_RSA", "wb")) == NULL)
		return -2;
	fwrite(buf2, sizeof(uint8_t), lSize, file1);
	fclose(file1);

	//decoding
	for(i = 0; i < lSize; i++){
		buf2[i] = powMod(buf2[i], d, n);
	}

	if ((file = fopen("decodedFile_RSA", "wb")) == NULL)
		return -3;
	fwrite(buf, sizeof(uint8_t), lSize, file);
	free(buf);
	fclose(file);
}
