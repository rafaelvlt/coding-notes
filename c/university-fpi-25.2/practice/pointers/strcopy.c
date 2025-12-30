#include <stdio.h>

void meu_strcpy(char* destino, const char* origem){

  int origem_len = 0; 
  while (*(origem + origem_len) != '\0') origem_len++;

  int destino_len = 0;
  while (*(destino + destino_len) != '\0') destino_len++;

  int i = 0;
  for (; i < destino_len-1 && i < origem_len; i++){
    *(destino + i) = *(origem + i);
  }
  for (; i < destino_len; i++) *(destino + i) = '\0';
}

int main(){
  char str1[] = "teste";
  char str2[] = "blab";

  meu_strcpy(str1, str2);

  printf("str1: %s\nstr2: %s\n", str1, str2);

  return 0;
}
