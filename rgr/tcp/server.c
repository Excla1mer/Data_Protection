#include "../../libs/headers.h"

long long int prime(int a, int b){
	while(1){
		long long int x = rand() % b + a;
		if (isPrime(x)){
			return x;
			break;
		}
	}
}

int main() {

	setlocale(0, "rus");

	long long int  buffer, v, x, y;
	int fd, fd1;
	struct sockaddr_in client, server;

	if((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Socket:");
		exit(1);
	}

	srand(time(NULL));

	long long int p = prime(1, 100000);
	long long int q = prime(1, 100000);
	long long int n = p * q;

	memset(&server, 0, sizeof(server));
	memset(&client, 0, sizeof(client));
	server.sin_family    = AF_INET;  
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	if(bind(fd, (struct sockaddr*)&server, sizeof(server)) == -1)
	{
		perror("Bind:");
		exit(1);
	}
#if defined(LOGS)
	printf("Server started\n");
#endif
	int len, e;
	len = sizeof(client);
	if ((listen(fd, 5)) == -1)
	{ 
		perror("Listen"); 
		exit(1); 
    }
	while(1) 
	{
	if ((fd1 = accept(fd, (struct sockaddr *)&client, &len)) == -1)
	{
		perror("accept");
		exit(1);
	}
#if defined(LOGS)
		printf("Waiting clients...\n");
#endif

		if (recv(fd1, &buffer, sizeof(long long int), 0) == -1) 
		{
			perror("recv:");
			exit(1);
		}
#if defined(LOGS)
		printf("Client %lld connected\n", buffer);
#endif
		buffer = n;

#if defined(LOGS)
		printf("Send n = %lld\n", buffer);
#endif

		if(send(fd1, &buffer, sizeof(long long int), 0) == -1)
		{
			perror("send:");
			exit(1);
		}

		if(recv(fd1, &buffer, sizeof(long long int), 0) == -1) 
		{
			perror("recv:");
			exit(1);
		}
		v = buffer;
#if defined(LOGS)
		printf("Got v = %lld\n", buffer);
#endif

		for (int i = 1; i <= COUNT_OF_ROUNDS; i++)
		{
			printf("Round %d\n", i);

			if(recv(fd1, &buffer, sizeof(long long int), 0) == -1) 
			{
				perror("recv:");
				exit(1);
			}
			x = buffer;

#if defined(LOGS)
			printf("Got x = %lld \n", buffer);
#endif

			e = rand() % 2;
			buffer = e;

#if defined(LOGS)
			printf("Send e = %lld\n", buffer);
#endif

			if(send(fd1, &buffer, sizeof(long long int), 0) == -1)
			{
				perror("send:");
				exit(1);
			}

			if(recv(fd1, &buffer, sizeof(long long int), 0) == -1) 
			{
				perror("recv:");
				exit(1);
			}

			y = buffer;

#if defined(LOGS)
			printf("Got y = %lld\n", buffer);
#endif

			if(powMod(y, 2, n) == (((x % n) * powMod(v, e, n)) % n))
			{
				printf("Next\n");
			}
			else
			{
				printf("Error\n");
				return -1;
			}
		}
		printf("Success!!!\n\n");

	}
	return 0;
}
