#include <stdio.h>
void aumento(double salario){
    float porcentagem = 0;
    double novosalario = 0;
    double reajuste = 0;
    
    if(salario <= 0){
        porcentagem = 0;
    }else if(salario > 0 && salario <= 400){
        porcentagem = 15;
        
    }else if(salario > 400 && salario <= 800){
        porcentagem = 12;
        
    }else if(salario >800 && salario<=1200){
        porcentagem = 10;
    
    }else if(salario >1200 && salario<=2000){
        porcentagem = 10;
        
    }else if(salario >800 && salario<=1200){
        porcentagem = 10;
    }else if(salario >1200 && salario<=2000){
        porcentagem = 7;   
    }else{
        porcentagem = 4;
    }
    novosalario = (porcentagem / 100 + 1) * salario;
    reajuste = novosalario - salario;
    printf("Novo salario = %.2lf\n",novosalario);
    printf("Valor do reajuste = %.2lf\n",reajuste);
    printf("Indice do reajuste = %.0f",porcentagem);
    
}
int main(){
    double salario;
    printf("Digite o salário:\n");
    scanf("%lf", &salario);
    aumento(salario);
    
}