#include<stdio.h>
#include<stdlib.h>

int Login(){
	int X=1;
	char Login[100], Senha[100],Login_Admin[100]="Pericles_admin", Login_User[100]="Pericles_user", Pass[100]="Queremos10";
	do{
		printf("Digite seu usuário: ");
		gets(Login);#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char NOME[200], DURACAO[20], EP[50], TEMP[50], DESC[10000], AVAL[4];
	int FS;//Var caso seja Filme = 1, S�rie = 0
}LIBRARY;

LIBRARY produto[100];
int quant=0;

//Login
int Login(){
	int X=1;
	char Login[100], Senha[100],Login_Admin[100]="Pericles_admin", Login_User[100]="Pericles_user", Pass[100]="Queremos10";

	do{
		printf("Digite seu usuario: ");
		gets(Login);
		printf("Digite sua senha: ");
		gets(Senha);
		if(strcmp(Login,Login_Admin)==0){
			if(strcmp(Senha,Pass)==0){
				return(1);
			}
		}
		else if(strcmp(Login, Login_User)==0){
			if(strcmp(Senha,Pass)==0){
				return(2);
			}
		}
		else{
			system("CLS");
			printf("Login errado ou senha errada, tente novamente.\n");
		}
	}while(X==1);
}

//Menu inicial
int IncMenu(){
	int Menu;
	do{
		printf("O que deseja fazer?\n1)Verificar o catalogo.\n2)Adicionar produto no catalogo.\n3)Editar catalogo.\n4)...\n5)Fechar programa.");
		scanf("\n%i", &Menu);
	}while(Menu<=0 || Menu>5);
	return Menu;
}

//Adi��o de produto no cat�logo
void library_add(){
	int i;
	char descarte;
	do{
		quant++;
		printf("O seu produto e filme(1) ou serie(2)?");
		scanf("%i", &i);

		if(i==1){//filme
			system("CLS");
			scanf("%c", &descarte);
			printf("Digite o nome do seu filme: ");
			gets(produto[quant].NOME);
			printf("\nDigite a duracao do seu filme: ");
			gets(produto[quant].DURACAO);
			printf("\nCrie uma descricao para o filme: ");
			gets(produto[quant].DESC);
			break;
		}
		else if(i==2){//s�rie
			system("CLS");
			scanf("%c", &descarte);
			printf("Digite o nome do seu serie: ");
			gets(produto[quant].NOME);
			printf("\nDigite o numero de temporadas que a serie possui: ");
			gets(produto[quant].TEMP);
			printf("\nCrie uma descricao para a serie: ");
			gets(produto[quant].DESC);
			break;
		}
		else{
			printf("Valor invalido");
		}
	}while(i>0);
}

//Visualiza��o do cat�logo
void library_Vis(){
	int catalogo, i, loop;
	do{
		printf("Escolha o produto do catalogo para ver:");
		for(i=1;i<=quant;i++){
			printf("%i)%s", i, produto[i].NOME);
		}		
		scanf("\n%i", &catalogo);
		if(catalogo>=1 && catalogo<=4){
			//caso seja s�rie
			int FS=1;
			if(FS==0){
				printf("Titulo:%s\nTemporadas:%s\nAvaliacao:%s\nDescricao:%s\n", produto[catalogo].NOME[200], produto[catalogo].TEMP[50], produto[catalogo].AVAL[4], produto[catalogo].DESC[10000] );
			}

			//caso seja longa(filme, document�rio,...)
			if(FS==1){
				printf("Titulo:%s\nDuracao:%s\nAvaliacao:%s\nDescricao:%s\n", produto[catalogo].NOME[200], produto[catalogo].DURACAO[20] , produto[catalogo].AVAL[4], produto[catalogo].DESC[10000]);
			}
		}
	}while(loop==1);
}

main(){
	int X=1,i;
	Login();
	do{
		system("CLS");
		int LogMain=IncMenu();
		if(LogMain==1){//Verificar catalogo
			system("CLS");
			library_Vis();
			system("CLS");
		}
		else if(LogMain==2){//Adicionar produto no catalogo
			system("CLS");
			library_add();
			system("CLS");
		}
		else if(LogMain==3){
			system("CLS");

		}
		else if(LogMain==5){
			system("CLS");
			break;
		}
	}while(X==1);
}

		printf("Digite sua senha: ");
		gets(Senha);
		if(strcmp(Login,Login_Admin)==0){
			if(strcmp(Senha,Pass)==0){
				return(1);
			}
		}
		else if(strcmp(Login,Login_User)==0){
			if(strcmp(Senha,Pass)==0){
				return(2);
			}
		}
		else{
			system("CLS");
			printf("Login errado ou senha errada, tente novamente.\n");
		}
	}while(X==1);
}

int IncMenu(){
	int Menu;
	do{
		printf("O que deseja fazer?\n1)Verificar os filmes no catálogo.\n2)Adicionar filme no catálogo.\n3)Editar filme.\n4)...\n5)Fechar programa.");
		scanf("\n%i", &Menu);
	}while(Menu<=0 || Menu>5);
	return Menu;
}

main(){
	int X=1;
	do{
		int LogMain= Login();
		if(LogMain==1){
			system("CLS");
			do{
				int SelMenu = IncMenu();
			}while(IncMenu()<5);
		}
		else if(LogMain==2){
			system("CLS");
			do{
				
			}while(IncMenu()<5);
		}
	}while(X==1);
}
