#include "../libs/headers.h"

int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	rsa("test.png");
	return 0;
}