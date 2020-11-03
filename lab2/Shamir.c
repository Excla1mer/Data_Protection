#include "../libs/headers.h"

int main()
{
	// char file_name[20] = "test.txt";
	// char file_name1[20] = "test.txt_1";
	// char file_name2[20] = "test.txt_2";
	// char file_name3[20] = "test.txt_3";
	// char file_name[20] = "2.jpg";
	// char file_name1[20] = "2.jpg_1";
	// char file_name2[20] = "2.jpg_2";
	// char file_name3[20] = "2.jpg_3";

	char file_name[20] = "1";

	srand(time(NULL));
	while (1)
	{
		//p = rand() % (255 - 200 + 1) + 200;
		p = rand() % (1000 - 500 + 1) + 500;
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
		
	}
	while (1)
	{
		Cb = rand();
		if (Cb == 1)
			continue;
		Db = rand();
		if (Db == 1)
			continue;
		x = Cb*Db;
		//printf("try Ca %d Da %d\n", Cb, Db);
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