#include <stdio.h>
#include <stdlib.h>
#include <string.h> // biblioteca para utilizar o strcmp() para comparar duas strings (atualizado: Programa necessario no momento, pois, vai ser necessario se eu utilizar email ou nome de usuario para comparar os 2 programas.
#include <time.h> // biblioteca para aplicar a data e horario da movimentação na funcão extratos()

int menu_login(char cpf[12], char senha[7], char nomec[60]);
int d = 0;
void plataform_acess(char cpf[12], char senha[7], char nomec[60]); // definindo a funcao;
void op(char cpf[12], char senha[7], char nomec[60],int select, int qual);
void dados_banco(char cpf[12], int select);
void acao_banco(int select);
void acao_cripto(int select);
int atualizar_extrato(char acao[2],double deposito,char moeda[10],double ct,double tx,double real,double btc,double eth,double xrp, int select);
double taxa_porcentual(double valor, double taxa,int select);
void atualizar_cotacao();

int main() {
   // acao_cripto(2);
    srand(time(NULL));
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
    printf("Usuario (CPF sem Digitos): ");
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
          op(cpf, senha, nomec, 1,1);
        break;
    case 2:
        printf("Opcao 2 selecionada\n");
        op(cpf, senha, nomec, 2,1);
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
        op(cpf,senha,nomec,1,2);
        break;
    case 6:
        printf("Opcao 6 selecionada\n");
        op(cpf,senha,nomec,2,2);
        break;
    case 7:
        printf("Opcao 7 selecionada\n");
           atualizar_cotacao();
		   break;
    case 8:
        printf("Saindo...");
        status = 0; // status 0 ativa a saida no while
        break;
    default: 
        printf("Selecione de 1 a 8!\n");
        }
    }while(status != 0);
}

void op(char cpf[12], char senha[7], char nomec[60],int select, int qual) {
    // depois, realizar manutencao para que o programa leia os arquivos e armazenar na variavel, por enquanto as variaveis serao definidas por aqui
    char dsenha[7];

    printf("Senha (numeros): ");
    scanf("%6s", dsenha);
    printf("\n");

    if (strcmp(senha, dsenha) == 0) {
        // exibicao de dados, aplicar verificacao por senhas antes de realmente fazer os dados aparecer;
        if(qual == 1){
            printf("Nome: %s\n", nomec);            
            printf("Cpf: %s\n\n", cpf);
            dados_banco(cpf, select);
        }else{
            acao_cripto(select);
        }
    } else {
        printf("Senha incorreta!");
    }
}

void dados_banco(char cpf[12], int select) {
    if (select == 1){
        char moeda[12];
        double quantia = 0.000;
        FILE *f = fopen("dados/banco.txt", "r");
        if (f == NULL) {
            printf("Erro ao abrir arquivo banco");
            return;
        }
        // enquanto nao chegar ao final do arquivo
        while (fscanf(f, "%s %lf\n", moeda, &quantia) == 2) {
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
        while (fgets(c,sizeof(c), f) != NULL) { // enquanto a linha atual do arquivo existir, vai continuar lendo ate chegar no 0 (final)
            printf("%s", c);
        }
        fclose(f);
    }
}

void acao_banco(int select) {
    if (select != 1 && select != 2) return;
    char moeda[5] = "REAL";
    double antvalor;
    double reais = 0, btc = 0, eth = 0, xrp = 0, valor = 0;
    FILE *f = fopen("dados/banco.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir arquivo banco para leitura.\n");
        return;
    }
    if (fscanf(f, "Reais %lf\nBitcoin %lf\nEthereum %lf\nRipple %lf", &reais, &btc, &eth, &xrp) != 4) { // Alterado para %lf
        printf("1. Erro ao ler formato do arquivo.\n");
        fclose(f);
        return;
    }
    fclose(f);

    if (select == 1) { 
        printf("Valor de deposito: ");
        scanf("%20lf", &valor); 
        antvalor = valor; // armazena o antigo valor
        valor = reais + valor;
        printf("Valor a depositar %.2f e o saldo ficara %.2f\n", antvalor, valor);
    } else { // SAQUE
        printf("Valor disponivel para sacar: %.2f\n", reais);
        printf("Insira o valor de saque: ");
        scanf("%20lf", &valor); 
        valor = reais - valor;
        
        if (valor < 0) {
            printf("Nao foi possivel realizar saque, valor ultrapassado!\n");
            return; 
        }
    }
    atualizar_extrato(select == 1 ? "+" : "-", antvalor, moeda, 0.0, 0.0, valor, btc, eth, xrp,select);

}


