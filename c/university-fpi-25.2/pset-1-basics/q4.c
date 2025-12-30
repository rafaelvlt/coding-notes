#include <stdio.h>

float calcularMediaFinal(int N, float notas[N]){

    if (N < 3){
        printf("Numero de notas insuficiente.\n");
        return -1.0f;
    }
    else{
        float menor = 10000;
        float sMenor = 1000;
        int indMenor;
        for (int i = 0; i < N ; i++){
            if (notas[i] < menor){
                menor = notas[i];
                indMenor = i;
            }
        }
        for (int i = 0; i < N ; i++){
            if(notas[i] < sMenor && i != indMenor){
                sMenor = notas[i];
            }
        }
        if (sMenor < menor){
            float temp = sMenor;
            sMenor = menor;
            menor = temp;
        }

        float media = 0;
        for (int i = 0; i < N; ++i){
            media += notas[i];
        }
        media = media - menor - sMenor;
        media /= (N-2);
        return media;
    }
}

int main(){
    int N;
    scanf("%d", &N);

    float notas[N];
    for (int i = 0; i < N; i++){
        scanf("%f", &notas[i]);
    }

    float mediaFinal = calcularMediaFinal(N, notas);
    if (mediaFinal != -1.0f)printf("%.2f\n", mediaFinal);

    return 0;
}

