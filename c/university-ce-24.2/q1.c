#include <stdio.h>
#include <math.h>

void trocar_linhas(int n, double matriz[n][n], int linha1, int linha2) {
    for (int j = 0; j < n; j++) {
        double temp = matriz[linha1][j];
        matriz[linha1][j] = matriz[linha2][j];
        matriz[linha2][j] = temp;
    }
}

void escalonar(int n, double matriz[n][n]) {
    for (int i = 0; i < n; i++) {
        if (fabs(matriz[i][i]) < 1e-9) {  
            int trocou = 0;
            for (int j = i + 1; j < n; j++) {
                if (fabs(matriz[j][i]) > 1e-9) {
                    trocar_linhas(n, matriz, i, j);
                    trocou = 1;
                    break;
                }
            }
            if (!trocou) continue;  
        }
        
        double pivot = matriz[i][i];
        for (int g = i + 1; g < n; g++) {
            if (matriz[g][i] != 0) {
                double m = (-1) * matriz[g][i] / pivot;
                for (int k = 0; k < n; k++) {
                    matriz[g][k] += m * matriz[i][k]; 
                }
            }
        }
    }
}

int nulas(int n, double matriz[n][n]) {
    int linhas_nulas = 0;
    for (int i = 0; i < n; i++) {
        int nula = 1;
        for (int j = 0; j < n; j++) {
            if (fabs(matriz[i][j]) > 1e-9) { 
                nula = 0;
                break;
            }
        }
        if (nula) linhas_nulas++;
    }
    return linhas_nulas;
}

int main() {
    int posto, ld;
    float preco;
    double multa;
    
    scanf("%d %f", &posto, &preco);
    
    double matriz[posto][posto];
    double escalonada[posto][posto];

    for (int i = 0; i < posto; i++) {
        for (int j = 0; j < posto; j++) {
            scanf("%lf", &matriz[i][j]);
            escalonada[i][j] = matriz[i][j];
            printf("%.1f ", escalonada[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    escalonar(posto, escalonada);

    for (int i = 0; i < posto; i++) {
        for (int j = 0; j < posto; j++) {
            printf("%.1f ", escalonada[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    ld = nulas(posto, escalonada);

    if (ld == 0) {
        printf("Nao houve falsificacao neste produto, aproveite!!\n");
    } else {
        multa = preco * pow(1.65, ld);
        printf("O produto esta falsificado, devolva e exija uma multa de %.2lf reais\n", multa);
    }

    return 0;
}

