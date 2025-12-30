#include <stdio.h>
#include <stdlib.h>

int** aloca_matriz_denteada(int linhas, int* tamanho_colunas){

  int** m = malloc(linhas * sizeof(int*));
  if (m == NULL){
    exit(1);
  }
  for (int i = 0; i < linhas;i++){
    m[i] = malloc(tamanho_colunas[i] * sizeof(int));
    if(m[i] == NULL){
      for (int j = i-1 ; j >= 0 ; j--){
        free(m[j]);
      }
      free(m);
      exit(1);
    }
  }   

  return m;
}

void libera_matriz_denteada(int **matriz, int linhas){

  for (int i = 0; i < linhas; i++){
    free(matriz[i]);
  }
  free(matriz);
}

int main(){
  int tamcol[5]; 
  for (int i = 1; i < 5;i++) tamcol[i] = i;
  int** jagged = aloca_matriz_denteada(5, tamcol);
  
  libera_matriz_denteada(jagged, 5);
  return 0;
}
