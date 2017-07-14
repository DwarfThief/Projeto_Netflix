#include<stdio.h>
#include<stdlib.h>

int Login(){
	int X=1;
	char Login[100], Senha[100],Login_Admin[100]="Pericles_admin", Login_User[100]="Pericles_user", Pass[100]="Queremos10";
	do{
		printf("Digite seu usuário: ");
		gets(Login);
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
