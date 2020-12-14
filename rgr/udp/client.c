#include "../../libs/headers.h"

#define PORT 8080

int main(int argc, char *argv[]) {

    setlocale(0, "rus");

	int fd;
	long long int buffer, s, n, r, x, e;
	int len;
	buffer = 1;
	struct sockaddr_in server;
    srand(time(NULL));
    //создание сокета
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
            perror("Socket:");
            exit(1);
    }

	memset(&server, 0, sizeof(server));
    server.sin_family    = AF_INET;  
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
	len = sizeof(server);

   	if (sendto(fd, &buffer, sizeof(long long int), MSG_CONFIRM, (struct sockaddr*)&server, len) == -1)
    {
        perror("Sendto:");
        exit(1);
    }
#if defined(LOGS)
    printf("Связь с сервером установлена\n");
    printf("Ожидание сообщений от сервера...\n");
#endif
    //получаем от сервера n
	if(recvfrom(fd, &buffer, sizeof(long long int), MSG_WAITALL, (struct sockaddr*)&server, &len) == -1) 
    {
        perror("Recvfrom:");
        exit(1);
    }
    n = buffer;

#if defined(LOGS)
    printf("Принял n = %lld\n", buffer);
#endif

    while(1)
    {
        //вычислыем s [1, n-1], взаимнопростое с n
        s = rand() % (n - 1) + 1;
        if(ExtendedEuclied(s, n) == 1)
            break;
    }
    //вычисляем v = s^2 mod n
    long long int v = powMod(s, 2, n);
    buffer = v;
    //отправляем v серверу
    if (sendto(fd, &buffer, sizeof(long long int), MSG_CONFIRM, (struct sockaddr*)&server, len) == -1) 
    {
        perror("Sendto:");
        exit(1);
    }
#if defined(LOGS)
    printf("Отправил v = %lld\n", buffer);
#endif
    //цикл по раундам аунтификации
    for (int i = 0; i < COUNT_OF_ROUNDS; i++)
    {
        //генерируем r [1, n - 1]
        r = rand() % (n - 1) + 1;
        //вычисляем х = r^2 mod n
        x = powMod(r, 2, n);

        buffer = x;
        //отправляем х серверу
        if (sendto(fd, &buffer, sizeof(long long int), MSG_CONFIRM, (struct sockaddr*)&server, len) == -1) 
        {
            perror("Sendto:");
            exit(1);
        }
#if defined(LOGS)
        printf("Отправил x = %lld\n", buffer);
#endif
        //получаем от сервера е
        if(recvfrom(fd, &buffer, sizeof(long long int), MSG_WAITALL, (struct sockaddr*)&server, &len) == -1) 
        {
            perror("Recvfrom:");
            exit(1);
        }
        e = buffer;
#if defined(LOGS)
        printf("Принял e = %lld\n", buffer);
#endif
        //вычисляем у = r * s^e mod n и отправляем его на сервер для проверки
        y = ((r % n) * powMod(s, e, n)) % n;
        buffer = y;

        if (sendto(fd, &buffer, sizeof(long long int), MSG_CONFIRM, (struct sockaddr*)&server, len) == -1) 
        {
            perror("Sendto:");
            exit(1);
        }
#if defined(LOGS)
        printf("Отправил y = %lld\n", buffer);
        printf("\n");
#endif

    }
    
}