#include <stdio.h>

int main(){
    float arg, col, usa, eu;
    scanf("%f %f %f %f", &arg, &col, &usa, &eu);
    printf("R$ %.2f\n", (arg/170));
    printf("R$ %.2f\n", (col/760));
    printf("R$ %.2f\n", (usa * 5.50));
    printf("R$ %.2f", (eu * 6));
    return 0;
}
