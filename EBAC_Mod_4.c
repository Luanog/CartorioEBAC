#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);

	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

	FILE *fp; // cria o arquivo
	fp = fopen(arquivo, "w"); // cria o arquivo
	fprintf(fp,cpf); // salvo o valor da variavel
	fclose(fp); // fecha o arquivo

	fp = fopen(arquivo, "a");
	fprintf(fp,"\n");
	fclose(fp);

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);

	fp = fopen(arquivo, "a");
	fprintf(fp,nome);
	fclose(fp);

	fp = fopen(arquivo, "a");
	fprintf(fp,"\n");
	fclose(fp);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);

	fp = fopen(arquivo, "a");
	fprintf(fp,sobrenome);
	fclose(fp);

	fp = fopen(arquivo, "a");
	fprintf(fp,"\n");
	fclose(fp);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);

	fp = fopen(arquivo, "a");
	fprintf(fp,cargo);
	fclose(fp);

    getchar();

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");

	char cpf[200];
	char conteudo [200];

	printf("Digite o CPF a ser consultado: ");
    scanf("%S",cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        printf("CPF não encontrado!\n");

    }

     system("clear");


    while(fgets(conteudo, 200, file) != NULL )
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    getchar();
}

int deletar()
{
	printf("Você escolheu deletar nomes!\n");
	getchar();
}



int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;

	for(laco=1;laco=1;)
	{


		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");//fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usuário

		system("clear");

		switch(opcao) //inicio da seleção
		{
			case 1:
			registro();
			break;

			case 2:
			consulta();
			break;

			case 3:
			deletar();
			break;

			default:
			printf("Essa opçao não está disponivel!\n");
			getchar();
			break;
		} //fim da seleção

	}
}
