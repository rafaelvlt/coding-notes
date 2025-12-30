#include <stdio.h>

int main(){
    int x, y, pares = 0;
    scanf("%d %d", &x, &y);
    for (int i = x; i <= y; i++){
        if (i % 2 == 0) pares++;
    }
    printf("Total de numeros pares entre %d e %d: %d", x, y, pares);
    return 0;
}
