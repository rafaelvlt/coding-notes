#include <stdio.h>

int main(){
    char operacao;
    float x, y, z = 0;
    scanf("%c %f %f", &operacao, &x, &y);
    switch(operacao){
        case 'p':
            printf("Perimetro do retangulo: %.3fcm", (2 * x + 2 * y));
            break;
        case 'a':
            printf("Area do retangulo: %.3fcm quadrados", (x * y));
            break;
        case 'v':
            scanf("%f", &z);
            printf("Volume do paralelepipedo: %.3fcm cubicos", (x * y * z));
            break;
        default: printf("Operador nao existe"); break;
    }
    return 0;
}
