#include <stdio.h>

int main(){
int len = 8;

int array[] = {1,2,3,4,5,6,7,8};
int maior = array[0];
int menor = array[0];

for(int i=0; i < len; i++){
	if(maior < array[i]){
		maior = array[i];
	}else if(menor < array[i]){
		menor = array[i];
	}

}
	printf("Maior valor: %d\n", maior);
	printf("Menor valor: %d", menor);
}
