#include <stdio.h>

int main(){
int len;
printf("Digite o numero pares do array:");
scanf("%d",&len);

int array[len];
int somatoria[len/2];

for(int i=0; i < len; i++){
	printf("Digite o valor da posicao %d: ",i+1);
	scanf("%d", &array[i]);
}
printf("Os valores digitados somando os impares com pares foram: ");
for(int i = 0; i < len; i+=2){
	
	//printf("%d ", array[i]);

	somatoria[i] = array[i] + array[i+1];
	printf("%d ", somatoria[i]);
	}

}