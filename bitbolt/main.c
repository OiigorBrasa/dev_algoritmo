#include <stdio.h>
#include <stdlib.h>
#include <string.h> // biblioteca para utilizar o strcmp() para comparar duas strings (atualizado: Programa necessario no momento, pois, vai ser necessario se eu utilizar email ou nome de usuario para comparar os 2 programas.

int menu_login(char cpf[12], char senha[7], char nomec[60]);
int d = 0;
void plataform_acess(char cpf[12], char senha[7], char nomec[60]); // definindo a funcao;
void op1(char cpf[12], char senha[7], char nomec[60]);
void op2(), op3(), op4(), op5(), op6();
void dados_banco(char cpf[12], int select);

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
    printf("\n---Bem vindo a plataforma bitbolt!---\n");
    printf("\n\nProximo passo:\n");
    printf("\n1. Consultar saldo\n2. Consultar extrato\n3. Depositar\n4. Sacar\n5. Comprar criptomoedas\n6. Vender criptomoedas\n7. Atualizar cotacao\n8. Sair\n: ");
    scanf("%1i", &option);

    if (option <= 0 || option >= 8) {
        	printf("Nenhuma opcao da lista selecionada"); // retorna para pagina principal
    } else {
        switch (option) { // utilizar o switch pois as opcao sao de casos
        case 1:
            printf("Opcao 1 selecionada\n");
            op1(cpf, senha, nomec);
            break;
        case 2:
            printf("Opcao 2 selecionada\n");
            break;
        case 3:
            printf("Opcao 3 selecionada\n");
            break;
        case 4:
            printf("Opcao 4 selecionada\n");
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
        default:
            printf("Opcao invalida");
            break;
        }
    }
}

void op1(char cpf[12], char senha[7], char nomec[60]) {
    // depois, realizar manutencao para que o programa leia os arquivos e armazenar na variavel, por enquanto as variaveis serao definidas por aqui
    int select = 0;
    char dsenha[7];

    printf("Senha (numeros): ");
    scanf("%6s", dsenha);
    printf("\n");

    if (strcmp(senha, dsenha) == 0) {
        // exibicao de dados, aplicar verificacao por senhas antes de realmente fazer os dados aparecer;
        printf("Nome: %s\n", nomec);
        printf("Cpf: %s\n\n", cpf);
        dados_banco(cpf, select = 1);
    } else {
        printf("Senha incorreta!");
    }
}

void dados_banco(char cpf[12], int select) {
    if (select == 1) {
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
}
