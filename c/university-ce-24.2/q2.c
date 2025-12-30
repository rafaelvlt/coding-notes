#include <stdio.h>
#include <string.h>
void conversor(char tipo[15], int x){
    unsigned int convertido = 0;
    int i = 0;
    int binario[32];
    if (strcmp(tipo, "binario") == 0){
        while (x > 0) {
            binario[i] = x % 2;
            x = x / 2;
            i++;
        }
        printf("O numero em binario eh: ");
        for (int j = (i - 1); j >= 0; j--){
             printf("%d", binario[j]);
        }
    }
    else if (strcmp(tipo, "hexadecimal") == 0){
            printf("O numero em hexadecimal eh: %X", x);
        }
    else if (strcmp(tipo, "octal") == 0){
            printf("O numero em octal eh: %o", x);
        }  
    else{
        printf("Sistema de destino invalido!");
    }
}

int main(){
    char sistema[15];
    int numero;
    scanf("%14[^\n]", sistema);
    scanf("%d", &numero);
    conversor(sistema, numero);
    return 0;
}

