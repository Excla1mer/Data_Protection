#include "../libs/headers.h"

int main()
{
	char file_name[15] = "test.txt";
	//char file_name[15] = "1";
	srand(time(NULL));
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
  /* Бесконечный цикл для подбора g такого, что g^q mod p != 1 */
	while(1)
  	{
    	g = random();
    	if(powMod(g, q, p) != 1 )
      	break;
  	}

  	// p = 23;
  	// g = 5;
  	Ca = rand();
  	Da = powMod(g, Ca, p);

  	Cb = rand();
  	//Cb = 13;
  	Db = powMod(g, Cb, p);

  	printf("%ld %ld %ld %ld \n", Cb, Db, p, g);
  	ElGamal(file_name, Cb, Db);

	return 0;
}