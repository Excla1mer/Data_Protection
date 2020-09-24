#include "headers.h"


unsigned long long DiffiHellman(unsigned long long a, unsigned long long b,
								unsigned long long p)
{
	unsigned long long result;
	result = powMod(a, b, p);
	return result;
}
