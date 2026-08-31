#include "calculadora.h"  
 // aspas duplas sãos para chamar a função que está dentro do mesmo arquivo
float somar(float a, float b){
return a + b; // retornar o resultado da equação
}
float substrair(float a,float b){
return a-b;
}
float multiplicar(float a,float b){
return a*b;
}
float dividir(float a,float b){
return a/b;
}
int eh_divisao_valida(float divisor){
if(divisor != 0){
return 1;
}else{
return 0;
}
}