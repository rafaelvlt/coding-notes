#include <stdio.h>

int main(){
    char prim, seg, terc, quart, maior1, menor1, maior2, menor2, maiorzao, meiomaior, meiomenor, menorzasso, meio1, meio2;
    scanf("%c %c %c %c", &prim, &seg, &terc, &quart);
    if (prim > seg){
        maior1 = prim; 
        menor1 = seg;
    }else{
        maior1 = seg;
        menor1 = prim;
    }
    if (terc > quart){
        maior2 = terc;
        menor2 = quart;
    }else{
        maior2 = quart;
        menor2 = terc;
    }
    if (maior1 > maior2){
        maiorzao = maior1;
        meio1 = maior2;
    }else {
        maiorzao = maior2;
        meio1 = maior1;
    }
    if (menor1 < menor2){
        menorzasso = menor1;
        meio2 = menor2;
    }else{
        menorzasso = menor2;
        meio2 = menor1;
    }
    if (meio1 > meio2){
        printf("%c %c %c %c", menorzasso, meio2, meio1, maiorzao);
    }else{
        printf("%c %c %c %c", menorzasso, meio1, meio2, maiorzao);
    }
    return 0;
}
