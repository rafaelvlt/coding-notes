#include <stdio.h>

int somar(int p[], int s[], int res[]){
    for(int i = 0; i < 5; i++){
        res[i] = p[i] + s[i];
    }
}

int main(){
    int v1[5], v2[5], soma[5] = {0};
    for (int i = 0; i < 5; i++){
        scanf("%d", &v1[i]);
    }
    for(int j = 0; j < 5; j++){
            scanf("%d", &v2[j]);
        }
    somar(v1, v2, soma);
    printf("Vetor resultante da soma: ");
    for (int i = 0; i < 5; i++){
        if (i < 5){
            printf("%d ", soma[i]);
        }else{
            printf("%d", soma[i]);
        }
    }
    return 0;
}
