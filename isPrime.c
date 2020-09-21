#include "headers.h"

/*
 * Функция для определения, является ли число простым или нет.
 * Если число простое вернет значение true, если нет, то false 
 */

int isPrime(long long p)
{
  long long b = pow(p, 0.5);

  if (p<=1) 
    return 0;
   
  for(long long i=2;i<=b;++i)
  {
    if ((p%i)==0) return 0;        
  }

  return 1;     
}
