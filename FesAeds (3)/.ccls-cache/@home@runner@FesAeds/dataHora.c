#include <string.h> 
#include<stdbool.h>
//definição do tipo dataHora, utilizado na locação.
#ifndef MY_HEADER_FILE2
#define MY_HEADER_FILE2


struct sDataHora{
int dia;
int mes;
int ano;
int hora;
int minutos;
};

typedef struct sDataHora tDataHora;


#endif