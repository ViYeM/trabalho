#include "endereco.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
FILE *arqVeiculo;

// definição do tipo veiculo
#ifndef MY_HEADER_FILE6
#define MY_HEADER_FILE6

struct sVeiculo {
  char modelo[100];
  char descricao[1000];
  char cor[100];
  char placa[7];
  char valorDiaria;
  char qtOcupantes;
  bool status;
};
typedef struct sVeiculo tVeiculo;
tVeiculo cadastro [500];


  // abrir arquivo
  // ler dados do novo veiculo
  // verifica se veiculo existe(utiliza funcao pesquisaPlaca)
// Fazer uma função pra converter os dados para char antes de jogar no arquivo
  // salva dados do veiculo no documento
  // fecha arquivo
tVeiculo c[500];
int tamVet=0;

void leArquivo() {
  FILE *arqVeiculo;
  char cod[100], p1[100], p2[100];
  int ret, i = 0;

  char aux1[20];
  char aux2[20];
  arqVeiculo = fopen("veiculo.txt", "r");

  ret = fscanf(arqVeiculo, "%s %s", &p1[i], &p2[i]);
  while (ret != EOF) {

    if (strcmp("modelo", p1) == 0) {
       i = atoi(p2); /*Converte inteiro i em char*/
      strcpy(c[i].modelo, p2);
    }
    else if (strcmp("descricao", p1) == 0)
      strcpy(c[i].descricao, p2);
    else if (strcmp("cor", p1) == 0)
      strcpy(c[i].cor, p2);
    else if (strcmp("placa", p1) == 0)
      strcpy(c[i].placa, p2);
    else if (strcmp("diaria", p1) == 0)
      strcpy(c[i].valorDiaria, p2);
    else if (strcmp("ocupantes", p1) == 0)
      strcpy(c[i].qtOcupantes, p2);
    else if (strcmp("status", p1) == 0)
      strcpy(c[i].status, p2);

    else if (strcmp("veiculo", p1) == 0 && strcmp("fim", p2) == 0) {
    }
    ret = fscanf(arqVeiculo, "%s %s", &p1[i], &p2[i]);
  }
}

/*
- Incluir Veículos no cadastro
- Pesquisa o Veiculo com algum argumento
- Listar todos veículos
*/

// menu de veiculos
void menuVeiculos() {
  int opcao;
  int tamanho;

  printf("Selecione a opcao:\n");
  
  printf("Cadastro de veiculo (1)\n");
  scanf("%d", &opcao);

  printf("Pesquisar veiculo (2)\n");
  scanf("%d", &opcao);

  printf("Lista de veiculos (3)\n");
  scanf("%d", &opcao);

  if (opcao == 1) {
    // chamar funcao cadastrarVeiculo
    void cadastroVeiculo();
  }
  else if (opcao == 2) {
    // chamar funcao pesquisar veiculo
    int pesquisaVeiculo();
  }
  else if (opcao == 3) {
    // chamar funcao listaVeiculo
    void listaVeiculo();
  }

  // chamar funcao incluirCarro
}

// incluir carro
void cadastroVeiculo() 
{

  tVeiculo c;
  char cod;
  int i;

  printf("Inicio cliente\n\n");

  printf(":");
  printf("\nInforme o modelo do veiculo:");
  scanf("%s", c.modelo);

   printf("\nDescrição do veiculo:");
  scanf("%s", c.descricao);

   printf("\nCor do veiculo:");
  scanf("%s", c.cor);

   printf("\nInforme a palca do veiculo:");
  scanf("%s", c.placa);

   printf("\nInforme o valor da diaria:");
  scanf("%s", &c.valorDiaria);

   printf("\nInforme a capacidade de ocupantes do veiculo:");
  scanf("%s", &c.qtOcupantes);

   printf("\nInforme o status do veiculo:");
  scanf("%s", &c.status);
  
  printf("\n\nveiculo fim");
}
  


// funcao pesquisa placa de carro
// retorna true se for possivel encontrar placa, false caso nao exista a placa
int pesquisaPlaca(char placa[7], int tamanho)
{
tVeiculo c[500];
  int i = 0;

  printf("\nDigite a placa do veiculo que voce deseja encontrar:");
  scanf ("%s", c[i].placa);
  
   for (int i = 0; i< tamanho && strcmp(c[i].placa,"EOF") != 0; i++)
    {
      if (myStrcmp (placa, c[i].placa) == 0)
        printf ("\n%d, %s", i, c[i].placa);
          return c[i].placa;
    }
printf ("\n\n");
}



void listaVeiculo(int tamanho)
{
  tVeiculo c[500];
  int i;
  
  for (i = 0; i < tamanho && strcmp(c[i].modelo, "EOF") != 0; i++)
    {
     printf("\n%s, %s, %s",c[i].modelo, c[i].descricao, c[i].cor,     
     c[i].placa, c[i].valorDiaria, c[i].qtOcupantes, c[i].status);  
    }
    printf("\n\n");
}

void escreveArquivo(int busca) {
  int i;
  tVeiculo c[500];
  FILE *arqVeiculo;
  arqVeiculo = fopen("clientes.txt", "w");

  for (i = 0; i < busca; i++) {
    fprintf(arqVeiculo, "%s \n", c[i].modelo);
    fprintf(arqVeiculo, "%s \n", c[i].descricao);
    fprintf(arqVeiculo, "%s \n", c[i].cor);
    fprintf(arqVeiculo, "%s \n", c[i].placa);
    fprintf(arqVeiculo, "%s \n", c[i].valorDiaria);
    fprintf(arqVeiculo, "%s \n",c[i].qtOcupantes);
    fprintf(arqVeiculo, "%s \n", c[i].status);
    }
  }

#endif