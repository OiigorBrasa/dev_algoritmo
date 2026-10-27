#include <stdio.h>
#include <stdlib.h>
#include <string.h> // biblioteca para utilizar o strcmp() para compara duas strings (atualizado: Programa nescessário no momento, pois, vai ser necessário se eu utilizar email ou nome de usuário para comparar os 2 progrmaas.

int menu_login();
int d = 0;
void plataform_acess(); // definindo a função;


int main(){
	
	if(menu_login()==1){
		//printf("%d true", menu_login());
		plataform_acess();
	}else{
		printf("tente novamente:\n");
		(menu_login()) ? plataform_acess() : printf("Limite ultrapassado, tente novamente reabrindo o programa"); // aplicado a operação ternário para analisar o returno da funçaõ menu_login.
		return 0;
	}
	
	return 0;
	
}

int menu_login(){
	
	int cpf = 123; // aplicar cpf aqui depois.
	int senha = 123; // até 6 digitos.
	int dcpf = 0;
	int dsenha = 0;
	
	printf("---Aba de login---\n");
	printf("Usuario: ");
	scanf("%20d", &dcpf); // %20d limite até 20 digitos, para evitar stack overflow.
	
	if(cpf == dcpf){
		
		printf("Senha (números): ");
		scanf("%20d", &dsenha );
		(senha == dsenha) ? return 1: return 0;
		
	}else{
		return 0;
	}
}

void plataform_acess(){
	printf("\n---Bem vindo à plataforma bitbolt!---\n");
	printf("\n\nPróximo passo:\n");
	
}
