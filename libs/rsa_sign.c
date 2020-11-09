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

int rsa_sign(char * sourceFile){
  int c, d, i;
  int p = prime(1, MAX);
  int q = prime(1, MAX);
  int n = p * q;
  int fi = (p - 1) * (q - 1);
  uint8_t hash_key[16], w[16];
  uint64_t s[16];

  if ((file = fopen(sourceFile, "rb")) == NULL)
    return -1;

// определяем размер файла
  fseek(file , 0 , SEEK_END);                          
  long lSize = ftell(file);                            
  rewind(file);                                       
   
  uint8_t * buf = (uint8_t*) malloc(sizeof(uint8_t) * lSize);
  fread(buf, sizeof(uint8_t), lSize, file);

  md5(buf, lSize, hash_key);
  printf("\nhash key: ");
  for(i = 0; i < 16; i++)
    printf("%x", hash_key[i]);

  printf("\n");

  while(1){
    d = prime(1, fi);
    if((d < fi) && (fi % d != 0))
      break;
  }
  c = euclied(fi, d);
  //encoding
  for(i = 0; i < 16; i++){
    s[i] = powMod(hash_key[i], c, n);
  }

  fclose(file);

  if ((file1 = fopen("rsa_sign", "wb")) == NULL)
    return -1;
  fwrite(s, sizeof(uint64_t), 16, file1);
  fclose(file1);

  free(buf);
  //decoding
  for(i = 0; i < 16; i++){
    w[i] = powMod(s[i], d, n);
    if(w[i] != hash_key[i]){
      return -2;
    }
  }
  return 0;
}