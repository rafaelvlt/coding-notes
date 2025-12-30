#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int matriz[n][m];
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    int transp[m][n];
    for (int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            transp[y][x] = matriz[x][y];
        }
    }
    for (int i = 0; i< m; i++){
        for(int j = 0; j< n; j++){
            printf("%d ", transp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
