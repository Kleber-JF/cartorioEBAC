#include <stdio.h> // biblioteca de comunica��o com o us�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca por cuidar das strings

int registro()
{
	// inicio cria��o das vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); // inicio do registro
	scanf("%s", cpf); // coletando informa��o do usu�rio e armazenando em uma string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file= fopen(arquivo, "w"); // abre o arquivo e "escreve" no arquivo.
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); // escreve "," no arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome); // coletando informa��o do usu�rio e armazenando em uma string
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,nome); // escreve a string "nome" no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); // escreve "," no arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,sobrenome); // escreve a string "sobrenome" no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); // escreve "," no arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,cargo); // escreve a string "cargo" no arquivo
	fclose(file); // fecha o arquivo
	
	system("pause"); // espera a confirma��o para continuar executando o programa. //final do registro
	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // definindo o idioma
	
	// inicio da cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	// final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser consultado: ");// inicio da consulta de nomes
	scanf("%s",cpf); //coletando informa��o do usu�rio e armazenando em uma string
	
	FILE *file;
	file = fopen(cpf,"r"); // abre o arquivo e "l�" as informa��es
	
	if(file == NULL) // condi��o se n�o for encontrado o valor da vari�vel digital no arquivo
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // condi��o se a vari�vel digital for encontrada. Tras a informa��o de at� 200 caracteres.
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // fim da consulta

}
int deletar()
{
	char cpf[40]; // cria��o da vari�vel/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // inicio da dele��o de cadastro
	scanf("%s", cpf); //coletando informa��o do usu�rio e armazenando em uma string
	
	remove( cpf); // remove o arquivo contendo a informa��o armazenada na string.
	
	FILE *file;
	file = fopen( cpf,"r");
	
	if(file == NULL) // condi��o se a string n�o for encontrada
	{
		printf("O usu�rio n�o foi encontrado no sistema! \n");	
	}
	
	system("pause"); // fim da dele��o de cadastros
	
}



int main()
	{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	// determinando loop de execu��o do programa (quantas vezes o programa vai rodar, nesse caso, indefinidamente)
	{
	
		system("cls"); // limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); // definindo o idioma
		
		printf("### Cart�rio da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Resgistrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Digite o n�mero da op��o desejada e aperte ENTER: "); // final do menu
		
		scanf("%d" , &opcao); // armazenando a escolha do usu�rio
		
		system("cls"); // limpa a tela
		
		
		switch(opcao) //inicio da sele��o
		{
			case 1: // caso o usu�rio digite 1
			registro(); // roda a fun��o registro
			break; // pausa 1 vez o programa
			
			case 2: // caso o usu�rio digite 2
			consulta();// roda a fun��o consulta
			break; // pausa 1 vez o programa
			
			case 3: // caso o usu�rio digite 3
			deletar();// roda a fun��o deletar
			break; // pausa 1 vez o programa
			
			case 4: // caso o usu�rio digite 4
			printf("Obrigado por utilizar nosso sistema!\n");
			return 0;// fecha o programa
			break; // pausa 1 vez o programa
			
			default: // caso o usu�rio digite qualquer outro caracter
			printf("Essa op��o n�o est� dispon�vel!\n\n");
			system("pause");// pausa 1 vez o programa
			break; //final da sele��o
				
		}
		
	
}
}
