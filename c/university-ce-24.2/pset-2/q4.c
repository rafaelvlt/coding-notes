#include <stdio.h>
#include <string.h>
int main(){
    int termos = 0;
    char stringfim[100] = "", strTemp[10];
    scanf("%d", &termos);
    for (int i = 0; i < termos; i++){
      fflush(stdin);    
      scanf(" %10[^\n]", strTemp);
      fflush(stdin);
      strcat(stringfim, strTemp);
      strcat(stringfim, " ");
    }
    printf("Equacao formada: %s= 0", stringfim);
    return 0;
}
