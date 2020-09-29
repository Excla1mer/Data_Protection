#include "headers.h"
/* Test commit */

int main(int argc, char *argv[])
{
  srand(time(NULL));
  a = random();
  x = random();
  p = random();
  printf("\t#########################\n");
  printf("\t#\tTest powMod\t#\n");
  printf("\t# a = %10lld\t#\n \t# x = %10lld\t#\n \t# p = %10lld\t#\n", a, x, p);
  printf("\t#########################\n");
  printf("\t# Result = %lld\t#\n", powMod(a, x, p));
  printf("\t#########################\n");
  printf("\n");
  printf("\t#########################\n");
  printf("\t# Test ExtendedEuclied\t#\n");
  a = random();
  b = random();
  printf("\t# a = %10lld\t#\n \t# b = %10lld\t#\n", a, b);
  printf("\t#########################\n");
  printf("\t# NOD = %10lld\t#\n", ExtendedEuclied(a, b));
  printf("\t#########################\n");
  printf("\n");
  printf("\t#########################\n");
  printf("\t# Test DiffiHellman\t#\n");
  DiffiHellman();
  printf("\t#########################\n");
  printf("\t# \tBabyGiant\t#\n");
  
  while (1)
  {
    a = random();
    y = random();
    p = random();
    if ( y < p )
      break;
  }
{
  //a = 3 y = 1 p = 7 {x == 6}
  //a = 88 y = 47 p = 107 {x == 62}
  //a = 2 y = 45 p = 61 {x == 34}
  /*
  a = 88;
  y = 47;
  p = 107;
  */
}
  printf("\t# a = %10lld\t#\n \t# y = %10lld\t#\n \t# p = %10lld\t#\n", a, y, p);
  printf("\t#########################\n");
  printf("\t# Result = %10lld\t#\n", BabyGiant(a, y, p));
  printf("\t#########################\n");
  return 0;
}