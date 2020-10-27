#include "headers.h"

/* Функция быстрого возведения [a] в степень [х] по модулю [p] 
 * pow(a, x) % p;
 */

unsigned long long powMod(unsigned long long a, unsigned long long x, 
                          unsigned long long p)
{
  unsigned long long result = 1;
  int iter = 0;
  while(x)
  {
    result = (x&1) ? (result * a) % p : result;
    x = x >> 1; 
    a = (a * a) % p;
  }
  return result;
}