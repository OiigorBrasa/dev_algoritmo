#include <stdio.h>
#include "numeros.h"
#include <stdlib.h>

int main(){
    int a ;
    int b ;

    scanf("%d", &a);
    scanf("%d", &b);
    
    printf("a: %d e b %d\n", a, b);
    printf("Par: %d\n",par(a));
    printf("Primo: %d\n",primo(a));
    printf("Fatorial: %d\n",fatorial(a));
    printf("Maior: %d\n",maior(a,b));
    printf("Potencia: %d\n",potencia(a,b));

    system("pause");
    return 0;
}