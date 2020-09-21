#include "headers.h"


int main(int argc, char *argv[])
{
  unsigned long long a,x,p,b,g,q,Xa,Xb,Ya,Yb,Zab,Zba;
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
  printf("\t# Test ExtendedEuclied\t#\n");
  a = random();
  b = random();
  printf("\t# a = %10lld\t#\n \t# b = %10lld\t#\n", a, b);
  ExtendedEuclied(a, b);
  printf("\n");
  printf("\t#########################\n");
  printf("\t# Test DiffiHellman\t#\n");
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
  //   if(modPoW(g, q, p) != 1 )
  //     break;
  // }
  p = 11;
  g = 7;
  Xa = 4;
  Xb = 7;
  printf("\t# Xa = %10lld\t#\n \t# Xb = %10lld\t#\n \t# q = %10lld\t#\n \t# p = %10lld\t#\n", Xa, Xb, q, p);
  printf("\t#########################\n");
  Ya = DiffiHellman(g, Xa, p); // Открытый ключ Алисы
  Yb = DiffiHellman(g, Xb, p); // Открытый ключ Боба
  Zab = DiffiHellman(Yb, Xa, p); // Уникальный ключ для Алисы и Боба
  Zba = DiffiHellman(Ya, Xb, p); // Уникальный ключ для Алисы и Боба
  printf("\t# Ya = %11lld\t#\n \t# Yb = %11lld\t#\n \t# Zab = %10lld\t#\n \t# Zba = %10lld\t#\n", Ya, Yb, Zab, Zba);  
  printf("\t#########################\n");                      
  return 0;
}