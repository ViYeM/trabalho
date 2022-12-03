#include <string.h> 
#include<stdbool.h>
//definição do tipo endereço, utilizado no cliente.
//Assinatura endereco: (char rua)(char bairro)(char numero)(char complemento)(char Cep)(char estado)(charCidade)
#ifndef MY_HEADER_FILE3
#define MY_HEADER_FILE3

struct sEndereco{
char rua[100];
char bairro[100];
char numero;
char complemento[100];
char cep;
char estado[100];
char cidade[100];
};

typedef struct sEndereco tEndereco;
#endif