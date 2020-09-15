#include "headers.h"

unsigned long long powMod(unsigned long long a, unsigned long long x, 
													unsigned long long p)
{
	unsigned long long result = 1;
	int iter = 0;
	while(x)
	{
		//printf("[%d] a  = %lld x = %lld p = %lld\n", iter, a, (x&1), p);
		result = (x&1) ? (result * a) % p : result;
		//printf("[%d] result = %lld\n", result);
		x = x >> 1;	
		a = (a * a) % p;
		//iter++;
	}
	return result;
}