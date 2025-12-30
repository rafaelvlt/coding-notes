/*
* This one didn't solve the problem because there was a problem with the judge, but it's the special question of the list, just for extra points
*/
#include <stdio.h>

int main(){
    int n1, n2, n3;
    float barreira = 100.00;
    float somatorio = 0;
    float divisor = 0;
    scanf("%d", &n1);
    if (n1 == 15){
        barreira -= 12.00;
        printf("Nivel de contencao %.2f%%! Akira ainda dorme.\n", barreira);
        do{
            scanf("%d", &n2);
            if (n2 <= n1){
                return 0;
            }
        } while (n2 > n1 + 20);
        for (float i = n1; i <= n2; i++) {
            somatorio += i;
            divisor += 1;
        }
        barreira -= (somatorio / divisor);
        printf("Nivel de contencao %.2f%%! Akira ainda dorme.\n", barreira);
    
        scanf("%d", &n3);
        if (n3 == (n1 + n2)){
            barreira = 0.00;
            printf("Nivel de contencao %.2f%%! Akira despertou!\n", barreira);
            return 0;
        } else {
            barreira += 4.25;
            printf("Nivel de contencao %.2f%%! Akira ainda dorme.\n", barreira);
            return 0;
        }
    }
    else if (n1 == 25){
        barreira -= 16.00;
        printf("Nivel de contencao %.2f%%! Akira ainda dorme.\n", barreira);
        do {
            scanf("%d", &n2);
            if (n2 < 1){
                barreira += 16.00;
                printf("Nivel de contencao %.2f%%! Akira ainda dorme.\n", barreira);
                return 0;
            }
        } while (n2 > n1);

        if (n2 >= 1 && n2 <= n1) {

                for (int i = 1; i <= (n1); i++) {
                if (i % 5 == 0) {    
                    somatorio += i;
                    divisor++;
                }
            }
            barreira -= (somatorio / divisor);
            printf("Nivel de contencao %.2f%%! Akira ainda dorme.\n", barreira);
        }
        
        do {
            scanf("%d", &n3);
            if (n3 < n2){
                barreira -= (n2 - n3);
                printf("Nivel de contencao %.2f%%! Akira ainda dorme.\n", barreira);
                return 0;
            }
        } while (n3 > 85);
        
        if (n3 >= n2 && n3 <= 85){
            barreira -= n3;
            if (barreira >= 0) {
                printf("Nivel de contencao %.2f%%! Akira ainda dorme.\n", barreira);
                return 0;
            } else {
                printf("Nivel de contencao 0.00%%! Akira despertou!\n");
                return 0;
            }
        }
    }
    else if (n1 == 35){
        barreira -= 18.00;
        printf("Nivel de contencao %.2f%%! Akira ainda dorme.\n", barreira);
        
        int tentativa = 0;
        while (tentativa < 3) {
            scanf("%d", &n2);
            if (n2 >= 15 && n2 <= 35) {
                barreira -= n2;
                printf("Nivel de contencao %.2f%%! Akira ainda dorme.\n", barreira);
                break;
            } else {
                barreira += 0.5;
                tentativa++;
                if (tentativa == 3) {
                    printf("Nivel de contencao %.2f%%! Akira ainda dorme.\n", barreira);
                    return 0;
                }
            }
        }

        scanf("%d", &n3);
        if (n3 >= 1 && n3 <= 10){
            printf("Nivel de contencao 0.00%%! Akira despertou!\n");
            return 0;
        } else {
            barreira -= 15.25;
            printf("Nivel de contencao %.2f%%! Akira ainda dorme.\n", barreira);
            return 0;
        }
    }
    else {
        printf("Nivel de contencao %.2f%%! Akira ainda dorme.\n", barreira);
        return 0;
    }
}

