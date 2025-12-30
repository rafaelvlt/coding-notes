#include <stdio.h>

int main(){
    int a, b, c, alto, meio, baixo;
    scanf("%d%d%d", &a, &b, &c);
    //faz lógica para decidir qual valor é o maior
    if (a > b && a > c) {alto = a;}
    else if (b > a && b > c) {alto = b;}
    else {alto = c;}
    //sabendo do maior, determina qual o valor intermediário
    if (alto != a && (a > b || a > c)) { meio = a;}
    else if (alto != b && (b > a || b > c)) { meio = b;}
    else {meio = c;}
    
    //determina o menor numero
    if (a < meio && a < alto) {baixo = a;}
    else if (b < meio && b < alto) {baixo = b;}
    else {baixo = c;}
    //printa o resultado
    printf("%d %d %d\n", baixo, meio, alto);
    
    return 0;
}
