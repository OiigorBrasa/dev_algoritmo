#include <stdio.h>

int dataMagica(int d,int m,int y){
  // faça aqui o desenvolvimento da função
    if(y <= 1900 && y > 2000){
        printf("Insira somente data dentro de século 20");
        
    }else{
        if (y==2000){
            return 0;
        }
        int last2digit = y - 1900; 
        int digit2 = d * m;
        if(last2digit == digit2){

            printf("A data %d/%d/%d é mágica",d,m,y);
        
        }else{
            return 0;
        }
    }
    
}

int main(void) {
int d,m,y;    
scanf("%d %d %d",&d ,&m ,&y);
dataMagica(d,m,y);
return 0;
}
