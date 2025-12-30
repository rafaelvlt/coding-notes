#include <stdio.h>

int main(){
    int matriz[3][3];
    int *p, *q, *r;
    for (int i = 0; i<3 ; i++){
        for(int j = 0; j<3; j++){
            scanf("%d", &matriz[j][i]);
        }
    }
    p = &matriz[0][0];
    q = &matriz[1][1];
    r = &matriz[2][2];
    printf("Diagonal principal da matriz (valores criticos):\n");
    printf("Elemento [0][0]: %d\nElemento [1][1]: %d\nElemento [2][2]: %d", *p, *q, *r);
    return 0;
}
