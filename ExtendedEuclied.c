#include "headers.h"


int ExtendedEuclied(int a, int b){
  int i;
  if(a < b){
    i = a;
    a = b;
    b = i;
  }
  int q, u[3], v[3], t[3];
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
  for(i = 0; i < 3; i++)
    printf("%d ", u[i]);
}