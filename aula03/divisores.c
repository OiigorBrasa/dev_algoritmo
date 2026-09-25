#include <stdio.h>

void divisao(int, int);

int main(void) {
  // faça aqui o main
  int dividendo, divisor;
  printf("Digite o dividendo:\n");
  scanf("%d",&dividendo);
  printf("Digite o divisor:\n");
  scanf("%d",&divisor);
  divisao(dividendo,divisor);
  return 0;
}

void divisao(int a, int b) {
    int resto = a;
    int quociente = 0;
    while (resto >= b){
        resto = resto - b;
        quociente++;
    };
    printf("o quociente é %d com resto %d",quociente, resto);
    
}