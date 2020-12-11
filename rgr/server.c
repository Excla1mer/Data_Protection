#include "../libs/headers.h"

#define PORT 8080

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


	long long int  buffer, v, x, y;
	int fd;
	struct sockaddr_in client, server;

	if((fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		perror("Socket:");
		exit(1);
	}

	srand(time(NULL));
	long long int p = prime(1, 20);
	long long int q = prime(1, 20);
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
	printf("Start server\n");
#endif
	int len, e;
	len = sizeof(client);
	while(1) 
	{	
#if defined(LOGS)
		printf("Waiting clients...\n");
#endif
		if(recvfrom(fd, &buffer, sizeof(long long int), MSG_WAITALL, (struct sockaddr*)&client, &len) == -1) 
		{
			perror("Recvfrom:");
			exit(1);
		}
#if defined(LOGS)
		printf("Client %lld connected\n", buffer);
#endif
		buffer = n;

#if defined(LOGS)
		printf("Send n = %lld to client\n", buffer);
#endif
		if(sendto(fd, &buffer, sizeof(long long int), MSG_CONFIRM, (struct sockaddr*)&client, len) == -1)
		{
			perror("Sendto:");
			exit(1);
		}

		if(recvfrom(fd, &buffer, sizeof(long long int), MSG_WAITALL, (struct sockaddr*)&client, &len) == -1) 
		{
			perror("Recvfrom:");
			exit(1);
		}
		v = buffer;
#if defined(LOGS)
		printf("Got v = %lld from client\n", buffer);
#endif

		for (int i = 0; i < COUNT_OF_ROUNDS; i++)
		{
			if(recvfrom(fd, &buffer, sizeof(long long int), MSG_WAITALL, (struct sockaddr*)&client, &len) == -1) 
			{
				perror("Recvfrom:");
				exit(1);
			}
			x = buffer;

#if defined(LOGS)
			printf("Got x = %lld from client\n", buffer);
#endif

			e = rand() % 2;
			buffer = e;

#if defined(LOGS)
			printf("Send e = %lld to client\n", buffer);
#endif
			if(sendto(fd, &buffer, sizeof(long long int), MSG_CONFIRM, (struct sockaddr*)&client, len) == -1)
			{
				perror("Sendto:");
				exit(1);
			}

			if(recvfrom(fd, &buffer, sizeof(long long int), MSG_WAITALL, (struct sockaddr*)&client, &len) == -1) 
			{
				perror("Recvfrom:");
				exit(1);
			}

			y = buffer;

#if defined(LOGS)
			printf("Got y = %lld from client\n", buffer);
#endif
			if(powMod(y, 2, n) == (((x % n) * powMod(v, e, n)) % n))
			{
				printf("Round success\n");
			}
			else
			{
				printf("bad\n");
				break;
			}
		}

	}
	return 0;
}
