#include "endereco.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
FILE *arqCliente;


// Assinatura do arquivo: (Char CodigoCLiente) (Char NomeCamelCase) (Char Telefone) (Char CNH) (tEndedereco endereco) definição do tipo cliente

#ifndef MY_HEADER_FILE
#define MY_HEADER_FILE

struct sCliente {
  char codigo[100];
  char nome[50];
  char telefone[15];
  char cnh[15];
  tEndereco endereco;
  char fim[5];
};
typedef struct sCliente tCliente;
#endif
tCliente cadastro[500];


//-------------------------leitura de arquivo------------------------------
void leArquivo() {
  FILE *arqCliente;
  tCliente c[500];
  char cod[100], p1[100], p2[100];
  int ret, i = 0;

  char aux1[20];
  char aux2[20];
  arqCliente = fopen("clientes.txt", "r");

  ret = fscanf(arqCliente, "%s %s", &p1[i], &p2[i]);
  while (ret != EOF) {

    if (strcmp("codigo", p1) == 0) {
       i = atoi(p2); /*Converte inteiro i em char*/
      strcpy(c[i].codigo, p2);
    }

    else if (strcmp("nome", p1) == 0)
      strcpy(c[i].nome, p2);
    else if (strcmp("telefone", p1) == 0)
      strcpy(c[i].telefone, p2);
    else if (strcmp("rua", p1) == 0)
      strcpy(c[i].endereco.rua, p2);
    else if (strcmp("bairro", p1) == 0)
      strcpy(c[i].endereco.bairro, p2);
    else if (strcmp("numero", p1) == 0)
      strcpy(c[i].endereco.numero, p2);
    else if (strcmp("complemento", p1) == 0)
      strcpy(c[i].endereco.cep, p2);
    else if (strcmp("estado", p1) == 0)
      strcpy(c[i].endereco.estado, p2);
    else if (strcmp("cidade", p1) == 0)
      strcpy(c[i].endereco.cidade, p2);

    else if (strcmp("cliente", p1) == 0 && strcmp("fim", p2) == 0) {
    }
    ret = fscanf(arqCliente, "%s %s", &p1[i], &p2[i]);
  }
}


/*
- Incluir Cliente no cadastro
- pesquisa o Cliente com algum argumento
- Lista quantidade de pontos fidelidade
Listar todos os cliente
*/

// menu de cliente
void menuCliente() {

  int opcao;
  int tamanho;

  printf("Selecione a opcao:\n");
  printf("cadastra cliente (1)\n");
  scanf ("%d", &opcao);
  
  printf("Pesquisar cliente (2)\n");
  scanf ("%d", &opcao);
  
  printf("Lista de clientes (4)\n");
  scanf ("%d", &opcao);
  
  if (opcao == 1) {
    // chamar funcao cadastroCliente
    void cadastroCliente();
    
  } else if (opcao == 2) {
    // chamar funcao pesquisaCliente
    int pesquisaCliente();
  } 
  else if (opcao == 3) {
    // chamar funcao listarCliente
    void listarCliente(int tamanho);
  }
}




//-------------------------Cadastro de cliente
//(INCLUI)------------------------------ cadastro de cliente e salvamento no
// arquivo clientes.txt
void cadastroCliente() {
  tCliente c;
  char cod;
  int i;

  printf("Inicio cliente\n\n");

  printf(":");
  printf("\nDigite seu nome completo:");
  scanf("%s", c.nome);

  printf("\nInforme seu numero de telefone:");
  scanf("%s", c.telefone);

  //------inicio endereços
  printf("\nInforme sua rua:");
  scanf("%s", c.endereco.rua);

  printf("\nBairro:");
  scanf("%s", c.endereco.bairro);

  printf("\nNumero de sua residencia:");
  scanf("%s", c.endereco.numero);

  printf("\nComplemento:");
  scanf("%s", c.endereco.complemento);

  printf("\nCEP");
  scanf("%s", c.endereco.cep);

  printf("\nEstado:");
  scanf("%s", c.endereco.estado);

  printf("\nCidade:");
  scanf("%s", c.endereco.cidade);
  //-------fim endereços

  printf("\nInforme sua cnh");
  scanf("%s", c.cnh);

  printf("\n\ncliente fim");
}



//----------------------Listagemm de clientes-----------------------------
// Lista os clientes cadastrados
void listarClientes(int tamanho) 
{
  
  tCliente c[500];
  int i;
  
  for (i = 0; i < tamanho && strcmp(c[i].nome, "EOF") != 0; i++)
    {
     printf("\n%s, %s, %s",c[i].nome, c[i].telefone, c[i].codigo);  
    }
    printf("\n\n");
}


//-------------------------Procura por nome---------------------------------
// Procura cliente por nome
int pesquisaCliente(char nome[]) 
{ 
  tCliente c[500];
  int i = 0;
 
  
  printf("digite o filtro para o nome : ");
    scanf("%s",&nome[i]);
    printf("\n\nNumero, nome, celular, cep");
    for (int i = 0;strcmp(c[i].nome,"EOF") != 0; i++)
    {
        if ( myStrCmp(nome,c[i].nome) == 0)
            printf("\n%d, %s, %s, %c",i,c[i].nome, 
c[i].telefone, c[i].endereco.cep);
      return c[i].nome;
      }
    printf("\n\n");
}


// Abrir o arquivo para editar, colocar o vetor (cadastro[1000]) la dentro
void escreveArquivo(int busca) {
  int i;
  tCliente c[500];
  FILE *arqCliente;
  arqCliente = fopen("clientes.txt", "w");

  for (i = 0; i < busca; i++) {
    fprintf(arqCliente, "%s \n", c[i].nome);
    fprintf(arqCliente, "%s \n", c[i].telefone);
    fprintf(arqCliente, "%s \n", c[i].endereco.rua);
    fprintf(arqCliente, "%s \n", c[i].endereco.bairro);
    fprintf(arqCliente, "%s \n", c[i].endereco.numero);
    fprintf(arqCliente, "%s \n",c[i].endereco.complemento);
    fprintf(arqCliente, "%s \n", c[i].endereco.cep);
    fprintf(arqCliente, "%s \n", c[i].endereco.estado);
    fprintf(arqCliente, "%s \n", c[i].endereco.cidade);
    fprintf(arqCliente, "%s \n", c[i].cnh);
  
    }
  }
