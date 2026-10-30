#include <stdio.h>
#include <stdlib.h>
#include <string.h> // biblioteca para utilizar o strcmp() para compara duas strings (atualizado: Programa necessario no momento, pois, vai ser necessario se eu utilizar email ou nome de usuario para comparar os 2 progrmaas.

int menu_login();
int d = 0;
void plataform_acess(); // definindo a funcao;
void op1();


int main(){
    
    if(menu_login()==1){
        //printf("%d true", menu_login());
        plataform_acess();
    }else{
        printf("tente novamente:\n");
        (menu_login()) ? plataform_acess() : printf("Limite ultrapassado, tente novamente reabrindo o programa"); // aplicado a operacao ternario para analisar o returno da funcao menu_login.
        return 0;
    }
    return 0;
}

int menu_login(){
    
    // aba para realizar leitura do usuario no arquivo
    FILE *f = fopen("dados/usuario.txt","r"); // abrindo o arquivo
    if(f == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    char cpf[12]; // aplicar cpf aqui.
    char senha[7]; // ateh 6 digitos.    
    char nomec[60];
    if(fscanf(f,"%s %s %[^\n]", cpf,senha,nomec) == 3){; // [^\n] -> vai realizar leituras dos nomes ate encontrar o final da linha e armazenar na variavel
    //printf("CPF: %s \nSenha: %s \nNome: %s\n",cpf,senha,nomec);
    char dcpf[12];
    char dsenha[7] = "";
    printf("---Aba de login---\n");
    printf("Usuario: ");
    scanf("%12s", &dcpf); // %12s limite ateh 12 digitos, para evitar stack overflow.
    
    if(strcmp(cpf,dcpf) == 0){ // comparar 2 valores, entre o input do usuario e dados armazenado no arquivo    
        printf("Ola\n",nomec);
        printf("Senha (numeros): ");
        scanf("%6s", &dsenha );    
        if(strcmp(senha,dsenha) == 0){
            // armazenar os dados de usuario em ponteiros de memoria para reutilizar em outras funcoes            
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }        
    }else{
        printf("Nada bom");
    }
    fclose(f);


}

void plataform_acess(){
    int option = 0;
    printf("\n---Bem vindo a plataforma bitbolt!---\n");
    printf("\n\nProximo passo:\n");
    printf("\n1. Consultar saldo\n2. Consultar extrato\n3. Depositar\n4. Sacar\n5. Comprar criptomoedas\n6. Vender criptomoedas\n7. Atualizar cotacao\n8. Sair\n: ");
    scanf("%1i",&option);
    if ( option <= 0 || option >= 8 ){
        main(); // retorna para pagina principal
    }else{
        switch(option){ // utilizar o switch pois as opcao sao de casos
        case 1: printf("Opcao 1 selecionada\n"); op1(); break;
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

void op1(){
    // depois, realizar manutencao para que o programa leia os arquivos e armazenar na variavel, por enquanto as variaveis serao definidas por aqui

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
        //exibicao de dados, aplicar verificacao por senhas antes de realmente fazer os dados aparecer;
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

void op2(){
    // depois, realizar manutencao para que o programa leia os arquivos e armazenar na variavel, por enquanto as variaveis serao definidas por aqui

    char nome[20] = "Igor Reis";
    char cpf[20] = "123.456.789-00";
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
        //exibicao de dados, aplicar verificacao por senhas antes de realmente fazer os dados aparecer;
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
