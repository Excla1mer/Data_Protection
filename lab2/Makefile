
all: Shamir.o ElGamal.o vernam.o rsa.o

Shamir.o: Shamir.c
		gcc Shamir.c -o Shamir_result -L../libs/ -lmy_lib -lm

vernam.o: vernam.c
		gcc vernam.c -o vernam_result -L../libs/ -lmy_lib -lm

rsa.o: rsa.c
		gcc rsa.c -o rsa_result -L../libs/ -lmy_lib -lm

ElGamal.o: ElGamal.c
		gcc ElGamal.c -o ElGamal_result -L../libs/ -lmy_lib -lm


