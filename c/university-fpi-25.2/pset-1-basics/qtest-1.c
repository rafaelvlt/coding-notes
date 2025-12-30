#include <stdio.h>

int main() {
    int dia, mes, ano;
    int printar = 1; //1 se valido, 0 se invalido 
    scanf("%d %d %d", &dia, &mes, &ano);
    
    //se passar dos limites
    if ((dia > 31 || dia < 1) || (mes > 12 || mes < 1) || (ano < 1900 || ano > 2100))
    {
        printar = 0;
    }
    //meses de 30
    if (((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11) ) && (dia > 30))
    {
        printar = 0;
    }
    //checagem especial p/fevereiro
    if ((mes == 2) && (dia > 29))
    {
        printar = 0;
    }
    //checagem ano bissexto
    else if ((mes == 2) && (dia == 29))
    {
        //regra esquisita de divis�o por 100 e 400
        if (!(((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)))
        {
            printar = 0;
        }
    }
    
    if (printar == 1) printf("valida");
    else printf("invalida");
    
	return 0;
}
