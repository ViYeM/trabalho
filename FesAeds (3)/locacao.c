#include "cliente.c"
#include "dataHora.c"
#include "veiculo.c"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// definição do tipo locação
// assinatura locacao: (char codigo) (char codCliente) (char placa) (int diaEmp)
// (int mesEmp) (int diaDev) (int mesDev)
#ifndef MY_HEADER_FILE4
#define MY_HEADER_FILE4

// tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900

struct sLocacao {
  char codigo;
  char codigoCliente;
  char placaVeiculo;
  int diaEmprestimo;
  int mesEmprestimo;
  int diaDevolucao;
  int mesDevolucao;
  int ptsFidelidade;
};
typedef struct sLocacao tLocacao;
int i = 0;

// vetor global das locações
tLocacao vetLocacao[1000];

// registrar inicio aluguel/manutencao
void abrirArquivo() {
  FILE *arqLoca;
  arqLoca = fopen("locacao.txt", "r");
  do {
    i++;
  } while (fscanf(arqLoca, "%s %s %s %d %d %d %d %d", &vetLocacao[i].codigo,
                  &vetLocacao[i].codigoCliente, &vetLocacao[i].placaVeiculo,
                  &vetLocacao[i].diaEmprestimo, &vetLocacao[i].mesEmprestimo,
                  &vetLocacao[i].diaDevolucao,
                  &vetLocacao[i].mesDevolucao),
                  &vetLocacao[i].ptsFidelidade) != EOF);
  i++;
  fclose(arqLoca);
}

// menu locação

void registraSaida() {
  tCliente cliente;
  tVeiculo veiculo;
  char nome[1000], placa[7], text[10];
  time_t mytime;
  mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  vetLocacao[i].diaEmprestimo = tm.tm_mday;
  vetLocacao[i].mesEmprestimo = tm.tm_mon;
  printf("\nVamos registrar o cliente.\nDigite o nome do cliente: ");
  scanf("%s", nome);
  cliente = buscaClientePorNome(nome);
  strcpy(cliente.codigo, &vetLocacao[i].codigoCliente);
  printf("\nVamos registrar o veiculo.\nDigite a placa do carro: ");
  scanf("%s", placa);
  veiculo = obterVeiculoPelaPlaca(placa);
  sprintf(text, "%d", i);
  strcpy(&vetLocacao[i].codigo, text);
  vetLocacao[i].diaDevolucao = 0;

  
}

// registra fim aluguel/manutencao
int registraEntrada() {
  char placa[7];
  time_t mytime;
  mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  printf("\nVamos registrar o veiculo.\nDigite a placa do carro: ");
  scanf("%s", placa);
  for (int x = 0; x < i; x++) {
    if (strcmp(vetLocacao[x].placaVeiculo, placa) == 0) {
      vetLocacao[x].diaDevolucao = tm.tm_mday;
      vetLocacao[x].mesDevolucao = tm.tm_mon;
    }
  }
}

// verificar se o carro esta na locadora ou esta no cliente ou na manutencao.
// retorna 0 para locadora, 1 para cliente, e -1 para manutencao
int verificaStatusCarro(char placa[]) {
  char txt = '0';
  for (int x = 0; x < i; x++) {
    if (strcmp(vetLocacao[x].placaVeiculo, placa) == 0) {
      if (strcmp(vetLocacao[x].diaDevolucao, txt) == 0)
        return 1;
    }
  }
}

// verifica as locação a partir do id do cliente e printa
void verificaLocacaoByID(char id) {
  char txt = '0';
  for (int x = 0; x < i; x++) {
    if (strcmp(vetLocacao[x].codigo, id) == 0) {
      if (strcmp(vetLocacao[x].diaDevolucao, txt) == 0)
        printf("status: alugado");
      else
        printf("status: disponivel");
    }
  }
}



// abrindo menu de locação, chamado no main
int menuLocacao() {
  int escolha;
  printf("Seja bem vindo ao menu de locação. Selecione uma opção:");
  printf("Registrar uma nova locação (1)");
  printf("Registrar uma devolução (2)");
  printf("Registrar uma manutenção (3)");
  printf("Sair (0)");
  switch (escolha) {
  case 1:
    registraSaida();
    break;
  case 2:
    registraEntrada();
    break;
  case 3:
    registraManutencao();
    break;
  case 0:
    return 0;
    break;
  }
  if (escolha > 3 || escolha < 0) {
    printf("Escolha inválida.");
    menuLocacao();
  }
  return 0;
}
#endif