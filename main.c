#include "headers.h"

#define a 1
#define x 2 
#define p 3

int main(int argc, char *argv[])
{
  printf("\tTest powMod a = 5 x = 7 p = 7\n");
  printf("%lld\n", powMod(5, 7, 7));
  printf("\tTest ExtendedEuclied a = 15  b = 60\n");
  ExtendedEuclied(15, 60);

  return 0;
}