#include "headers.h"

/*
 * Функция для определения, является ли число простым или нет.
 * Если число простое вернет значение true, если нет, то false 
 */

bool isPrime(int p)
{
  int b=(int)pow(p,0.5);

  if (p<=1) 
    return false;
   
  for(int i=2;i<=b;++i)
  {
    if ((p%i)==0) return false;        
  }

  return true;     
}