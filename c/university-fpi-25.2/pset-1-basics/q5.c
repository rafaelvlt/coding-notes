#include <stdio.h>

int absVal(int x){
    if (x >= 0) return x;
    else return -x;
}

int power(int x){
    return x * x;
}

int main(){
    int dataNasc[3];
    int dataAtual[3];
    scanf("%d/%d/%d", &dataNasc[0], &dataNasc[1], &dataNasc[2]);
    scanf("%d/%d/%d", &dataAtual[0], &dataAtual[1], &dataAtual[2]);
    
    int amor = 0;
    for (int i = 0; i < 3; i++){
        amor += dataNasc[i] + dataAtual[i];
    }
    amor = (amor * 7) % 101;
    printf("Amor: %d%% ", amor);
    if (amor < 20) puts("Pessimo dia para se apaixonar.");
    else if (amor <= 40) puts("Melhor manter o coracao <3 longe de perigo.");
    else if (amor <= 69) puts("Se o papo e as ideias baterem, esta liberado pensar em algo.");
    else if (amor <= 80) puts("Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.");
    else if (amor > 80) puts("Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.");

    int sorte = (dataAtual[0] + dataNasc[0] + dataAtual[1] + dataNasc[1])*9 + absVal(dataAtual[2] - dataNasc[2]);
    sorte = sorte % 101;
    printf("Sorte: %d%% ", sorte);
    if (sorte < 30) printf("Nem jogue moedas pra cima hoje.");
    else if (sorte <= 50) printf("Melhor nao arriscar.");
    else if (sorte <= 79) printf("Por sua conta em risco.");
    else if (sorte <= 90) printf("Hoje vale a pena arriscar.");
    else if (sorte > 90) printf("Nao tenha medo de virar cartas hoje.");
    puts(" Sem tigrinho nem jogos de azar, por favor!");
    
    int trabalho = dataAtual[2] + dataNasc[2];
    trabalho = (trabalho - ((dataAtual[0] + dataAtual[1] + + dataNasc[0] + dataNasc[1]) * 8)) % 101;
    printf("Trabalho: %d%% ", trabalho);
    if (trabalho < 40) puts("Hoje nao sera um dia tao proveitoso, keep calm e faca o basico.");
    else if (trabalho <= 50) puts("Segura a emocao, nao xinga ninguem, nao esquece de beber agua.");
    else if (trabalho <= 69) puts("Um dia proveitoso com certeza, leve sua simpatia consigo.");
    else if (trabalho <= 84) puts("Boas vibracoes hoje, chances podem estar ao seu redor.");
    else if (trabalho >= 85) puts("Use do maximo de networking poss�vel hoje, dia bom para negocios.");
 
    int cor = (power(dataAtual[0]) + power(dataAtual[1]) + power(dataAtual[2]) + power(dataNasc[0]) + power(dataNasc[1]) + power(dataNasc[2]));
    cor %= 11;
    printf("Cor: ");
    switch(cor){
        case 0:
            printf("Cinza.");
            break;
        case 1:
            printf("Vermelho.");
            break;
        case 2:
            printf("Laranja.");
            break;
        case 3:
            printf("Amarelo.");
            break;
        case 4:
            printf("Verde.");
            break;
        case 5:
            printf("Azul.");
            break;
        case 6:
            printf("Roxo.");
            break;
        case 7:
            printf("Marrom.");
            break;
        case 8:
            printf("Rosa.");
            break;
        case 9:
            printf("Preto.");
            break;
        case 10:
            printf("Branco.");
            break;
    }

    return 0;
}

