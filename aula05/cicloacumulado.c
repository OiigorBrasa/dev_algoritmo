#include <stdio.h>

int main(){
    int digitado=-1, media; // garante que o digitado não seja qualquer número
    int acc=0, ciclo=0;
    
    while(digitado != 0){
        printf("Digite um número:\n");
        scanf("%d",&digitado);
        if(digitado == 0){
            break;
        } // quebra o ciclo se o digitado for igual à zero
        acc = digitado + acc;
        ciclo++;
    }
    
    media = ciclo > 0 ? acc/ciclo : acc;
    
    printf("Você digitou %d números\n",ciclo);
    printf("O somatório dos números é %d\n",acc);
    printf("Média = %d\n",media);
    return 0;
}