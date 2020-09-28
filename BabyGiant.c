#include "headers.h"


unsigned long long BabyGiant(unsigned long long a, unsigned long long y, 
	unsigned long long p){
    unsigned long long i, j, k, m, *baby, *giant;
    unsigned long long x;
    k = ceill(sqrt(p));
    m = k;
    //Baby step
    baby = (unsigned long long*)malloc((m) * sizeof(unsigned long long));
    for(j = 0; j < m; j++){
        baby[j] = (unsigned long long)(pow(a, j) * y) % p;
    }
    //Giant step
    giant = (unsigned long long*)malloc(k * sizeof(unsigned long long));
     for(i = 1; i <= k; i++){
        giant[i] = (unsigned long long)(pow(a, (i * m))) % p;
    }
    //x
    for(i = 1; i <= k; i++)
        for(j = 0; j < m; j++)
            if(giant[i] == baby[j]){
                x = i * m - j;
                break;
            }
    
    free(baby);
    free(giant);
    
    return x;
}

/*
    a = 3 y = 1 p = 7 {x == 6}

*/