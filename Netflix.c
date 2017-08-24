#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
	char nome[30], descricao[500];
	int duracao, FS, temp;//FS divide oq eh um filme ou serie. Caso filme, 1. Caso serie, 2
}CATALOGO;

//Imprimi a lista da lixeira
void REVIVE_LIST(CATALOGO* Lixeira, int* Lixeira_TAM){
	system("CLS");
	int loop;
	for(loop=0;loop<=*Lixeira_TAM;loop++){
		printf("%i)%s\n", loop+1, Lixeira[loop].nome);
	}
}

//Removendo o produto da lixeira e mandando para o catalogo
int REVIVE(CATALOGO* produtos, CATALOGO* Lixeira, int* Lixeira_TAM, int* TAM, int produto_selecionado){
	*TAM++;
	strcpy(produtos[*TAM].descricao, Lixeira[produto_selecionado].descricao);//Copia a descricao
	strcpy(produtos[*TAM].nome, Lixeira[produto_selecionado].nome);//Copia o nome
	produtos[*TAM].FS = Lixeira[produto_selecionado].FS;//Copia o tipo do produto
	produtos[*TAM].temp = Lixeira[produto_selecionado].temp;//Copia a quantidade de Temp
	produtos[*TAM].duracao = Lixeira[produto_selecionado].duracao;//Copia a duracao
	
	int i;
	for(i=produto_selecionado;i<*Lixeira_TAM;i++){
		strcpy(Lixeira[i].descricao, Lixeira[i+1].descricao);//Copia a descricao
		strcpy(Lixeira[i].nome, Lixeira[i+1].nome);//Copia o nome
		Lixeira[i].FS = Lixeira[i+1].FS;//Copia o tipo do produto
		Lixeira[i].temp = Lixeira[i+1].temp;//Copia a quantidade de Temp
		Lixeira[i].duracao = Lixeira[i+1].duracao;//Copia a duracao
	}

	strcpy(Lixeira[*Lixeira_TAM].descricao, "");//Copia a descricao
	strcpy(Lixeira[*Lixeira_TAM].nome, "");//Copia o nome
	Lixeira[*Lixeira_TAM].FS = NULL;//Copia o tipo do produto
	Lixeira[*Lixeira_TAM].temp = NULL;//Copia a quantidade de Temp
	Lixeira[*Lixeira_TAM].duracao = NULL;//Copia a duracao
	
	*Lixeira_TAM--;
}

//Removendo o produto do catalogo e mandando para a lixeira
int REMOCAO(int* Lixeira_TAM, CATALOGO* Lixeira, int* TAM, int produto_selecionado, CATALOGO* produtos){
	system("CLS");
	char sel_menu;
	printf("O produto selecionado para ser removido foi: %s\nVoce realmente quer retira-lo do catalogo(Y/N)?", produtos[produto_selecionado].nome);
	scanf("%c", &sel_menu);
	getchar();
	if(sel_menu == 'Y' || sel_menu == 'Y'){
		*Lixeira_TAM++;
		strcpy(Lixeira[*Lixeira_TAM].descricao, produtos[produto_selecionado].descricao);//Copia a descricao
		strcpy(Lixeira[*Lixeira_TAM].nome, produtos[produto_selecionado].nome);//Copia o nome
		Lixeira[*Lixeira_TAM].FS = produtos[produto_selecionado].FS;//Copia o tipo do produto
		Lixeira[*Lixeira_TAM].temp = produtos[produto_selecionado].temp;//Copia a quantidade de Temp
		Lixeira[*Lixeira_TAM].duracao = produtos[produto_selecionado].duracao;//Copia a duracao
		int i;
		//retirando o filme do catalogo
		for(i=produto_selecionado ; i<*TAM ; i++){
			strcpy(produtos[i].descricao, produtos[i+1].descricao);//Copia a descricao
			strcpy(produtos[i].nome, produtos[i+1].nome);//Copia o nome
			produtos[i].FS = produtos[i+1].FS;//Copia o tipo do produto
			produtos[i].temp = produtos[i+1].temp;//Copia a quantidade de Temp
			produtos[i].duracao = produtos[i+1].duracao;//Copia a duracao
		}
		
		strcpy(produtos[*TAM].descricao, "");//Copia a descricao
		strcpy(produtos[*TAM].nome, "");//Copia o nome
		produtos[*TAM].FS = NULL;//Copia o tipo do produto
		produtos[*TAM].temp = NULL;//Copia a quantidade de Temp
		produtos[*TAM].duracao = NULL;//Copia a duracao

		TAM--;
		return 1;
	}
}

//Edicao no nome de algum produto
int EDIT_Titulo(int* TAM, CATALOGO* produtos, int produto_selecionado){
	CATALOGO temp;
	char sel_menu;
	system("CLS");
	printf("O titulo atual eh: %s\nVoce realmente deseja mudar o titulo do produto(Y/N)?", produtos[produto_selecionado].nome);
	scanf("%c", &sel_menu);
	getchar();
	if(sel_menu == 'y' || sel_menu == 'Y'){
		printf("\nDigite o novo titulo:");
		gets(temp.nome);
		int validacao = SEARCH(TAM, produtos, temp);
		if(validacao == -1){
			return -1;//Ja existe um titulo com o nome que o usuario deseja alterar.
		}
		else{//Pode ser alterado
			strcpy(produtos[produto_selecionado].nome,temp.nome);//efetuando a alteração para o filme original
			return 1;
		}
	}
}

