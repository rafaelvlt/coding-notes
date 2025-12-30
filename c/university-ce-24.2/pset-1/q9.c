#include <stdio.h>
#include <math.h>

int main(){
    int t;
    float aresta, altura, area;
    scanf("%d %f %f", &t, &aresta, &altura);
    switch(t){
        case 1:
        printf("O volume da piramide eh: %.2f", (aresta*aresta*altura)/3);
        break;
        case 2:
        area = (6*aresta*aresta*sqrt(3)/4);
        printf("O volume da piramide eh: %.2f", (area*altura/3) );
        break;
        default:
        printf("Escolha invalida!");
        break;
    }
    return 0;
}
