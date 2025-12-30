#include <stdio.h>
#define TAM_MAXIMO 20
#define Potencial 0
#define Gastos 1
#define Tranquilidade 2
#define qtdCriterios 3

int main(){
    // (3 * P + G + 2 * T)/6 >= 3.5
    int qtdLugares = 0;
    scanf("%d", &qtdLugares);

    char lugares[qtdLugares][TAM_MAXIMO+1];  
    float criterios[qtdLugares][qtdCriterios];
    for (int i = 0; i < qtdLugares; i++){
        scanf(" %s", lugares[i]);
        scanf("%f %f %f", 
            &criterios[i][Potencial],
            &criterios[i][Gastos],
            &criterios[i][Tranquilidade]
        );
    }
    int qtdLugaresBons = 0;
    float indices[qtdLugares];
    int posicaoMax = 0;
    float maxIndice = 0.0;

    for(int i = 0; i < qtdLugares; i++){
        indices[i] = (3 * criterios[i][Potencial] + criterios[i][Gastos] + 2 * criterios[i][Tranquilidade])/6;
        if (indices[i] >= 3.5) {
            ++qtdLugaresBons;
            if (indices[i] > maxIndice){
                maxIndice = indices[i];
                posicaoMax = i;
            }
        }
    }
    printf("Temos %d lugares pra visitar!\n", qtdLugaresBons);
    if (qtdLugaresBons > 0){
        printf("Devo comecar por %s", lugares[posicaoMax]);
    }
    else{
        puts("Puts. Melhor ficar em casa mesmo");
    }
    
    return 0;
}



