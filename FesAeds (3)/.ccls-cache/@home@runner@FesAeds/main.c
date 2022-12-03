// Integrantes do grupo: João Gabriel Perez, Joaquim de Moura Thomaz Neto, Tito Li An Chen                        

#include <stdio.h>
#include <string.h> 
#include <stdbool.h>

//arquivos do programa 
  
#include "endereco.c"
#include "locacao.c"
#include "veiculo.c"
tCliente vetCLiente[1000];
tVeiculo vetVeiculo[100];
tLocacao vetLocacao[1000];
int main() {
  int opcao;
  
  printf("----------Menu Inicial----------\n"); //Menu inicial
  printf("\nPara abrir menu de veiculos, digite (1)");
    scanf("%d", &opcao);
  printf("\nPara acessar menu de locação, digite (2)");
    scanf("%d", &opcao);
  printf("\nPara acessar (Salva vetores) digite (3)");
    scanf("%d", &opcao);
  
  if (opcao == 1)
  {
  //Função veiculos
  menuVeiculos();
  }
  if (opcao == 2)
  {
    menuLocacao();
  }
  if (opcao == 3)
  {
    menuCliente();
  }
  return 0;
  
}