#include<stdio.h>
#include<stdlib.h>

int IncMenu(){
	int Menu;
	do{
		printf("O que deseja fazer?\n1)Verificar os filmes no cat�logo.\n2)Adicionar filme no cat�logo.\n3)Editar filme.\n4)...\n5)...");
		scanf("\n%i", &Menu);
	}while(Menu<=0 || Menu>5);
	return Menu;
}

main(){
	int SelMenu = IncMenu();
}
