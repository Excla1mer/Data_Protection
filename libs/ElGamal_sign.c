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

int ElGamal_sign(uint8_t hash_key[16], uint64_t p, uint64_t x, uint64_t g)
{
	uint64_t u, k1;
	uint64_t s[16];
	// while (1)
	// {
	// 	k = random(); // q 
	// 	if (isPrime(k))
	// 	{
	// 		if (k < (p - 1))
	// 			break;
	// 	}
	// }
	k = 5;
	hash_key[0] = 3;
	r = powMod(g, k, p);
	k1 = euclied(k, (p-1));
	for(int i = 0; i < 16; i++)
	{
		u = (int)(hash_key[i] - r * x) % (p - 1);
		s[i] = powMod((k1*u), 1, p - 1);
	}

	return s[0];
}