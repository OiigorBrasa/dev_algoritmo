#include <stdio.h>
#include "calculadora.h"
#include <stdlib.h>
int main(){
float a = 10.0 , b = 3.0;
printf("a = %.2f, b = %.2f\n",a,b);
printf("Soma: %.2f\n", somar(a,b));
printf("Substrair: %.2f\n", substrair(a,b));
printf("Multiplicar: %.2f\n", multiplicar(a,b));
if(eh_divisao_valida(b)){
printf("Divisao: %.2f\n", dividir(a,b));
}else{
printf("Erro: Divisao por zero! \n");
}
system("pause"); // Trava a tela preta até você apertar uma tecla
    return 0;
}
