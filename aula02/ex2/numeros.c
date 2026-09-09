#include "numeros.h"
 
int par(int a){
    return a % 2;
};

int primo(int a){
    /* Se o a for menor ou igual a 1, não é primo, 2 é primo e os números pares após o 2 não é primo */
    if(a<=1) return 0;
    if(a==2) return 1;
    if(a%2 == 0) return 0;
     /* número não é primo enquanto dividir por ele menos dá 0 */
    for(int i=3; i * i <= a; i+=2){
        if (a%i == 0){
            return 0;
            };
        };
    return 1;
}

int fatorial(int a) {
    int fat=a;
    if(a<0){
        return 0;
    }else{
    for(int i = 1,n; n > 1; i++){
        n = a-i;
        fat = fat * n;   
    };
    };
    return fat;
};

int maior(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    };
    return 0;
};

int potencia(int a, int b){
    int r = a;
    for(int cont = 1; cont < b ; cont++){
        r = r * a;
    }; 
    return r;
};
