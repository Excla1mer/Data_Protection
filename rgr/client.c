#include "../libs/headers.h"

#define PORT 8080

int main(int argc, char *argv[]) {
	int fd;
	long long int buffer, s, n, r, x, e;
	int len;
	buffer = 1;
	struct sockaddr_in server;
    srand(time(NULL));
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
    printf("Connected to server\n");
    printf("Waiting msg from server...\n");
#endif
	if(recvfrom(fd, &buffer, sizeof(long long int), MSG_WAITALL, (struct sockaddr*)&server, &len) == -1) 
    {
        perror("Recvfrom:");
        exit(1);
    }
    n = buffer;

#if defined(LOGS)
    printf("Got n = %lld from server\n", buffer);
#endif

    while(1)
    {
        s = rand() % (n - 1) + 1;
        if(ExtendedEuclied(s, n) == 1)
            break;
    }

    long long int v = powMod(s, 2, n);
    buffer = v;

    if (sendto(fd, &buffer, sizeof(long long int), MSG_CONFIRM, (struct sockaddr*)&server, len) == -1) 
    {
        perror("Sendto:");
        exit(1);
    }
#if defined(LOGS)
    printf("Send v = %lld to server\n", buffer);
#endif
    for (int i = 0; i < COUNT_OF_ROUNDS; i++)
    {
        r = rand() % (n - 1) + 1;
        x = powMod(r, 2, n);

        buffer = x;
        if (sendto(fd, &buffer, sizeof(long long int), MSG_CONFIRM, (struct sockaddr*)&server, len) == -1) 
        {
            perror("Sendto:");
            exit(1);
        }
#if defined(LOGS)
        printf("Send x = %lld to server\n", buffer);
#endif
        if(recvfrom(fd, &buffer, sizeof(long long int), MSG_WAITALL, (struct sockaddr*)&server, &len) == -1) 
        {
            perror("Recvfrom:");
            exit(1);
        }
        e = buffer;
#if defined(LOGS)
        printf("Got e = %lld from server\n", buffer);
#endif
        y = ((r % n) * powMod(s, e, n)) % n;
        buffer = y;

        if (sendto(fd, &buffer, sizeof(long long int), MSG_CONFIRM, (struct sockaddr*)&server, len) == -1) 
        {
            perror("Sendto:");
            exit(1);
        }
#if defined(LOGS)
        printf("Send y = %lld to server\n", buffer);
#endif

    }
    
}