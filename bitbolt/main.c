#include <stdio.h>
#include <stdlib.h>
#include <string.h> // biblioteca para utilizar o strcmp() para compara duas strings (atualizado: Programa nescessï¿½rio no momento, pois, vai ser necessï¿½rio se eu utilizar email ou nome de usuï¿½rio para comparar os 2 progrmaas.

int menu_login();
int d = 0;
void plataform_acess(); // definindo a funï¿½ï¿½o;
void op1c_saldo();


int main(){
	
	plataform_acess();
	
	/*
	if(menu_login()==1){
		//printf("%d true", menu_login());
		plataform_acess();
	}else{
		printf("tente novamente:\n");
		(menu_login()) ? plataform_acess() : printf("Limite ultrapassado, tente novamente reabrindo o programa"); // aplicado a operaï¿½ï¿½o ternï¿½rio para analisar o returno da funï¿½aï¿½ menu_login.
		return 0;
	}
	*/
	return 0;
	
}

int menu_login(){
	
	int cpf = 123; // aplicar cpf aqui depois.
	int senha = 123; // ateh 6 digitos.
	int dcpf = 0;
	int dsenha = 0;
	
	printf("---Aba de login---\n");
	printf("Usuario: ");
	scanf("%20d", &dcpf); // %20d limite atï¿½ 20 digitos, para evitar stack overflow.
	
	if(cpf == dcpf){
		
		printf("Senha (numeros): ");
		scanf("%6d", &dsenha );
		
		if(senha == dsenha){
			return 1;
		}else{
			return 0;
		}
		
	}else{
		return 0;
	}
}

void plataform_acess(){
	int option = 0;
	printf("\n---Bem vindo a plataforma bitbolt!---\n");
	printf("\n\nProximo passo:\n");
	printf("\n1. Consultar saldo\n2. Consultar extrato\n3. Depositar\n4. Sacar\n5. Comprar criptomoedas\n6. Vender criptomoedas\n7. Atualizar cotacao\n8. Sair\n: ");
	scanf("%1i",&option);
	if ( option <= 0 || option >= 8 ){
		main(); // retorna para página principal
	}else{
		switch(option){ // utilizar o switch pois as opï¿½ï¿½o sï¿½o de casos
		case 1: printf("Opcao 1 selecionada\n"); op1c_saldo() 	;break;
		case 2: printf("Opcao 2 selecionada\n");break;
		case 3: printf("Opcao 3 selecionada\n");break;
		case 4: printf("Opcao 4 selecionada\n");break;
		case 5: printf("Opcao 5 selecionada\n");break;
		case 6: printf("Opcao 6 selecionada\n");break;
		case 7: printf("Opcao 7 selecionada\n");break;
		default: printf("Opcao invalida"); break;
		}
	}
		
}

void op1c_saldo(){
	// depois, realizar manuntenção para que o programa leia os arquivos e armazenar na varíavel, por enquanto as variáveis serão definidas por aqui

	char nome[20] = "Igor Reis";
	char cpf[20] = "123.456.789-0";
	int senha = 123;
	int dsenha = 0;
	float reais = 0.00;
	float bitcoin = 0.000;
	float eth = 0.00;
	float ripp = 0.00;
	
	printf("Senha (numeros): ");
	scanf("%6d", &dsenha );
	printf("\n");
	
	if(senha == dsenha){					
		//exibição de dados, aplicar verificação por senhas antes de realmente fazer os dados aparecer;
		printf("Nome: %s\n",nome);
		printf("Cpf: %s\n\n",cpf);
		printf("Reais: %.2f\n",reais);
		printf("Bitcoin: %.3f\n",bitcoin);
		printf("Ethereum: %.2f\n",eth);
		printf("Ripple: %.2f\n",ripp);
	}else{
		printf("Senha incorreta!");
	}

}