void acao_cripto(int select){
    char moeda[5] = "Real";
    double ceth = 0.0, cxrp = 0.0, cbtc = 0.0;
    double antvalor = 0, reais = 0, btc = 0, eth = 0, xrp = 0, valor = 0, total = 0; 
    
    FILE *f = fopen("dados/cotacao.txt","r");
    if(f == NULL){
        printf("Erro ao abrir arquivo banco");
        return;
    }
    if(fscanf(f,"Bitcoin %lf\nEthereum %lf\nRipple %lf",&cbtc,&ceth,&cxrp) == 3){ // Alterado para %lf
        printf("Cotacao por unidade de criptos em R$:\nBitcoins - R$ %.2f\nEthereum - R$ %.2f\nRipple - R$ %.2f\n\n",cbtc,ceth,cxrp);
    }else{
        printf("erro ao ler as cotas");
        return;
    };
    fclose(f);
    
    FILE *f2 = fopen("dados/banco.txt", "r");
    if (f2 == NULL) {
        printf("Erro ao abrir arquivo banco para leitura.\n");
        return;
    }
    if (fscanf(f2, "Reais %lf\nBitcoin %lf\nEthereum %lf\nRipple %lf", &reais, &btc, &eth, &xrp) != 4) { // Alterado para %lf
        printf("2. Erro ao ler formato do arquivo.\n");
        fclose(f2);
        return;
    }
    fclose(f2);    
    
    if(select == 1){
        printf("Comprar criptomoeda\ninsira cripto que deseja comprar:\n");
        int buyop = 0;
        double valor = 0.0;
        double antvalor = 0.0;
        double taxa = 0.0;
        double cripto_convert;
        do{
            printf("1 - Bitcoin\n2 - Ethereum\n3 - Ripple\n0 - Sair\n: ");
            scanf("%d", &buyop);
            if(buyop == 0 || buyop > 3){
            	printf("Saindo...");
				return;
			}
            printf("Valor de compra: ");
            scanf("%20lf", &valor); 
            antvalor = valor;
            
            if( reais-valor < 0 ){
                printf("Valor ultrapassado, insiria valor valido!");
                return;
            }
            
            switch (buyop){
            case 1:
                strcpy(moeda, "btc");
                printf("Selecionado %d %s\n",buyop, moeda);
                taxa = 2.0;
                valor = valor - taxa_porcentual(valor,taxa,1);
                cripto_convert = valor / cbtc; // converte o valor real inserido em BTC de acordo com a cotação atual
                reais = reais - valor; // atualiza o valor real no depósito;
                btc = btc + cripto_convert; // atualiza a cripto na carteira;
				printf("Aplicando a taxa de 2 %% que resulta em: %.2f\n%.8f de %s aplicado na carteira\n",valor,cripto_convert,moeda);
                atualizar_extrato("+",antvalor,moeda,cripto_convert,taxa,reais,btc,eth,xrp,select);
                break;
            case 2:
                printf("Selecionado %d eth:\n",buyop);
                strcpy(moeda, "eth");
				taxa = 1.0;
                valor = valor - taxa_porcentual(valor,taxa,1);
                cripto_convert = valor / ceth; // converte o valor real inserido em BTC de acordo com a cotação atual
                reais = reais - valor; // atualiza o valor real no depósito;
                eth = eth + cripto_convert; // atualiza a cripto na carteira;
				printf("Aplicando a taxa de 2 %% que resulta em: %.2f\n%.8f de %s aplicado na carteira\n",valor,cripto_convert,moeda);
                atualizar_extrato("+",antvalor,moeda,cripto_convert,taxa,reais,btc,eth,xrp,select);
                
                break;
            case 3:
                printf("Selecionado %d:\n",buyop);
                strcpy(moeda, "xrp");
                taxa = 1.0;
                valor = valor - taxa_porcentual(valor,taxa,1);
                cripto_convert = valor / cxrp; // converte o valor real inserido em BTC de acordo com a cotação atual
                reais = reais - valor; // atualiza o valor real no depósito;
                xrp = xrp + cripto_convert; // atualiza a cripto na carteira;
				printf("Aplicando a taxa de 2 %% que resulta em: %.2f\n%.8f de %s aplicado na carteira\n",valor,cripto_convert,moeda);
                atualizar_extrato("+",antvalor,moeda,cripto_convert,taxa,reais,btc,eth,xrp,select);
                break;
            }
                // NOTE: Sei que daria para fazer compactado, transformar essas funções, mas devido ao tempo, e necessidade de raciocínio deixarei assim no momento
        }while(buyop != 0);
    }
    
    if(select == 2){
    	printf("Vender criptomoeda\ninsira cripto que deseja vender:\n");
        int sellop = 0;
        double valor = 0.0;
        double taxa = 0.0;
        double cripto_convert;
        double valorc_taxa;
        do{
            printf("1 - Bitcoin\n2 - Ethereum\n3 - Ripple\n0 - Sair\n: ");
            scanf("%d", &sellop);
            if(sellop == 0 || sellop > 3){
            	printf("Saindo...");
				return;
			}
            switch (sellop){
	            case 1:
	                strcpy(moeda, "btc");
	                printf("Selecionado %d %s\n",sellop, moeda);
	                taxa = 3.0;
	                printf("Bitcoin disponível para vender: %lf\n deseja vender quanto?\n: ",btc);
	                scanf("%lf",&valor);
	                if(btc-valor<0){
	                	printf("Insira quantia valida!");
	                	break;
					}
	                
					cripto_convert = valor * cbtc; // converte o valor em real bruto inserido em BTC de acordo com a cotação atual
					printf("Valor inserido para vender %lf\n Conversao para real (bruto): %.2f\n",valor, cripto_convert);
					valorc_taxa = cripto_convert-taxa_porcentual(cripto_convert,taxa,1); // aplicando a taxa, introduzindo valor liquido
					reais = valorc_taxa + reais; // novo valor total liquido somando com o total na carteira
					btc = btc - valor; // atualiza a cripto na carteira;
					printf("valor reais com taxa 3%%: %.2f\nreais liquido: %.2f\nbtc: %lf\n",valorc_taxa,reais,btc); 
					atualizar_extrato("+",valorc_taxa,moeda,valor,taxa,reais,btc,eth,xrp,select);
	                
	                break;
	            case 2:
	                printf("Selecionado %d eth:\n",sellop);
	                strcpy(moeda, "eth");
	                taxa = 2.0;
	                printf("Ethereum disponível para vender: %lf\n deseja vender quanto?\n: ",eth);
	                scanf("%lf",&valor);
	                if(eth-valor<0){
	                	printf("Insira quantia valida!");
	                	break;
					}
	                
					cripto_convert = valor * ceth; // converte o valor em real bruto inserido em BTC de acordo com a cotação atual
					printf("Valor inserido para vender %lf\n Conversao para real (bruto): %.2f\n",valor, cripto_convert);
					valorc_taxa = cripto_convert-taxa_porcentual(cripto_convert,taxa,1); // aplicando a taxa, introduzindo valor liquido
					reais = valorc_taxa + reais; // novo valor total liquido somando com o total na carteira
					eth = eth - valor; // atualiza a cripto na carteira;
					printf("valor reais com taxa 3%%: %.2f\nreais liquido: %.2f\neth: %lf\n",valorc_taxa,reais,eth); 
					atualizar_extrato("+",valorc_taxa,moeda,valor,taxa,reais,btc,eth,xrp,select);
					
	                break;
	            case 3:
	                printf("Selecionado %d:\n",sellop);
	                strcpy(moeda, "xrp");
	                taxa = 1.0;
	                printf("Ripple disponível para vender: %lf\n deseja vender quanto?\n: ",xrp);
	                scanf("%lf",&valor);
	                if(xrp-valor<0){
	                	printf("Insira quantia valida!");
	                	break;
					}
	                
					cripto_convert = valor * cxrp; // converte o valor em real bruto inserido em BTC de acordo com a cotação atual
					printf("Valor inserido para vender %lf\n Conversao para real (bruto): %.2f\n",valor, cripto_convert);
					valorc_taxa = cripto_convert-taxa_porcentual(cripto_convert,taxa,1); // aplicando a taxa, introduzindo valor liquido
					reais = valorc_taxa + reais; // novo valor total liquido somando com o total na carteira
					xrp = xrp - valor; // atualiza a cripto na carteira;
					printf("valor reais com taxa 3%%: %.2f\nreais liquido: %.2f\nxrp: %lf\n",valorc_taxa,reais,xrp); 
					atualizar_extrato("+",valorc_taxa,moeda,valor,taxa,reais,btc,eth,xrp,select);
	                break;
	        }
	}while(sellop != 0);
}
}

