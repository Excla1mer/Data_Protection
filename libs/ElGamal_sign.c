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

uint64_t neg_mod(long int a, uint64_t p)
{
	uint64_t tmp = abs(a);
	uint64_t dev = 0;
	if (tmp < p)
	{
		dev = p - tmp;
		return dev;
	}
	else
	{
		int i = 1;
		while(dev < tmp)
		{
			dev = i * p;
			i++;
		}
		return dev - tmp;
	}
}

int ElGamal_sign(uint8_t hash_key[16], uint64_t p, uint64_t x, uint64_t g, uint64_t s[16])
{
	uint64_t u, k1;

	k = random() % p - 1; // q
	k = euclied(k, p - 1) ;

	
	r = powMod(g, k, p);
	printf("r = %ld \n", k);
	k1 = euclied(k, (p-1));
	char *str = (char *)malloc(sizeof(char) * 255);
	for(int i = 0; i < 16; i++)
	{
		if ((int)(hash_key[i] - r * x) < 0)
		{
			long int l = (int)(hash_key[i] - r * x);
			u = neg_mod(l, p-1);
		}
		else
		{
			u = (int)(hash_key[i] - r * x) % (p - 1);
		}
		
		s[i] = powMod((k1*u), 1, p - 1);
	}

	return 0;
}