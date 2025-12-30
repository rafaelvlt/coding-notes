#include <stdio.h>

int main()
{
    int qtdQuestoesInicial, qtdQuestoesFinal, incrSemana, semanaAlvo;
    scanf("%d %d %d", &qtdQuestoesInicial, &incrSemana, &semanaAlvo);

    qtdQuestoesFinal = qtdQuestoesInicial + (semanaAlvo - 1) * incrSemana;
    
    printf("Na semana %d Soneca tera que fazer %d questoes!", semanaAlvo, qtdQuestoesFinal);

    return 0;
}

