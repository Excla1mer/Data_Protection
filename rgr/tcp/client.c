#include "../../libs/headers.h"

int main(int argc, char *argv[]) {

    setlocale(0, "rus");

	int fd;
	long long int buffer, s, n, r, x, e;
	int len;
	buffer = atoll(argv[1]);
	struct sockaddr_in server;
    srand(time(NULL));

    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
            perror("Socket:");
            exit(1);
    }

	memset(&server, 0, sizeof(server));
    server.sin_family    = AF_INET;  
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
	len = sizeof(server);

    if(connect(fd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        perror("connect");
        exit(1);
    }

   	if (send(fd, &buffer, sizeof(long long int), 0) == -1)
    {
        perror("send:");
        exit(1);
    }
#if defined(LOGS)
    printf("Connected to server\n");
    printf("Waiting msg fron server...\n\n");
#endif
	if(recv(fd, &buffer, sizeof(long long int), 0) == -1) 
    {
        perror("recv:");
        exit(1);
    }
    n = buffer;

#if defined(LOGS)
    printf("Got n = %lld\n", buffer);
#endif

    while(1)
    {

        s = rand() % (n - 1) + 1;
        if(ExtendedEuclied(s, n) == 1)
            break;
    }

    long long int v = powMod(s, 2, n);
    buffer = v;

    if (send(fd, &buffer, sizeof(long long int), 0) == -1) 
    {
        perror("send:");
        exit(1);
    }
#if defined(LOGS)
    printf("Send v = %lld to server\n", buffer);
#endif

    for (int i = 1; i <= COUNT_OF_ROUNDS; i++)
    {
        printf("Round %d\n", i);
        r = rand() % (n - 1) + 1;
        x = powMod(r, 2, n);

        buffer = x;

        if (send(fd, &buffer, sizeof(long long int), 0) == -1) 
        {
            perror("send:");
            exit(1);
        }
#if defined(LOGS)
        printf("Send x = %lld to server\n", buffer);
#endif

        if(recv(fd, &buffer, sizeof(long long int), 0) == -1) 
        {
            perror("recv:");
            exit(1);
        }
        e = buffer;
#if defined(LOGS)
        printf("Got e = %lld from server\n", buffer);
#endif
        y = ((r % n) * powMod(s, e, n)) % n;
        buffer = y;

        if (send(fd, &buffer, sizeof(long long int), 0) == -1) 
        {
            perror("send:");
            exit(1);
        }
#if defined(LOGS)
        printf("Send y = %lld to server\n", buffer);
        printf("\n");
#endif

    }
    
}