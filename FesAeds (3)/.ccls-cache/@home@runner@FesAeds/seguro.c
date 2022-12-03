#include <string.h> 
#include<stdbool.h>
//definição do tipo de seguro, utilizado na locação
#ifndef MY_HEADER_FILE5
#define MY_HEADER_FILE5

struct sSeguro{
char nomeSeguro[100];
char descricaoSeguro[1000];
int valorSeguro;
int idSeguro;
};
typedef struct sSeguro tSeguro;
#endif
