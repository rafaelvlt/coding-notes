#include <stdio.h>


int absValue(int x){
    if (x >= 0) return x;
    if (x < 0) return -x;
}

int main(){
    int xSite;
    int qtdCanais;

    scanf("%d %d", &xSite, &qtdCanais);

    int paresCanais[qtdCanais][2];
    for (int i = 0; i < qtdCanais ; i++){
        scanf("%d %d", &paresCanais[i][0], &paresCanais[i][1]);
    }

    int distAnterior = 99999;
    int distAtual = 0;
    int anterior;
    int atual;
    int minutos = 0;
    int momentos[qtdCanais][3];

    for (int i = 0; i < qtdCanais; i++){
        int diminuindoDistancia = 1;
        anterior = paresCanais[i][0];
        atual = paresCanais[i][1];
        minutos = 0;
        distAnterior = 99999;
        distAtual = 0;
        while(diminuindoDistancia){
            ++minutos;
            if (minutos == 1){
                distAtual = xSite - anterior;
            }
            else if(minutos == 2){
                distAnterior = distAtual;
                distAtual = xSite - atual;
            }
            else{
                int temp = anterior;
                anterior = atual;
                atual = temp + atual;
                distAnterior = distAtual;
                distAtual = xSite - atual;
            }

            if (absValue(distAtual) >= absValue(distAnterior)) {
                diminuindoDistancia = 0;
                distAtual = distAnterior;
                --minutos;
            }
        }
        momentos[i][0] = absValue(distAtual);
        momentos[i][1] = anterior;
        momentos[i][2] = minutos;
    }
    int distMin = 99999;
    int canalMelhor = 0;
    int minutosMelhor = 0;
    int vip = 0;
    for (int i = 0; i < qtdCanais; i++){
        if (momentos[i][0] <= distMin){
            canalMelhor = i + 1;
            minutosMelhor = momentos[i][2];

            int soma = 0;
            int numero = momentos[i][1];
            while (numero > 0){
                soma += numero % 10;
                numero = numero / 10;
            }

            if (soma > 10) vip = 1;
            else vip = 0;

            distMin = momentos[i][0];
        }
    }

    if (vip){
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n", canalMelhor, minutosMelhor);
    }
    else{
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP n�o vai rolar :(\n", canalMelhor, minutosMelhor);
    }
    return 0;
}

