#include "../libs/headers.h"

int main(int argc, char **argv){
  char *file_name = argv[1];

  if (file_name == NULL){
	perror("Enter file_name");
	return -1;
  }

	int i = rsa_sign(file_name);
	switch(i){
		case 0: 
			printf("success\n");
			break;
		case -1:
			printf("file reading error\n");
			break;
		case -2:
		    printf("RSA sign undone\n");
		    break;
		default:
			printf("unknown error\n");
	}

	return 0;
}