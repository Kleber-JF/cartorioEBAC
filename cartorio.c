#include <stdio.h> // biblioteca de comunicação com o usário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca por cuidar das strings

int registro()
{
	// inicio criação das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); // inicio do registro
	scanf("%s", cpf); // coletando informação do usuário e armazenando em uma string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file= fopen(arquivo, "w"); // abre o arquivo e "escreve" no arquivo.
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,","); // escreve "," no arquivo
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome); // coletando informação do usuário e armazenando em uma string
	
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
	
	system("pause"); // espera a confirmação para continuar executando o programa. //final do registro
	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // definindo o idioma
	
	// inicio da criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	// final da criação de variáveis/strings
	
	printf("Digite o CPF a ser consultado: ");// inicio da consulta de nomes
	scanf("%s",cpf); //coletando informação do usuário e armazenando em uma string
	
	FILE *file;
	file = fopen(cpf,"r"); // abre o arquivo e "lê" as informações
	
	if(file == NULL) // condição se não for encontrado o valor da variável digital no arquivo
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // condição se a variável digital for encontrada. Tras a informação de até 200 caracteres.
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // fim da consulta

}
int deletar()
{
	char cpf[40]; // criação da variável/string
	
	printf("Digite o CPF do usuário a ser deletado: "); // inicio da deleção de cadastro
	scanf("%s", cpf); //coletando informação do usuário e armazenando em uma string
	
	remove( cpf); // remove o arquivo contendo a informação armazenada na string.
	
	FILE *file;
	file = fopen( cpf,"r");
	
	if(file == NULL) // condição se a string não for encontrada
	{
		printf("O usuário não foi encontrado no sistema! \n");	
	}
	
	system("pause"); // fim da deleção de cadastros
	
}



int main()
	{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	// determinando loop de execução do programa (quantas vezes o programa vai rodar, nesse caso, indefinidamente)
	{
	
		system("cls"); // limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); // definindo o idioma
		
		printf("### Cartório da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Resgistrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Digite o número da opção desejada e aperte ENTER: "); // final do menu
		
		scanf("%d" , &opcao); // armazenando a escolha do usuário
		
		system("cls"); // limpa a tela
		
		
		switch(opcao) //inicio da seleção
		{
			case 1: // caso o usuário digite 1
			registro(); // roda a função registro
			break; // pausa 1 vez o programa
			
			case 2: // caso o usuário digite 2
			consulta();// roda a função consulta
			break; // pausa 1 vez o programa
			
			case 3: // caso o usuário digite 3
			deletar();// roda a função deletar
			break; // pausa 1 vez o programa
			
			case 4: // caso o usuário digite 4
			printf("Obrigado por utilizar nosso sistema!\n");
			return 0;// fecha o programa
			break; // pausa 1 vez o programa
			
			default: // caso o usuário digite qualquer outro caracter
			printf("Essa opção não está disponível!\n\n");
			system("pause");// pausa 1 vez o programa
			break; //final da seleção
				
		}
		
	
}
}
