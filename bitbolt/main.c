#include <stdio.h>
#include <stdlib.h>
#include <string.h> // biblioteca para utilizar o strcmp() para comparar duas strings (atualizado: Programa necessario no momento, pois, vai ser necessario se eu utilizar email ou nome de usuario para comparar os 2 programas.
#include <time.h> // biblioteca para aplicar a data e horario da movimentação na funcão extratos()

int menu_login(char cpf[12], char senha[7], char nomec[60]);
int d = 0;
void plataform_acess(char cpf[12], char senha[7], char nomec[60]); // definindo a funcao;
void op(char cpf[12], char senha[7], char nomec[60],int select);
void op3(), op4(), op5(), op6();
void dados_banco(char cpf[12], int select);
void acao_banco(int select);
int atualizar_extrato(char acao[2],float deposito,char em[10],float ct,float tx,float real,float btc,float eth,float xrp);

int main() {
	
    FILE *f = fopen("dados/usuario.txt", "r");
    if (f == NULL) {
        printf("erro ao abrir o arquivo");
        return 1;
    }
    char cpf[12];  // aplicar cpf aqui.
    char senha[7]; // ateh 6 digitos.
    char nomec[60];
    if (fscanf(f, "%s %s %[^\n]", cpf, senha, nomec) == 3) { // [^\n] -> vai realizar leituras dos nomes ate encontrar o final da linha e armazenar na variavel
        if (menu_login(cpf, senha, nomec) == 1) {
            plataform_acess(cpf, senha, nomec); // aplicando jah os dados do usuario dentro do parametro da funcao
        } else {
            printf("tente novamente:\n");
            (menu_login(cpf, senha, nomec)) ? plataform_acess(cpf, senha, nomec) : printf("Limite ultrapassado, tente novamente reabrindo o programa"); // aplicado a operacao ternario para analisar o retorno da funcao menu_login.
            return 0;
        }
    } else {
        printf("Erro ao capturar todos dados de usuario!");
        fclose(f);
        return 1;
    }
    fclose(f);
	return 0;
}

