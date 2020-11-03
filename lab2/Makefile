
all: main.o vernam.o rsa.o

main.o: main.c
		gcc main.c -o result -L../libs/ -lmy_lib -lm
vernam.o: vernam.c
		gcc vernam.c -o vernam_result -L../libs/ -lmy_lib -lm
rsa.o: rsa.c
		gcc rsa.c -o rsa_result -L../libs/ -lmy_lib -lm

