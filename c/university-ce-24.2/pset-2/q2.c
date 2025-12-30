#include <stdio.h>
#include <string.h>
#include <ctype.h>
void criptografar(char m[], int desloc){
    int tam = strlen(m);
    for(int i = 0; i < tam; i++){
        if (isupper(m[i])){
            if ((m[i] + desloc) <= 90){
                m[i] = m[i] + desloc;
            }
            else{
                m[i] = 64 + (m[i] + desloc - 90); 
                }
        }
        else if(islower(m[i])){
             if ((m[i] + desloc) <= 122){
                m[i] = m[i] + desloc;
            }
            else{
                m[i] = 96 + (m[i] + desloc - 122); 
                }
        }
        else{
            if(m[i] == ' ' || m[i] == '\0'){
            }
            else{
            m[i] = m[i] + desloc;
            }
        }
    }
    printf("%s\n", m);
}
void descriptografar(char m[], int desloc){
    int tam = strlen(m);
    for(int i = 0; i < tam; i++){
        if (isupper(m[i])){
            if ((m[i] - desloc) >= 65){
                m[i] = m[i] - desloc;
            }
            else{
                m[i] = 90 + (65 - m[i] - desloc); 
                }
        }
        else if(islower(m[i])){
             if ((m[i] - desloc) >= 97){
                m[i] = m[i] - desloc;
            }
            else{
                m[i] = 123 + (m[i] - 97 - desloc); 
                }
        }
        else{
            if(m[i] == ' ' || m[i] == '\0'){
            }
            else{
            m[i] = m[i] + desloc;
            }
        }
    }
    printf("%s\n", m);
}
int main(){
    int opcao, mudanca;
    char mensagem[100], lixo;
    scanf("%d", &opcao);
    if (opcao == 1){
        scanf("%d", &mudanca);
        scanf(" %99[^\n]s", mensagem);
        criptografar(mensagem, mudanca);
    }
    else if (opcao == 2){
        scanf("%d", &mudanca);
        scanf(" %99[^\n]s", mensagem);
        descriptografar(mensagem, mudanca);
    }
    else{
        printf("Opcao invalida. Encerrando o programa.");
        return 0;
    }
    return 0;
}
