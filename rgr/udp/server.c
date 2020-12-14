#include "../../libs/headers.h"

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

	setlocale(0, "rus");

	long long int  buffer, v, x, y;
	int fd;
	struct sockaddr_in client, server;
	//создание сокета
	if((fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		perror("Socket:");
		exit(1);
	}

	srand(time(NULL));
	//генерируем p q - простые числа
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
	printf("Сервер запущен\n");
#endif
	int len, e;
	len = sizeof(client);
	while(1) 
	{	
#if defined(LOGS)
		printf("Сервер ждет клиентов...\n");
#endif
		//ждем подключение клиента
		if(recvfrom(fd, &buffer, sizeof(long long int), MSG_WAITALL, (struct sockaddr*)&client, &len) == -1) 
		{
			perror("Recvfrom:");
			exit(1);
		}
#if defined(LOGS)
		printf("Клиент %lld подключен\n", buffer);
#endif
		buffer = n;

#if defined(LOGS)
		printf("Отправил n = %lld\n", buffer);
#endif
		//отправляем клиенту n
		if(sendto(fd, &buffer, sizeof(long long int), MSG_CONFIRM, (struct sockaddr*)&client, len) == -1)
		{
			perror("Sendto:");
			exit(1);
		}
		//получаем открытый ключ клиента v
		if(recvfrom(fd, &buffer, sizeof(long long int), MSG_WAITALL, (struct sockaddr*)&client, &len) == -1) 
		{
			perror("Recvfrom:");
			exit(1);
		}
		v = buffer;
#if defined(LOGS)
		printf("Получил v = %lld\n", buffer);
#endif
		//цикл по раундам аунтификации
		for (int i = 0; i < COUNT_OF_ROUNDS; i++)
		{
			//получаем от клиента х
			if(recvfrom(fd, &buffer, sizeof(long long int), MSG_WAITALL, (struct sockaddr*)&client, &len) == -1) 
			{
				perror("Recvfrom:");
				exit(1);
			}
			x = buffer;

#if defined(LOGS)
			printf("Получил x = %lld\n", buffer);
#endif
			//генерируем е [0,1]
			e = rand() % 2;
			buffer = e;

#if defined(LOGS)
			printf("Отправил e = %lld\n", buffer);
#endif
			//отправляем клиенту е
			if(sendto(fd, &buffer, sizeof(long long int), MSG_CONFIRM, (struct sockaddr*)&client, len) == -1)
			{
				perror("Sendto:");
				exit(1);
			}
			//получаем от клиента у
			if(recvfrom(fd, &buffer, sizeof(long long int), MSG_WAITALL, (struct sockaddr*)&client, &len) == -1) 
			{
				perror("Recvfrom:");
				exit(1);
			}

			y = buffer;

#if defined(LOGS)
			printf("Получил y = %lld\n", buffer);
#endif
			//проверяем равенство y^2 = x*v^e mod n; если проверка пройдена, то переходим к следующему раунду
			if(powMod(y, 2, n) == (((x % n) * powMod(v, e, n)) % n))
			{
				printf("Раунд успешно пройден\n");
				printf("\n");
			}
			//иначе прекращаем работу
			else
			{
				printf("Раунд не пройден\n");
				break;
			}
		}

	}
	return 0;
}
