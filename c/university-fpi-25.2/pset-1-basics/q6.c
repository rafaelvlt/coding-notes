#include <stdio.h>
#include <string.h>

void descriptografar(char msg[], int tamanho, int chave);
void removerNewline(char msg[], int tamanho);
int main(){
    int chave;
    scanf("%d", &chave);
    char msg[51];
    getchar();
    fgets(msg, 50, stdin);
    removerNewline(msg, (int)sizeof(msg));
    while (strcmp(msg, "FIM") != 0){
        int tamanho = strlen(msg);
        descriptografar(msg, tamanho, chave);
        fgets(msg, 50, stdin);
        removerNewline(msg, (int)sizeof(msg));
    }

    return 0;
}

void descriptografar(char msg[], int tamanho, int chave){
    int posLetra = 1;
    int deslocTotal;
    int ind;
    int indiceOrig;
    char origChar;
    for (int i = 0; i < tamanho; i++){
        if (msg[i] != ' '){
            deslocTotal = chave + posLetra;
            if (msg[i] >= 'A' && msg[i] <= 'Z') ind = msg[i] - 'A';
            else ind = msg[i] - 'a' + 26;

            indiceOrig = ind - deslocTotal;
            indiceOrig = (indiceOrig % 52 + 52) % 52;

            if (indiceOrig <= 25) origChar = indiceOrig + 'A';
            else origChar = (indiceOrig - 26) + 'a';
            
            msg[i] = origChar;
            posLetra++;
        }
    }
    
    printf("%s\n", msg);
}

void removerNewline(char msg[], int tamanho){
    for (int i = 0; i < tamanho ; i++){
        if (msg[i] == '\n') msg[i] = 0;
    }
}

