#include <stdio.h>
#include <string.h>

struct senha{
    int caracteres;
    int upper;
    int lower;
    int digito;
    int especial;
};

int main(){
    char senhausr[100];
    struct senha tent;
    tent.caracteres = 0;
    scanf(" %99[^\n]", senhausr);
    fflush(stdin);
    for (int i = 0; i < strlen(senhausr); i++){
        tent.caracteres++;
        if (senhausr[i] < 91 && senhausr[i] > 64){
            tent.upper = 1;
        } else if(senhausr[i] < 123 && senhausr[i] > 96){
            tent.lower = 1;
        } else if(senhausr[i] < 58 && senhausr[i] > 47){
            tent.digito = 1;
        } else if(senhausr[i] < 48 && senhausr[i] > 32){
            tent.especial = 1;
        }
    }
    if (tent.caracteres < 8){
        printf("A senha deve ter pelo menos 8 caracteres.\n");
        return 0;
    }
    if (!tent.upper){
        printf("A senha deve conter pelo menos uma letra maiuscula.\n");
    }
    if (!tent.lower){
        printf("A senha deve conter pelo menos uma letra minuscula.\n");
    }
    if (!tent.digito){
        printf("A senha deve conter pelo menos um digito.\n");
    }
    if (!tent.especial){
        printf("A senha deve conter pelo menos um caractere especial(!@#$%%^&*()).\n");
    }
    if(tent.upper && tent.lower && tent.digito && tent.especial){
        printf("Senha forte!\n");
    }
    
    return 0;
}
