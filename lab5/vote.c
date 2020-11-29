#include "../libs/headers.h"

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

int vote(){

	int p = prime(1, 10000);
	int q = prime(1, 10000);
	int n = p * q;
	int fi = (p - 1) * (q - 1);
	int d;

	while(1){
		d = prime(1, fi);
		if((d < fi) && (ExtendedEuclied(d, fi) == 1))
			break;
	}
	int c = euclied(fi, d);
	int dis;
	uint8_t buf[1];
	while(1){
		printf("Выберите один из вариантов:\n1. Да\t2. Нет\t3. Воздержался\n");
		scanf("%d", &dis);
		printf("-----------------\n");
		switch(dis){
			case 1:
				printf("Ваш выбор: Да\n");
				buf[0] = 1;
				break;
			case 2:
				printf("Ваш выбор: Нет\n");
				buf[0] = 2;
				break;
			case 3:
				printf("Ваш выбор: Воздержался\n");
				buf[0] = 3;
				break;
			default:
				printf("Такого варианта нет. Попробуйте снова\n");
				break;
		}
		if(dis >= 1 && dis <= 3)
			break;
	}

	uint8_t hash_key[16], w[16];

	int i;
	md5(buf, 1, hash_key);
  	printf("hash key:\t");
 	for(i = 0; i < 16; i++)
    	printf("%x", hash_key[i]);

    int rX, r;
    while(1){
    	r = prime(2, n);
    	if(ExtendedEuclied(n, r) == 1)
    		break;
    }
    rX = euclied(r, n);

    uint64_t h[16];

    for(i = 0; i < 16; i++)
    	h[i] = ((hash_key[i] % n) * powMod(r, d, n)) % n;

    printf("\n");

    uint64_t sX[16], s[16];
    for(i = 0; i < 16; i++){
    	sX[i] = powMod(h[i], c, n);
  }

  	for(i = 0; i < 16; i++){
    	s[i] = ((sX[i] % n) * (rX % n)) % n;
  }

  for(i = 0; i < 16; i++){
    w[i] = powMod(s[i], d, n);
    if(w[i] != hash_key[i]){
      return -1;
    }
  }
  printf("decoded hash:\t");
   	for(i = 0; i < 16; i++)
    	printf("%x", w[i]);

    printf("\n");

  return 0;

}

int main(){
	setlocale(0, "rus");
	int i = vote();
	switch(i){
		case -1:
			printf("ключи не совпадают\n");
			break;
		case 0:
			printf("ключи совпали\n");
			break;
	}

	return 0;
}