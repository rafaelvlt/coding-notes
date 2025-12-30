#include <stdio.h>

int main(){
    int digitos;
    int valor;
    char arr[11];
    scanf("%d %d", &digitos, &valor);
    printf("Decompondo %d: ", valor);
    sprintf(arr, "%d", valor);
    for(int i = 0; i < digitos ; i++){
        printf("%c  ", arr[i]);
    }
    return 0;
}