//Edicao no N de temp
int EDIT_Temp(int produto_selecionado, CATALOGO* produtos){
	char sel_menu;
	system("CLS");
	printf("O numero de temporadas no momento esta como: %i\nVoce deseja alterar(Y/N)?", produtos[produto_selecionado].temp);
	scanf("%c", &sel_menu);
	getchar();
	if(sel_menu == 'Y' || sel_menu == 'y'){
		system("CLS");
		printf("Informe a nova alteracao que voce deseja:");
		scanf("%i", &produtos[produto_selecionado].temp);
		getchar();
		return 1;
	}
	else{
		return 0;
	}
}

//Edicao da descricao de algum produto
int EDIT_Descricao(int produto_selecionado, CATALOGO* produtos){
	char sel_menu;
	system("CLS");
	printf("A descricao atual eh:\n%s\n\nVoce realmente deseja alterar a descricao(Y/N)?", produtos[produto_selecionado].descricao);
	scanf("%c", &sel_menu);
	getchar();
	if(sel_menu == 'Y' || sel_menu == 'y'){
		system("CLS");
		printf("Digite a nova descricao:\n");
		gets(produtos[produto_selecionado].descricao);
		return 1;
	}
	else{
		return 0;
	}
}

//Menu de edicao.
int EDIT_Menu(int* TAM, CATALOGO* produtos,int produto_selecionado){
	int SEL;
	if(produtos[produto_selecionado].FS==1){
		system("CLS");
		printf("O produto selecionado foi: %s.\nO que voce deseja editar?\n1)Titulo\n2)Duracao\n3)Descricao\n4)Remover do catalogo\n5)Retornar", produtos[produto_selecionado].nome);
		scanf("%i", &SEL);
		getchar();
	}
	else if(produtos[produto_selecionado].FS==2){
		system("CLS");
		printf("O produto selecionado foi: %s.\nO que voce deseja editar?\n1)Titulo\n2)Quantidade de temporadas\n3)Descricao\n4)Remover do catalogo\n5)Retornar", produtos[produto_selecionado].nome);
		scanf("%i", &SEL);
		getchar();
		if(SEL==2){
			SEL==0;
		}
	}
	return SEL;	
}

//Edicao da duracao de um filme.
int EDIT_Duracao(int* produto_selecionado, CATALOGO* produtos){
	char sel_menu;
	system("CLS");
	printf("A duracao atual do seu filme eh de(em min): %i\nVoce deseja alterar(Y/N)?", produtos[*produto_selecionado].duracao);
	scanf("%c", &sel_menu);
	getchar();
	if(sel_menu == 'Y'|| sel_menu == 'y'){
		system("CLS");
		printf("Digite a duracao(em min) que voce deseja para alterar: ");
		scanf("%i", &produtos[*produto_selecionado].duracao);
		getchar();
		return 1;
	}
	else{
		return 0;
	}
}

//Imprimi a lista do Catalogo
void LIST(int TAM, CATALOGO* produtos){
	int loop;
	for(loop=0;loop<=TAM;loop++){
		printf("%i)%s\n", loop+1, produtos[loop].nome);
	}
}

//Pesquisa a existencia de um arq com o msm nome
int SEARCH(int* TAM, CATALOGO* produtos, CATALOGO temp){
	int i;

	for(i=0; i<=*TAM; i++){
		if(strcmpi(produtos[i].nome, temp.nome)==0){
			return -1;//caso exista um filme com o msm nome.
		}
	}
	return 0;//caso o n exista um filme com o msm nome.		
}

//ADD produto
int ADD_LIBRARY(int* TAM, CATALOGO* produtos, CATALOGO temp){
	system("CLS");
	int validacao = SEARCH(TAM, produtos, temp);
	//verifica se existe outro filme com msm nome.
	if(validacao != -1){
		*TAM++;//aumenta o n de filmes no catalogo.
		strcpy(produtos[*TAM].nome, temp.nome);//copia o nome de forma oficial
		produtos[*TAM].FS = temp.FS;//aq ele recebe a diferenciacao de Filme ou Serie.
		
		if(produtos[*TAM].FS == 1){
			printf("Digite a duracao para o seu filme(em minutos):");
			scanf("%i", &produtos[*TAM].duracao);
			getchar();
			system("CLS");
			printf("Crie uma descricao para o seu filme:");
			gets(produtos[*TAM].descricao);
			system("CLS");
		}

		else if(produtos[*TAM].FS == 2){	
			printf("Infome quantas temporadas a sua serie possui:");
			scanf("%i", &produtos[*TAM].temp);
			getchar();
			system("CLS");
			printf("Crie uma descricao para a sua serie:");
			gets(produtos[*TAM].descricao);
			system("CLS");
		}

		return 0;
	}
	
	return -1;
}

