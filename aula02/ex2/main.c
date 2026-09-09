#include <stdio.h>
#include "numeros.h"
#include <stdlib.h>

int main(){
    int a ;
    int b ;

    scanf("%d", &a);
    scanf("%d", &b);
    
    printf("a: %d e b %d\n", a, b);
    printf("Par de a (1 Nao Par, 0 Par): %d\n",par(a));
    printf("Primo de a (0 Nao primo, 1 Primo): %d\n",primo(a));
    printf("Fatorial de a: %d\n",fatorial(a));
    printf("Maior: %d\n",maior(a,b));
    printf("Potencia com a numerador e b expoente: %d\n",potencia(a,b));

    system("pause");
    return 0;
}