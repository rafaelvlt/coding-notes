#include <stdio.h>
#include <math.h>

int main(){
    int energia, velocidade, altitude, temperatura, tempo;
    int erro = 0;
    scanf("%d %d %d %d", &velocidade, &altitude, &temperatura, &tempo);
    energia = velocidade * 10;
    //condições de altitude
    if (altitude < 1000){ energia = energia * 0.9;}
    else if (altitude > 5000){energia = energia * 1.2;}
    //checkagem temperatura
    if (temperatura < -10 || temperatura > 40) {energia = energia * 0.7;}

    //tempo
    if (tempo > 60 && tempo <= 120) {
        energia = energia * pow((1 + 0.1), (tempo - 60) / 30);
    }
    else if (tempo <= 60 && tempo > 0) {}
    else {
        erro = 1;
    }
    
    if (altitude < 0 || velocidade < 0){
        erro = 1;
    }
    
    if (erro != 1){printf("A energia necessaria para o voo eh: %d joules", energia);}
    else {printf("Erro: tempo de voo excedido ou dados invalidos.");}
    return 0;
}
