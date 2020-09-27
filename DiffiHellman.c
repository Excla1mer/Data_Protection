#include "headers.h"


/*unsigned long long DiffiHellman(unsigned long long a, unsigned long long b,
                unsigned long long p)
{
  unsigned long long result;
  result = powMod(a, b, p);
  return result;
}*/

unsigned long long DiffiHellman()
{
  /*
   * Бесконечный цикл для рандома q и p таких, что они простые и p = 2*q+1
   */
  while(1)
  {
    q = random(); // q 
    if(isPrime(q))
    {
      p = 2 * q + 1;
      if(isPrime(p))
        break;
    }
  }
  Xa = random(); // private key Алисы
  Xb = random(); // private key Боба
  /* Бесконечный цикл для подбора g такого, что g^q mod p != 1 */
  while(1)
  {
    g = random();
    if(powMod(g, q, p) != 1 )
      break;
  }
  printf("\t# Xa = %10lld\t#\n \t# Xb = %10lld\t#\n \t# q  = %10lld\t#\n \t# p  = %10lld\t#\n", Xa, Xb, q, p);
  printf("\t#########################\n");
  Ya = powMod(g, Xa, p); // Открытый ключ Алисы
  Yb = powMod(g, Xb, p); // Открытый ключ Боба
  Zab = powMod(Yb, Xa, p); // Уникальный ключ для Алисы и Боба
  Zba = powMod(Ya, Xb, p); // Уникальный ключ для Алисы и Боба
  printf("\t# Ya  = %11lld\t#\n \t# Yb  = %11lld\t#\n \t# Zab = %10lld\t#\n \t# Zba = %10lld\t#\n", Ya, Yb, Zab, Zba);  
  printf("\t#########################\n"); 
  printf("\n");
}
