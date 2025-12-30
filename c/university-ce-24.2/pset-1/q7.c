#include <stdio.h>

int main(){
    int dia, caixas, caminhoes;
    float largura = 0.7, comprimento = 0.8, altura = 0.6;
    scanf("%d %d", &dia, &caixas);
    float volume = caixas * largura * comprimento * altura;
    caminhoes = (volume / 20) + 1;
    if (dia == 1 || dia == 2){
        float valor = 45.00 * volume;
        printf("Custo total da mudanca : R$ %.2f\nVolume total necessario : %.2f metros cubicos\nQuantidade de caminhao necessario : %d caminhoes ", valor, volume, caminhoes);
    }
    else if(dia == 3 || dia == 4 || dia == 5){
        float valor = 30.00 * volume;
        printf("Custo total da mudanca : R$ %.2f\nVolume total necessario : %.2f metros cubicos\nQuantidade de caminhao necessario : %d caminhoes ", valor, volume, caminhoes);
    }else if (dia == 6 || dia == 7){
        float valor = 30.00 * volume;
        printf("Custo total da mudanca : R$ %.2f\nVolume total necessario : %.2f metros cubicos\nQuantidade de caminhao necessario : %d caminhoes ", valor, volume, caminhoes);
    }else {printf("Dia invalido!");}
        return 0;
    }
