#include "../libs/headers.h"


uint64_t euclied(uint64_t a, uint64_t b)
{
  int i;
  if(a < b){
    i = a;
    a = b;
    b = i;
  }
  uint64_t q, u[2], v[2], t[2];
  u[0] = a;
  u[1] = 0;
  v[0] = b;
  v[1] = 1;
  while(v[0] != 0) {
    q = u[0] / v[0];
    t[0] = u[0] % v[0];
    t[1] = u[1] - q * v[1];
    for(i = 0; i < 2; i++){
      u[i] = v[i];
      v[i] = t[i];
    }
  }
  if(u[1] < 0)
  	u[1] += a;
  return u[1];
}

int main()
{
	// char file_name[20] = "test.txt";
	// char file_name1[20] = "test.txt_1";
	// char file_name2[20] = "test.txt_2";
	// char file_name3[20] = "test.txt_3";

	char file_name[20] = "1";

	srand(time(NULL));
	while (1)
	{
		//p = rand() % (255 - 200 + 1) + 200;
		p = rand() % (1000 - 500 + 1) + 500;
		//p = rand();
		if(isPrime(p))
			break;
	}
	//p = 251;
	while (1)
	{
		Ca = rand();
		if (Ca == 1)
			continue;
		Da = rand();
		if (Da == 1)
			continue;
		x = Ca*Da;
		if (powMod(x, 1, p - 1) == 1)
		{
			// printf("try Ca %d Da %d\n", Ca, Da);
			// printf("%d %d %d\n", x, p, powMod(x, 1, p - 1));
			break;
		}
		if (powMod(Ca * powMod(Da, 1, p), 1, p) == 1)
		{
			break;
		}
	}
	while (1)
	{
		Cb = rand();
		if (Cb == 1)
			continue;
		//Db = euclied(Cb, p);
		Db = rand();
		if (Db == 1)
			continue;
		x = Cb*Db;

		//printf(" x = %lld\n", x);
		// printf("try Ca %d Da %d\n", Cb, Db);
			//printf("%d %d %d\n", x, p, powMod(x, 1, p - 1));
		if (powMod(x, 1, p - 1) == 1)
			break;
		//printf("try Ca Da\n");
	}
	// Ca = 7;
	// Da = 19;
	// Cb = 5;
	// Db = 9;
	// p = 23;
	// Ca = 43;
	// Da = 49;
	// Cb = 91;
	// Db = 73;
	// p = 163;
	// Ca = 33;
	// Da = 67;
	// Cb = 67;
	// Db = 33;
	// p = 443;
	printf("%ld %ld %ld %ld %lld\n", Ca, Da, Cb, Db, p);
	Shamir(p, Ca, Da, file_name);
	// Shamir(p, Cb, Db, file_name1);
	// Shamir(p, Ca, Da, file_name2);
	// Shamir(p, Cb, Db, file_name3);


	//-------------------------

	return 0;
}