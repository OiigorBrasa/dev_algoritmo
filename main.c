#include <stdio.h>
#include <stdlib.h>
	
int main(){

	char nome[20] = "igor";
	int senha = 123;
	
	char dnome[20] ;
	int dsenha;
		
	printf("Aba de login:\n");
	printf("Nome do usuário:\n");
	scanf("%s", &dnome);
		
	printf("%s , %s", nome, dnome);
	return nome == dnome;
	

	system("pause");
	return 0;
	
	
}
