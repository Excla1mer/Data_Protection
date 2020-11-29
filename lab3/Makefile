all: ElGamal.o rsa.o gost.o

ElGamal.o: ElGamal.c
		gcc ElGamal.c -o ElGamal_result -L../libs/ -lmy_lib -lm -g

rsa.o: rsa.c
		gcc rsa.c -o rsa_result -L../libs/ -lmy_lib -lm -g

gost.o: gost.c
		gcc gost.c -o gost_result -L../libs/ -lmy_lib -lm -g

clean: 
		rm -rf *result