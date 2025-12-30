#include <stdio.h>

void printPonto(int qtd){
    for (int i = 0; i < qtd; i++) printf(".");
}

int main(){

    char input;
    scanf("%c", &input);
    
    if (input == 'A') printf("A\n");
    else{
        int distanciaMax = input - 'A';

        for (int i = 0; i <= distanciaMax; i++){
            
            int pontos = distanciaMax - i;
            printPonto(pontos);
            for (int j = 0; j <= i; j++){
                char dist = 'A' + j;
                if (j == 0) printf("A");
                else{
                    printf("%c", dist);
                    if (j == i){
                        for (int z = j ; z > 0; z--){
                            --dist;
                            printf("%c", dist);
                        }
                    }
                }
                
            }
            printPonto(pontos);
            printf("\n");
        }
    }
    
    return 0;
}