int menu_login(char cpf[12], char senha[7], char nomec[60]) {
    char dcpf[12];
    char dsenha[7] = "";

    printf("---Aba de login---\n");
    printf("Usuario: ");
    scanf("%12s", dcpf); // %12s limite ateh 12 digitos, para evitar stack overflow.

    if (strcmp(cpf, dcpf) == 0) { // comparar 2 valores, entre o input do usuario e dados armazenado no arquivo
        printf("Senha (numeros): ");
        scanf("%6s", dsenha);
        if (strcmp(senha, dsenha) == 0) {
            // armazenar os dados de usuario em ponteiros de memoria para reutilizar em outras funcoes
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

void plataform_acess(char cpf[12], char senha[7], char nomec[60]) {
    int option = 0;
    int status = 1;
 do{
    printf("\n---Bem vindo a plataforma bitbolt!---\n");
    printf("\n\nProximo passo:\n");
    printf("\n1. Consultar saldo\n2. Consultar extrato\n3. Depositar\n4. Sacar\n5. Comprar criptomoedas\n6. Vender criptomoedas\n7. Atualizar cotacao\n8. Sair\n: ");
    scanf("%1i", &option);

    switch (option) { // utilizar o switch pois as opcao sao de casos
    case 1:
        printf("Opcao 1 selecionada\n");
  	    op(cpf, senha, nomec, 1);
    	break;
    case 2:
        printf("Opcao 2 selecionada\n");
        op(cpf, senha, nomec, 2);
        break;
    case 3:
        printf("Opcao 3 selecionada\n");
        acao_banco(1);
        break;
    case 4:
        printf("Opcao 4 selecionada\n");
        acao_banco(2);
        break;
    case 5:
        printf("Opcao 5 selecionada\n");
        break;
    case 6:
        printf("Opcao 6 selecionada\n");
        break;
    case 7:
        printf("Opcao 7 selecionada\n");
       	break;
    case 8:
        printf("Saindo...");
        status = 0;
        break;
    default: 
    	printf("Selecione de 1 a 8!\n");
		}
	}while(status != 0);
}

void op(char cpf[12], char senha[7], char nomec[60],int select) {
    // depois, realizar manutencao para que o programa leia os arquivos e armazenar na variavel, por enquanto as variaveis serao definidas por aqui
    char dsenha[7];

    printf("Senha (numeros): ");
    scanf("%6s", dsenha);
    printf("\n");

    if (strcmp(senha, dsenha) == 0) {
        // exibicao de dados, aplicar verificacao por senhas antes de realmente fazer os dados aparecer;
        printf("Nome: %s\n", nomec);
        printf("Cpf: %s\n\n", cpf);
        dados_banco(cpf, select);
    } else {
        printf("Senha incorreta!");
    }
}

void dados_banco(char cpf[12], int select) {
    if (select == 1){
        char moeda[12];
        float quantia = 0.000;
        FILE *f = fopen("dados/banco.txt", "r");
        if (f == NULL) {
            printf("Erro ao abrir arquivo banco");
            return;
        }
        // enquanto nao chegar ao final do arquivo
        while (fscanf(f, "%s %f\n", moeda, &quantia) == 2) { // enquanto a linha atual do arquivo existir, vai continuar lendo ate chegar no 0
            if (strcmp(moeda, "Bitcoin") == 0) {
                printf("%s: %.4f\n", moeda, quantia);
            } else {
                printf("%s: %.2f\n", moeda, quantia);
            }
        }
        fclose(f);
    }
    else if(select == 2){
        FILE *f = fopen("dados/extratos.txt", "r");
		if (f == NULL) {
            printf("Erro ao abrir arquivo banco");
            return;
        }
        char c[255]; // armazena oque foi lido
        // enquanto nao chegar ao final do arquivo
        while (fgets(c,sizeof(c), f) != NULL) { // enquanto a linha atual do arquivo existir, vai continuar lendo ate chegar no 0   
        	printf("%s", c);
		}
        fclose(f);
	}
}

void acao_banco(int select) {
    // 1: deposito, 2: saque
    if (select != 1 && select != 2) return;

    float reais = 0, btc = 0, eth = 0, xrp = 0, valor = 0, total = 0;
    FILE *f = fopen("dados/banco.txt", "r");

    if (f == NULL) {
        printf("Erro ao abrir arquivo banco para leitura.\n");
        return;
    }

    if (fscanf(f, "Reais %f\nBitcoin %f\nEthereum %f\nRipple %f", &reais, &btc, &eth, &xrp) != 4) {
        printf("Erro ao ler formato do arquivo.\n");
        fclose(f);
        return;
    }
    fclose(f);

    if (select == 1) { // DEPÓSITO
        printf("Valor de deposito: ");
        scanf("%20f", &valor);
        total = reais + valor;
        printf("Valor a depositar %.2f e o saldo ficara %.2f\n", valor, total);
    } else { // SAQUE
        printf("Valor disponivel para sacar: %.2f\n", reais);
        printf("Insira o valor de saque: ");
        scanf("%20f", &valor);
        total = reais - valor;
        
        if (total < 0) {
            printf("Nao foi possivel realizar saque, valor ultrapassado!\n");
            return; 
        }
    }

    f = fopen("dados/banco.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir arquivo banco.txt para escrita.\n");
        return;
    }

    if (fprintf(f, "Reais %.2f\nBitcoin %.4f\nEthereum %.2f\nRipple %.2f", total, btc, eth, xrp) < 0) {
        printf("Erro ao inserir saldo em arquivo.\n");
    } else {
        printf("%s realizado com sucesso!\n", select == 1 ? "Deposito": "Saque");
        if(select == 2){
        	printf("Novo saldo: %.2f\n",total);
		}
        atualizar_extrato(select == 1 ? "+" : "-", valor, "REAIS", 0.0, 0.0, total, btc, eth, xrp);
    }
    
    fclose(f);
}

int atualizar_extrato(char acao[2],float deposito,char em[10],float ct,float tx,float real,float btc,float eth,float xrp){
	FILE *ext = fopen("dados/extratos.txt","a");
	
	time_t tempo_atual = time(NULL); // pesquisado no google como capturar o tempo e horario atual
	struct tm *info_tempo = localtime(&tempo_atual);
	
	fprintf(ext,"%02d-%02d-%d %02d:%02d %s %.2f %s CT: %f\tTX: %.2f REAL: %.2f BTC: %.4f ETH: %.2f XRP: %.2f\n",
		info_tempo->tm_mday, 
    	info_tempo->tm_mon + 1,      // Meses vão de 0 a 11
    	info_tempo->tm_year + 1900, // Anos contados a partir de 1900
		info_tempo->tm_hour, 
    	info_tempo->tm_min, 
		acao,
		deposito,
		em,
		ct,
		tx,
		real,
		btc,
		eth,
		xrp
		);
	
	fclose(ext);
	return 0;
	
}
