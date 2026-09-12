//ex4
#include <stdio.h>

int main(){
int len = 15;

int array[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
int impar = 0;
int par = 0;
printf("Valores:" );
for(int i=0; i < len; i++){
	printf("%d ", array[i] );
	if(array[i]%2==0){
		par += 1;
	}else{
		impar +=1;
	}

}
	printf("\nQuantidade de pares: %d\n", par);
	printf("Quantidade de impares: %d", impar);
}
