#include <stdio.h>
#include <stdlib.h>

char* meu_strdup(const char* original){
  
  int og_size = 0;
  while(*(original + og_size) != '\0') ++og_size;

  char* p = malloc(og_size+1);
  if (p == NULL){
    free(p);
    return NULL;
  }

  for (int i = 0; i < og_size; i++) *(p+i) = *(original + i);
  *(p+og_size) = '\0';

  return p;
}

int main(){
  const char* teste = "luv my pookie";

  char* teste2 = meu_strdup(teste);
  
  printf("teste1: %s\nteste2: %s\n", teste, teste2);
  
  free(teste2);

  return 0; 
}
