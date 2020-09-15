#include "headers.h"

#define a 1
#define x 2 
#define p 3

int main(int argc, char *argv[])
{
  printf("%lld\n", powMod(atoll(argv[1]), atoll(argv[2]), atoll(argv[3])));
  return 0;
}