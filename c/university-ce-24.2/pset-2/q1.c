#include <stdio.h>

int fibonnaci(int n, int soma){
    if (n == 1){
        return 1;
    }
    else if(n < 1){
        return 0;
    }
    else{
        return soma = fibonnaci(n - 1, soma) + fibonnaci(n - 2, soma); 
    }
    
}

int main(){
    int termo, valor = 0;
    scanf("%d", &termo);
    valor = fibonnaci(termo, valor);
    printf("O %d termo da sequencia de Fibonacci e %d.", termo, valor);
    return 0;
}
