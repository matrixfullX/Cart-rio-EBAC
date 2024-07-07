#include <stdio.h>//biblioteca de comunicaçao com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memoria
#include <locale.h>//biblioteca de alocações de texto região
#include <string.h>//biblioteca responsável por cuidar dos strings

int registro() //função responsável por cadastrar os usuários do sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF a Ser Cadastrado"); //coletando informação do usuário
	scanf("%S",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //abre o arquivo e escreve e o "w" significa escrever
	fprintf(file,cpf);//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo e 
	fprintf(file,","); // salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o Nome a Ser Cadastrado : "); //coletando informações do usuário
	scanf("%s",nome); //refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo e 
	fprintf(file,nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo e 
	fprintf(file,","); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o Sobrenome a Ser Cadastrado : "); //coletando informação do usuário
	scanf("%s",sobrenome); //refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo e 
	fprintf(file,sobrenome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo e 
	fprintf(file,","); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o Cargo a Ser Cadastrado : "); ////coletando informação do usuário
	scanf("%s",cargo); //refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo e 
	fprintf(file,cargo);//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	system("pause"); //pausa a menu para decisão do usuário
}
int consultar() //função responsável por consultar os usuários do sistema
{
	//início da consulta de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final consulta de variáveis/string
	
	printf("Digite o CPF a Ser Consultado : "); //buscando informações do usuário
	scanf("%s",cpf); //refere-se a variável/string e o "%s" significa a string
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e ler e o "r" sigmifica ler
	
	if(file == NULL) //função responsável para quando as informações solicitadas estiverem erradas
	
	{
		printf("Não Foi Possível Abrir o Arquivo , Naõ Localizado !.\n"); //erro de informações erradas consultadas
	}
	
	while(fgets(conteudo,200,file)!= NULL) //função de respostas consultadas
	{
		printf("\nEssas São As Informações Do Usuário : "); //respostas seguintes de informações consultadas
		printf("%s",conteudo); //refere-se a variável
		printf("\n\n");
	}
	system("pause"); //pausa a menu para decisão do usuário
}
int deletar() //função respomsável por deletar os usuários do sistema
{
    //início de consulta para ser deletado
	char cpf[40];
	//final de consulta para ser deletado
	
	printf("Digite o CPF a Ser Deletado : "); //buscando informações do usuário
	scanf("%s",cpf); //refere-se a string
	
	remove(cpf); //função responsável por remover usuários do sistema
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e ler
	
	if(file == NULL) //função responsável para quando as informações solicitadas estiverem erradas
	{
		printf("O Usuário Não Se Encontra No Sistema ! .\n"); //erro de informações erradas consultadas
		system("pause"); //pausa a menu para decisão do usuário
	}
}

int main () //define as opções
{
	int opcao=0;//Definindo Variáveis
	int laco=1; //definindo laco
	
	for (laco=1;laco=1;) //
	{
		
		system("cls"); //reponsável por limpar a tela
    	
	    setlocale(LC_ALL,"Portuguese");//Definindo Linguagem
	    
	    //Inicio Do Menu
        printf("### Cartorio Da EBAC ###\n\n");
	    printf("Escolha a opçao desejada no menu\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n\n");
	    printf("\t4 - Sair Do Sistema\n\n");
	    printf("Opção : ");
	    //Fim Do Menu
	    
	    scanf("%d",&opcao);//Armazenando a Escolha Do Usuário
	    
	    system("cls"); //responsável por limpar a tela
	    
	    switch(opcao) //função responsável para decisão do usuário
	    {
	    	//inicio da seleção do menu
	    	case 1: //numeração da função
	    	registro(); //chamada de funções
	    	break; //fim de função
	    	
	    	case 2: //numeração da funçaõ
	        consultar(); //numeração da função
	    	break; //fim de função
	    	
	    	case 3: //numeração da função
	    	deletar(); //chamada de funções
   	     	break; //fim de função
   	     	
   	     	case 4:
   	     	printf("Obrigado Por Usar o Sistema !\n");
   	     	return 0;
   	     	break;
   	  	
   	     	default: //função respomsável para quando a opção decidida não estiver disponível no menu
   	    	printf("Essa Opcao Nao Esta Disponivel !\n"); //erro de opção errada escolhida
			system("pause"); //pausa a menu para decisão do usuário
			break; //final de função
			//fim da seleção
		} 
    }
}