//double convercao_cripto();

double taxa_porcentual(double valor, double taxa,int select){ // area para calcular a taxa de compra das criptomoedas
    if(select == 1){
    double resultado = 0.0;
    resultado = (valor * taxa) / 100.0;
    return resultado;
    }    
    return 0.0;
}

int atualizar_extrato(char acao[2],double deposito,char moeda[10],double ct,double tx,double real,double btc,double eth,double xrp,int select){
  
    FILE *f = fopen("dados/banco.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir arquivo banco.txt para escrita.\n");
        return 0;
    }

    if (fprintf(f, "Reais %.2f\nBitcoin %.8f\nEthereum %.2f\nRipple %.2f", real, btc, eth, xrp) < 0) {
        printf("Erro ao inserir saldo em arquivo.\n");
    } else {
        printf("%s realizado com sucesso!\n", select == 1 ? "Deposito": "Saque");
        if(select == 2){
            printf("Novo saldo: %.2f\n",real);
        }
    }
    
    fclose(f);
    
    FILE *ext = fopen("dados/extratos.txt","a");
    
    time_t tempo_atual = time(NULL); // pesquisado no google como capturar o tempo e horario atual
    struct tm *info_tempo = localtime(&tempo_atual);
    
    fprintf(ext,"%02d-%02d-%d %02d:%02d %s %.2f %s CT: %f\tTX: %.2f REAL: %.2f BTC: %.8f ETH: %.2f XRP: %.2f\n",
        info_tempo->tm_mday, 
        info_tempo->tm_mon + 1,      // Meses vão de 0 a 11
        info_tempo->tm_year + 1900, // Anos contados a partir de 1900
        info_tempo->tm_hour, 
        info_tempo->tm_min, 
        acao,
        deposito,
        moeda,
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

void atualizar_cotacao() {
    double cbtc = 0.0, ceth = 0.0, cxrp = 0.0;

    // 1. Abre o arquivo para ler as cotações atuais
    FILE *f = fopen("dados/cotacao.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir arquivo de cotacao para leitura.\n");
        return;
    }

    if (fscanf(f, "Bitcoin %lf\nEthereum %lf\nRipple %lf", &cbtc, &ceth, &cxrp) != 3) {
        printf("Erro ao ler as cotacoes atuais.\n");
        fclose(f);
        return;
    }
    fclose(f);

    // 2. Calcula a variacao aleatoria entre -5% e +5%
    // (rand() % 1001 - 500) gera números entre -500 e 500. 
    // Dividindo por 10000.0, obtemos um multiplicador entre -0.05 e 0.05
    double var_btc = (rand() % 1001 - 500) / 10000.0;
    double var_eth = (rand() % 1001 - 500) / 10000.0;
    double var_xrp = (rand() % 1001 - 500) / 10000.0;

    // 3. Aplica a variacao aos valores
    cbtc = cbtc + (cbtc * var_btc);
    ceth = ceth + (ceth * var_eth);
    cxrp = cxrp + (cxrp * var_xrp);

    // 4. Salva as novas cotações sobrescrevendo o arquivo
    f = fopen("dados/cotacao.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir arquivo de cotacao para escrita.\n");
        return;
    }

    fprintf(f, "Bitcoin %lf\nEthereum %lf\nRipple %lf", cbtc, ceth, cxrp);
    fclose(f);

    printf("\n--- Cotacoes atualizadas com sucesso! ---\n");
    printf("Novos valores (variacao de ate +- 5%%):\n");
    printf("Bitcoin  - R$ %.2f\n", cbtc);
    printf("Ethereum - R$ %.2f\n", ceth);
    printf("Ripple   - R$ %.2f\n\n", cxrp);
}
