#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 200
#define MAX_NAME 100

typedef enum {
  Estagiário = 0,
  Analista,
  Gerente,
  Diretor,
} Cargos;

typedef struct {
  char nome[MAX_NAME];
  int idade;
  double salario;
  Cargos cargo;
} funcionario;

funcionario criarFuncionario();

void aumentarSalario(funcionario* f, double percentual);

void listarPorCargo(funcionario* lista, int n, Cargos tipo);

int main(){
  int qtd_funcionarios = 1; 
  funcionario quadro_funcionarios[TAM_MAX];
  
  quadro_funcionarios[qtd_funcionarios - 1] = criarFuncionario();
  funcionario* jorge = &quadro_funcionarios[qtd_funcionarios - 1];

  aumentarSalario(jorge, 0.55);
 
  listarPorCargo(quadro_funcionarios, qtd_funcionarios, Estagiário);
  return 0;
}

funcionario criarFuncionario(){
  funcionario temp;

  printf("Digite o nome do funcionário: ");
  fgets(temp.nome, MAX_NAME, stdin); 
  temp.nome[strcspn(temp.nome, "\n")] = 0; 

  printf("Digite a idade do funcionário: ");
  scanf("%d", &(temp.idade));

  printf("Digite o salário do funcionário: ");
  scanf("%lf", &(temp.salario));
  getchar(); //tira buffer 
  int valido = 0;
  
  while(!valido){ 
    valido = 1;
    printf("Digite o cargo do funcionário: ");
    char tempcargo[MAX_NAME];
    fgets(tempcargo, MAX_NAME, stdin); 
    tempcargo[strcspn(tempcargo, "\n")] = 0;

    if      (!strcmp(tempcargo, "Estagiário")) temp.cargo = Estagiário; 
    else if (!strcmp(tempcargo, "Analista")) temp.cargo = Analista;
    else if (!strcmp(tempcargo, "Gerente")) temp.cargo = Gerente;
    else if (!strcmp(tempcargo, "Diretor")) temp.cargo = Diretor;
    else {
      printf("Cargo inválido, tente novamente.\n");
      valido = 0; 
    }

  } 

  return temp;
}


void aumentarSalario(funcionario* f, double percentual){
  f->salario += f->salario * percentual;
}

void listarPorCargo(funcionario lista[], int n, Cargos tipo){
  
  printf("LISTA DE ");
  if (tipo == Estagiário) printf("ESTAGIÁRIOS\n");
  else if (tipo == Analista) printf("ANALISTAS\n");
  else if (tipo == Gerente) printf("GERENTES\n");
  else printf("DIRETORES\n");

  for (int i = 0; i < n; i++){
    if (lista[i].cargo == tipo){
      printf("FUNCIONARIO #%d\n", i);
      printf("NOME: %s\n", lista[i].nome);
      printf("IDADE: %d\n", lista[i].idade);
      printf("SALÁRIO: %lf\n", lista[i].salario);
    }
  }
}
