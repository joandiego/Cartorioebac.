#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w"  significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a"  significa escrever
	fprintf(file,","); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a"  significa escrever
	fprintf(file,nome); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a"  significa escrever
	fprintf(file,","); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a"  significa escrever
	fprintf(file,sobrenome); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a"  significa escrever
	fprintf(file,","); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a"  significa escrever
	fprintf(file,cargo); // salvo o valor da variavel
	fclose(file);// fecha o arquivo
	
	system("pause");
	
	
		
}

int consultar() //Função responsavel por consultar os usuários no sistema
{
	//inicio consulta de variáveis/string
    setlocale(LC_ALL, "Portuguese"); //Definindo a línguagem
    
    char cpf[40];
    char conteudo[200];
    //Final da consulta de variáveis/string
   
    printf("Digite o CPF a ser consultado: "); //consultando informações do usuário
    scanf("%s",cpf); //%s refere-se a string
    
    FILE *file; // consultar o arquivo
    file = fopen(cpf,"r"); // consultar o CPF e o "r"  significa escrever
    
    if(file == NULL)
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    }

        while(fgets(conteudo, 200, file) != NULL)
        {
        	printf("\nEssas são as informações do usuário: ");
        	printf("%s", conteudo);
        	printf("\n\n");
		}
		system("pause");
}

int deletar() //Função responsavel por deletar os usuários no sistema
{
	//inicio deleta de variáveis/string
	char cpf[40];
	//Final de deleta de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //deletando informações do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file; // deletar o arquivo
	file = fopen(cpf,"r"); // deletar o CPF e o "r"  significa escrever
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
		
	}
	
	
}


int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a línguagem
	
    	printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n\n");
	    printf("\t2 - Consultar nomes\n\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Opção: ");//fim do menu
		
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	
	    system("cls"); //responsavel por limpar a tela
	    
	    
	    switch(opcao) //inicio da seleção do menu
	    {
	    	case 1:
	        registro(); //chamada de funçôes
			break;
			
			case 2:
			consultar();
		    break;
		    	
		   	case 3:
		    deletar();	
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
		    
		    default:
		    printf("Essa opção não está disponivel!\n");
		    system("pause");
			break;	
			// fim da seleção	
		}
	    
	
	
    }
}
