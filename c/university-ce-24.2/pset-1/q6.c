#include <stdio.h>

int main(){
    int inicio, razao, quantidade, somaA, somaG, termoA, termoB;
    scanf("%d %d %d ", &inicio, &razao, &quantidade);
    termoA = inicio;
    somaA = inicio;
    printf("Progressao Aritmetica (PA): %d, ", inicio);
    for (int i = 0; i < (quantidade - 1); i++){
        termoA += razao;
        if (i == (quantidade - 2)){
            printf("%d", termoA);
        }
        else {printf("%d, ", termoA);}
        somaA += termoA;
    }
    printf("\nSoma da PA: %d", somaA);
    printf("\nProgressao Geometrica (PG): %d, ", inicio);
    somaG = inicio;
    termoB = inicio;
    for (int j = 0; j < (quantidade - 1); j++){
        termoB *= razao;
        if (j == (quantidade - 2)){
        printf("%d", termoB);
        } else { printf("%d, ", termoB);}
        somaG += termoB;
    }
    printf("\nSoma da PG: %d\n", somaG);
    printf("Numero da sorte: %d\n", (somaA + somaG));
    return 0;
}
