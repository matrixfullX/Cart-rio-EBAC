#include <stdio.h>//biblioteca de comunica�ao com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em memoria
#include <locale.h>//biblioteca de aloca��es de texto regi�o
#include <string.h>//biblioteca respons�vel por cuidar dos strings

int registro() //fun��o respons�vel por cadastrar os usu�rios do sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a Ser Cadastrado"); //coletando informa��o do usu�rio
	scanf("%S",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //abre o arquivo e escreve e o "w" significa escrever
	fprintf(file,cpf);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo e 
	fprintf(file,","); // salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o Nome a Ser Cadastrado : "); //coletando informa��es do usu�rio
	scanf("%s",nome); //refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo e 
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo e 
	fprintf(file,","); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o Sobrenome a Ser Cadastrado : "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); //refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo e 
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo e 
	fprintf(file,","); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o Cargo a Ser Cadastrado : "); ////coletando informa��o do usu�rio
	scanf("%s",cargo); //refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo e 
	fprintf(file,cargo);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	system("pause"); //pausa a menu para decis�o do usu�rio
}
int consultar() //fun��o respons�vel por consultar os usu�rios do sistema
{
	//in�cio da consulta de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final consulta de vari�veis/string
	
	printf("Digite o CPF a Ser Consultado : "); //buscando informa��es do usu�rio
	scanf("%s",cpf); //refere-se a vari�vel/string e o "%s" significa a string
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e ler e o "r" sigmifica ler
	
	if(file == NULL) //fun��o respons�vel para quando as informa��es solicitadas estiverem erradas
	
	{
		printf("N�o Foi Poss�vel Abrir o Arquivo , Na� Localizado !.\n"); //erro de informa��es erradas consultadas
	}
	
	while(fgets(conteudo,200,file)!= NULL) //fun��o de respostas consultadas
	{
		printf("\nEssas S�o As Informa��es Do Usu�rio : "); //respostas seguintes de informa��es consultadas
		printf("%s",conteudo); //refere-se a vari�vel
		printf("\n\n");
	}
	system("pause"); //pausa a menu para decis�o do usu�rio
}
int deletar() //fun��o respoms�vel por deletar os usu�rios do sistema
{
    //in�cio de consulta para ser deletado
	char cpf[40];
	//final de consulta para ser deletado
	
	printf("Digite o CPF a Ser Deletado : "); //buscando informa��es do usu�rio
	scanf("%s",cpf); //refere-se a string
	
	remove(cpf); //fun��o respons�vel por remover usu�rios do sistema
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e ler
	
	if(file == NULL) //fun��o respons�vel para quando as informa��es solicitadas estiverem erradas
	{
		printf("O Usu�rio N�o Se Encontra No Sistema ! .\n"); //erro de informa��es erradas consultadas
		system("pause"); //pausa a menu para decis�o do usu�rio
	}
}

int main () //define as op��es
{
	int opcao=0;//Definindo Vari�veis
	int laco=1; //definindo laco
	
	for (laco=1;laco=1;) //
	{
		
		system("cls"); //repons�vel por limpar a tela
    	
	    setlocale(LC_ALL,"Portuguese");//Definindo Linguagem
	    
	    //Inicio Do Menu
        printf("### Cartorio Da EBAC ###\n\n");
	    printf("Escolha a op�ao desejada no menu\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n\n");
	    printf("\t4 - Sair Do Sistema\n\n");
	    printf("Op��o : ");
	    //Fim Do Menu
	    
	    scanf("%d",&opcao);//Armazenando a Escolha Do Usu�rio
	    
	    system("cls"); //respons�vel por limpar a tela
	    
	    switch(opcao) //fun��o respons�vel para decis�o do usu�rio
	    {
	    	//inicio da sele��o do menu
	    	case 1: //numera��o da fun��o
	    	registro(); //chamada de fun��es
	    	break; //fim de fun��o
	    	
	    	case 2: //numera��o da fun�a�
	        consultar(); //numera��o da fun��o
	    	break; //fim de fun��o
	    	
	    	case 3: //numera��o da fun��o
	    	deletar(); //chamada de fun��es
   	     	break; //fim de fun��o
   	     	
   	     	case 4:
   	     	printf("Obrigado Por Usar o Sistema !\n");
   	     	return 0;
   	     	break;
   	  	
   	     	default: //fun��o respoms�vel para quando a op��o decidida n�o estiver dispon�vel no menu
   	    	printf("Essa Opcao Nao Esta Disponivel !\n"); //erro de op��o errada escolhida
			system("pause"); //pausa a menu para decis�o do usu�rio
			break; //final de fun��o
			//fim da sele��o
		} 
    }
}
