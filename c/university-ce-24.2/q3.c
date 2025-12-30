#include <stdio.h>

struct Circuito{
    char nome[31];
    float tensao;
    float corrente;
    float potencia;
};




int main(){
    int qntcircuitos;
    scanf("%d", &qntcircuitos);
    int potencias[qntcircuitos];
    struct Circuito a[qntcircuitos];
    for (int i = 0; i < qntcircuitos; i++){
         getchar();
        scanf("%30[^\n]", a[i].nome);
        getchar();
        scanf("%f", &a[i].tensao);
        scanf("%f", &a[i].corrente);
        a[i].potencia = a[i].tensao * a[i].corrente;
    }
    struct Circuito temp;
    for (int i = 0; i < qntcircuitos - 1; i++) {
        for (int j = 0; j < qntcircuitos - 1 - i; j++) {
            if (a[j].potencia < a[j + 1].potencia) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Circuitos em ordem decrescente de potencia:\n");
    for (int i = 0; i < qntcircuitos; i++) {
         if (strcmp(a[i].nome, "Notebook ") == 0) {
            printf("%s- Potencia: %.2f W\n", a[i].nome, a[i].potencia);
        } else {
            printf("%s - Potencia: %.2f W\n", a[i].nome, a[i].potencia);
        }
    }
    
    return 0;
}
