#include "headers.h"


unsigned long long ExtendedEuclied(unsigned long long a, unsigned long long b)
{
  unsigned long long i;
  if(a < b){
    i = a;
    a = b;
    b = i;
  }
  long long q, u[3], v[3], t[3];
  u[0] = a;
  u[1] = 1;
  u[2] = 0;
  v[0] = b;
  v[1] = 0;
  v[2] = 1;
  while(v[0] != 0) {
    q = u[0] / v[0];
    t[0] = u[0] % v[0];
    t[1] = u[1] - q * v[1];
    t[2] = u[2] - q * v[2];
    for(i = 0; i < 3; i++){
      u[i] = v[i];
      v[i] = t[i];
    }
  }
  return u[0];
}