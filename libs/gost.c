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

uint64_t neg_mod(long int a, uint64_t p){
  uint64_t tmp = abs(a);
  uint64_t dev = 0;
  if (tmp < p){
    dev = p - tmp;
    return dev;
  }
  else{
    int i = 1;
    while(dev < tmp){
      dev = i * p;
      i++;
    }
  return dev - tmp;
  }
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

int gost(uint64_t q, char * sourceFile){
  int i; 
  long int sum = 0;

  if ((file = fopen(sourceFile, "rb")) == NULL)
    return -1;

   // определяем размер файла
  fseek(file , 0 , SEEK_END);                          
  long lSize = ftell(file);                            
  rewind(file);                                       
  
  uint8_t * buf = (uint8_t*) malloc(sizeof(uint8_t) * lSize);
  fread(buf, sizeof(uint8_t), lSize, file);
  fclose(file);

  uint8_t hash_key[16];
  md5(buf, lSize, hash_key);
  
  for(i = 0; i < 16; i++)
    sum += hash_key[i];
  //printf("hash sum = %ld\n", sum);

  printf("\nhash key: ");
  for(i = 0; i < 16; i++)
    printf("%x", hash_key[i]);
  printf("\n");

  q = prime(1, MAX * MAX);

  uint64_t p = (rand() % MAX) * q + 1;
  while(!isPrime(p)){
    p = rand() % MAX * q + 1;
  }
  printf("p = %lu\n", p);

  uint64_t a;
  while(1){
    a = powMod((rand() + 1), ((p - 1) / q), p);
    if(a > 1)
      break;
  }
  printf("a = %lu\n", a);

  uint64_t x = rand() % (q - 1) + 1;
  printf("x = %lu\n", x);

  uint64_t y = powMod(a, x, p);
  printf("y = %lu\n", y);

  uint64_t k, s;
  long int r;
  while(1){
    k = rand() % (q + 1) + 1;
    r = powMod(a, k, p) % q;
    s = (k * sum + x * r) % q;
    if(r != 0 && s != 0)
      break;
  }
  printf("k = %lu\n", k);

  if ((file1 = fopen("gost_sign", "wb")) == NULL)
    return -1;
  printf("r = %ld\n", r);
  printf("s = %lu\n", s);
  fwrite(&r, sizeof(uint64_t), 1, file1);
  fwrite(&s, sizeof(uint64_t), 1, file1);

  fclose(file1);

  long int u1, u2;
  u1 = ((s % q) * euclied(sum, q)) % q;
  u2 = (neg_mod(-r, q) * euclied(sum, q)) % q;

  long int v;
  v = ((powMod(a, u1, p) * powMod(y, u2, p)) % p) % q;
  printf("v = %ld\n", v);

    if(v != r)
      return -2;

  return 0;
}