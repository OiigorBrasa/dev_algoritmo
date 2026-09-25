#include <stdio.h>

void desconto(char t, float l){
    float precoG = 4.39;
    float precoA = 3.19;
    float porcentual = 0;
    
    if (t=='G'){
        // variável = (condição) ? valor_se_verdadeiro : valor_se_falso;
        porcentual = (l <= 20) ?  4 : 6;
        float total = l*precoG;
        float totalfinal = total - total*(porcentual/100);
        printf("Valor com desconto de %.0f%%: %.2f",porcentual,totalfinal);
    }
    if (t=='A'){
        // variável = (condição) ? valor_se_verdadeiro : valor_se_falso;
        porcentual = (l <= 20) ?  3 : 5;
        float total = l*precoA;
        float totalfinal = total - total*(porcentual/100);
        printf("Valor com desconto de %.0f%%: %.2f",porcentual,totalfinal);
    }
    
}

int main(){
    char t;
    float l;
    
    printf("Digite o tipo de combustivel (G para Gasolina ou A para Alcool):\n");
    scanf("%c",&t);
    printf("Digite a quantidade de litros:\n");
    scanf("%f",&l);
    desconto(t,l);
        
}