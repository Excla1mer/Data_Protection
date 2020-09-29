#include "headers.h"


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
  /*
   * Бесконечный цикл для рандома q и p таких, что они простые и p = 2*q+1
   */
  // while(1)
  // {
  //   q = random(); // q 
  //   if(isPrime(q))
  //   {
  //     p = 2 * q + 1;
  //     if(isPrime(p))
  //       break;
  //   }
  // }
  // Xa = random(); // private key Алисы
  // Xb = random(); // private key Боба
  // /* Бесконечный цикл для подбора g такого, что g^q mod p != 1 */
  // while(1)
  // {
  //   g = random();
  //   if(powMod(g, q, p) != 1 )
  //     break;
  // }
  // /*p = 11;
  // g = 7;
  // Xa = 4;
  // Xb = 7;*/
  // printf("\t# Xa = %10lld\t#\n \t# Xb = %10lld\t#\n \t# q  = %10lld\t#\n \t# p  = %10lld\t#\n", Xa, Xb, q, p);
  // printf("\t#########################\n");
  // Ya = DiffiHellman(g, Xa, p); // Открытый ключ Алисы
  // Yb = DiffiHellman(g, Xb, p); // Открытый ключ Боба
  // Zab = DiffiHellman(Yb, Xa, p); // Уникальный ключ для Алисы и Боба
  // Zba = DiffiHellman(Ya, Xb, p); // Уникальный ключ для Алисы и Боба
  // printf("\t# Ya  = %11lld\t#\n \t# Yb  = %11lld\t#\n \t# Zab = %10lld\t#\n \t# Zba = %10lld\t#\n", Ya, Yb, Zab, Zba);  
  // printf("\t#########################\n"); 
  // printf("\n");
  printf("\t#########################\n");
  printf("\t# \tBabyGiant\t#\n");
  a = 3;
  y = 1;
  p = 7;
  printf("\t# a = %10lld\t#\n \t# y = %10lld\t#\n \t# p = %10lld\t#\n", a, y, p);
  printf("\t#########################\n");
  printf("\t# Result = %10lld\t#\n", BabyGiant(a, y, p));
  printf("\t#########################\n");
  return 0;
}