//Leitura do arq
void LEITURA_DE_ARQ(int TAM, CATALOGO* produtos){
	FILE* arq = fopen("catalogo.txt", "r");
	fread(produtos, sizeof(*produtos), TAM, arq);
	fclose(arq);
}

//Salvando o arq
void SALVAR(int TAM, CATALOGO* produtos){
	FILE* arq = fopen("catalogo.txt", "w");
	
	fwrite(produtos, sizeof(*produtos), TAM, arq);
	fclose(arq);
}

main(){
	int Lixeira_TAM=0, TAM=0, SEL, loop=1;
	CATALOGO produtos[300], Lixeira[300];
	CATALOGO temp;
	int validacao, produto_selecionado;
	LEITURA_DE_ARQ(TAM, produtos);
	do{
		printf("Bem vindo, o que voce deseja fazer?\n1)Registrar um filme.\n2)Registrar uma serie.\n3)Editar algum produto.\n4)Visualizar o catalogo.\n5)Salvar e sair.\n");
		if(Lixeira_TAM !=0){
			printf("6)Reativar um produto.\n");
		}
		scanf("%i", &SEL);
		getchar();
		system("CLS");
		switch(SEL){
			case 1: //Registrar um filme
				system("CLS");
				printf("Digite o nome para o seu filme:");
				gets(temp.nome);
				temp.FS = 1;
				validacao = ADD_LIBRARY(&TAM, produtos, temp);
				if(validacao==-1){
					printf("---Ja existe um produto com esse nome.---\n");
				}
				else{
					printf("---Seu produto foi adicionado ao catalogo.---\n");
				}
				break;

			case 2: //Registrar uma serie
				printf("Digite o nome para a sua serie:");
				gets(temp.nome);
				temp.FS = 2;
				validacao = ADD_LIBRARY(&TAM, produtos, temp);
				if(validacao==-1){
					printf("---Ja existe um produto com esse nome.---\n");
				}
				else{
					printf("---Seu produto foi adicionado ao catalogo.---\n");
				}
				break;

			case 3: //Editar algum produto
				if(TAM>0){
					printf("\nSelecione o produto que deseja editar:");
					LIST(&TAM, produtos);
					scanf("%i", &produto_selecionado);
					produto_selecionado--;
					getchar();
					int sel_menu = EDIT_Menu(&TAM, produtos, produto_selecionado);
					switch(sel_menu){
						case 0://Edicao no N de temp de alguma serie
							validacao = EDIT_Temp(produto_selecionado, produtos);
							if (validacao == 1){
								system("CLS");
								printf("Seu produto foi alterado com sucesso!\n");
							}
							break;

						case 1://Edicao do titulo de algum produto
							validacao = EDIT_Titulo(&TAM, produtos, produto_selecionado);
							if(validacao == 1){
								system("CLS");
								printf("~~~Seu titulo foi editado~~~\n");
							}
							else if(validacao == 0){
								system("CLS");
								printf("~~~Seu titulo nao pode ser alterado, pois já existe um produto com o mesmo nome~~~\n");
							}
							break;
						case 2://Edicao da descricao de algum produto
							validacao = EDIT_Descricao(produto_selecionado, produtos);
							if(validacao == 1){
								system("CLS");
								printf("~~~Sua descricao foi alterada com sucesso~~~\n");
							}
							break;

						case 3://Edicao da duracao de algum filme.
							validacao = EDIT_Duracao(&produto_selecionado, produtos);
							if(validacao == 1){
								system("CLS");
								printf("~~~Sua duracao foi alterada com sucesso~~~\n");
							}
							break;

						case 4:
							validacao = REMOCAO(&Lixeira_TAM, Lixeira, &TAM, produto_selecionado, produtos);
							if(validacao == 1){
								system("CLS");
								printf("~~~Seu produto foi retirado do catalogo, porem ele nao sumiu~~~\n~~~Caso queira ele novamente, seus dados ainda estao salvos~~~\n");
							}
							break;

						case 5:
							break;

						default:
							system("CLS");
							printf("~~~Numero invalido~~~\n");
							break;
					}
				}
				else{
					printf("~~~Sem produtos catalogados por enquanto~~~\n");
				}
				break;

			case 4: //Listagem do catalogo
				LIST(TAM, produtos);
				break;

			case 5: //Salvar e sair
				loop=2;//quebra o While
				break;

			case 6: //Revivendo produto
				REVIVE_LIST(Lixeira, &Lixeira_TAM);
				scanf("%i", &produto_selecionado);
				validacao = REVIVE(produtos, Lixeira, &Lixeira_TAM, &TAM, produto_selecionado);
				if(validacao == 1){
					system("CLS");
					printf("~~~Seu produto foi reativado com todas as infomacoes antigas~~~\n");
				}
				break;

			default:
				printf("\n~~~Valor nao aceito~~~");
		}
	}while(loop==1);
	//Salva o arquivo
	SALVAR(TAM, produtos);
}
