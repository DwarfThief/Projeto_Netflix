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
	system("CLS");
	++*TAM;
	strcpy(produtos[*TAM].descricao, Lixeira[produto_selecionado].descricao);//Copia a descricao
	strcpy(produtos[*TAM].nome, Lixeira[produto_selecionado].nome);//Copia o nome
	produtos[*TAM].FS = Lixeira[produto_selecionado].FS;//Copia o tipo do produto
	produtos[*TAM].temp = Lixeira[produto_selecionado].temp;//Copia a quantidade de Temp
	produtos[*TAM].duracao = Lixeira[produto_selecionado].duracao;//Copia a duracao
	
	int i;
	for(i=produto_selecionado ; i<*Lixeira_TAM ; i++){
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
	--*Lixeira_TAM;
	return 1;
}

//Removendo o produto do catalogo e mandando para a lixeira
int REMOCAO(int* Lixeira_TAM, CATALOGO* Lixeira, int* TAM, int produto_selecionado, CATALOGO* produtos){
	system("CLS");
	char sel_menu;
	printf("O produto selecionado para ser removido foi: %s\nVoce realmente quer retira-lo do catalogo(Y/N)?", produtos[produto_selecionado].nome);
	scanf("%c", &sel_menu);
	getchar();
	if(sel_menu == 'Y' || sel_menu == 'y'){
		++*Lixeira_TAM;
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

		--*TAM;
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
int EDIT_Temp(int* produto_selecionado, CATALOGO* produtos){
	char sel_menu;
	system("CLS");
	printf("O numero de temporadas no momento esta como: %i\nVoce deseja alterar(Y/N)?", produtos[*produto_selecionado].temp);
	scanf("%c", &sel_menu);
	getchar();
	if(sel_menu == 'Y' || sel_menu == 'y'){
		system("CLS");
		printf("Informe a nova alteracao que voce deseja:");
		scanf("%i", &produtos[*produto_selecionado].temp);
		getchar();
		return 1;
	}
	else{
		return 0;
	}
}

//Edicao da descricao de algum produto
int EDIT_Descricao(int *produto_selecionado, CATALOGO* produtos){
	char sel_menu;
	system("CLS");
	printf("Digite a nova descricao:\n");
	gets(produtos[*produto_selecionado].descricao);
	return 1;
}

//Menu de edicao.
int EDIT_Menu(int* TAM, CATALOGO* produtos,int* produto_selecionado){
	int SEL;
	if(produtos[*produto_selecionado].FS==1){
		system("CLS");
		printf("O produto selecionado foi: %s.\nO que voce deseja editar?\n1)Titulo\n2)Duracao\n3)Descricao\n4)Remover do catalogo\n5)Retornar\n", produtos[*produto_selecionado].nome);
		scanf("%i", &SEL);
		getchar();
	}
	else if(produtos[*produto_selecionado].FS==2){
		system("CLS");
		printf("O produto selecionado foi: %s.\nO que voce deseja editar?\n1)Titulo\n2)Quantidade de temporadas\n3)Descricao\n4)Remover do catalogo\n5)Retornar\n", produtos[*produto_selecionado].nome);
		scanf("%i", &SEL);
		getchar();
		if(SEL==2){
			SEL=0;
			printf("OK\n");
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
void LIST(int* TAM, CATALOGO* produtos){
	int loop;
	printf("Selecione o produto que deseja:\n");
	for(loop=0;loop<=*TAM;loop++){
		printf("%i)%s\n", loop+1, produtos[loop].nome);
	}
}

//botao 4 do menu do admin
int LIST_SEL(int produto_selecionado, CATALOGO* produtos){
	int loop=1;
	char sel_menu;
	system("CLS");
	do{
		if(produtos[produto_selecionado].FS == 1){
			printf("Titulo: %s\n", produtos[produto_selecionado].nome);
			printf("Duracao: %imin\n", produtos[produto_selecionado].duracao);
			printf("Descricao: %s\n", produtos[produto_selecionado].descricao);
		}
		else if(produtos[produto_selecionado].FS == 2){
			printf("Titulo: %s\n", produtos[produto_selecionado].nome);
			printf("Temporadas: %i\n", produtos[produto_selecionado].temp);
			printf("Descricao: %s\n", produtos[produto_selecionado].descricao);
		}
		printf("Voce deseja editar esse produto(Y/N)?\n");
		scanf("%c", &sel_menu);
		
		if(sel_menu == 'Y' || sel_menu == 'y'){
			system("CLS");
			return 1;
		}
		
		else if(sel_menu == 'n' || sel_menu == 'N'){
			system("CLS");
			return 0;
		}
		
		else{
			system("CLS");
			printf("---------------\n");
			printf(" Digito errado\n");
			printf("---------------\n");
		}
	}while(loop==1);
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
		++*TAM;//Aumenta o indicador da quant de produtos no catalogo
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

//Le o TAM.txt e atribui o valor para a quantidade de produtos no catalogo
int Lendo_Tam(){
	int retornando;
	FILE* arq = fopen("TAM.txt", "r");
	fscanf(arq ,"%i", &retornando);
	fclose(arq);
	return retornando;
}

//Le o tamanho da lixeira
int Leitura_lixeira(){
	int retornando;
	FILE* arq = fopen("TLixeira.txt", "r");
	fscanf(arq, "%i", &retornando);
	fclose(arq);
	return retornando;
}

//Leitura do arq
void LEITURA_DE_ARQ(int TAM, CATALOGO* produtos, int Lixeira_TAM, CATALOGO* Lixeira){	
	FILE* arq = fopen("catalogo.txt", "r");
	fread(produtos, sizeof(CATALOGO), sizeof(TAM), arq);
	fclose(arq);

	FILE* Lixeira_arq = fopen("Lixeira.txt", "r");
	fread(Lixeira, sizeof(CATALOGO), sizeof(Lixeira_TAM), Lixeira_arq);
	fclose(arq);
}

//Salvando o arq
void SALVAR(int* TAM, CATALOGO* produtos, int* Lixeira_TAM , CATALOGO* Lixeira){
	//Salvando o tamanho do catalogo
	FILE* TAM_arq = fopen("TAM.txt","w");
	fprintf(TAM_arq, "%i", *TAM);
	fclose(TAM_arq);
	
	//Salva o catalogo
	FILE* arq = fopen("catalogo.txt", "w");
	fwrite(produtos, sizeof(CATALOGO), sizeof(TAM), arq);
	fclose(arq);

	//Salva o tamanho da Lixeira
	FILE* TLixeira = fopen("TamLixeira.txt", "w");
	fprintf(TLixeira , "%i", *Lixeira_TAM);
	fclose(TLixeira);

	//Salva a lixeira
	FILE* Lixeira_arq = fopen("Lixeira.txt", "w");
	fwrite(Lixeira, sizeof(CATALOGO), sizeof(Lixeira_TAM), Lixeira_arq);
	fclose(Lixeira_arq);
}

main(){
	int SEL, loop=1;
	CATALOGO produtos[300], Lixeira[300], temp;
	int validacao, produto_selecionado, sel_menu;
	int TAM = Lendo_Tam();
	int Lixeira_TAM = Leitura_lixeira();
	LEITURA_DE_ARQ(TAM, produtos, Lixeira_TAM, Lixeira);
	do{
		printf("Bem vindo, o que voce deseja fazer?\n1)Registrar um filme.\n2)Registrar uma serie.\n3)Editar algum produto.\n4)Visualizar catalogo.\n5)Salvar e sair.\n");
		if(Lixeira_TAM >=0){
			printf("6)Reativar um produto.\n");
		}
		scanf("%i", &SEL);
		getchar();
		system("CLS");
		switch(SEL){
			case 1: //Registrar um filme
				printf("Digite o nome para o seu filme:");
				gets(temp.nome);
				temp.FS = 1;
				validacao = ADD_LIBRARY(&TAM, produtos, temp);
				if(validacao==-1){
					printf("------------------------------------\n");
					printf(" Ja existe um produto com esse nome\n");
					printf("------------------------------------\n");
				}
				else{
					printf("----------------------------------------\n");
					printf(" Seu produto foi adicionado ao catalogo\n");
					printf("----------------------------------------\n");
				}
				break;

			case 2: //Registrar uma serie
				printf("Digite o nome para a sua serie:");
				gets(temp.nome);
				temp.FS = 2;
				validacao = ADD_LIBRARY(&TAM, produtos, temp);
				if(validacao==-1){
					printf("------------------------------------\n");
					printf(" Ja existe um produto com esse nome\n");
					printf("------------------------------------\n");
				}
				else{
					printf("----------------------------------------\n");
					printf(" Seu produto foi adicionado ao catalogo\n");
					printf("----------------------------------------\n");
				}
				break;

			case 3: //Editar algum produto
				if(TAM>=0){
					LIST(&TAM, produtos);
					scanf("%i", &produto_selecionado);
					getchar();
					produto_selecionado--;
					sel_menu = EDIT_Menu(&TAM, produtos, &produto_selecionado);
					switch(sel_menu){
						case 0://Edicao no N de temp de alguma serie
							validacao = EDIT_Temp(&produto_selecionado, produtos);
							if (validacao == 1){
								system("CLS");
								printf("--------------------------------------\n");
								printf(" Seu produto foi alterado com sucesso\n");
								printf("--------------------------------------\n");
							}
							break;

						case 1://Edicao do titulo de algum produto
							validacao = EDIT_Titulo(&TAM, produtos, produto_selecionado);
							if(validacao == 1){
								system("CLS");
								printf("------------------------\n");
								printf(" Seu titulo foi editado\n");
								printf("------------------------\n");
							}
							else if(validacao == 0){
								system("CLS");
								printf("------------------------------------------------------------------------------\n");
								printf(" Seu titulo nao pode ser alterado, pois já existe um produto com o mesmo nome\n");
								printf("------------------------------------------------------------------------------\n");
							}
							break;
						
						case 2://Edicao da descricao de algum produto
							validacao = EDIT_Duracao(produto_selecionado, produtos);
							if(validacao == 1){
								system("CLS");
								printf("--------------------------------------\n");
								printf(" Sua duracao foi alterada com sucesso\n");
								printf("--------------------------------------\n");
							}
							break;

						case 3://Edicao da duracao de algum filme.
							validacao = EDIT_Descricao(&produto_selecionado, produtos);
							if(validacao == 1){
								system("CLS");
								printf("----------------------------------------\n");
								printf(" Sua descricao foi alterada com sucesso\n");
								printf("----------------------------------------\n");
							}
							break;

						case 4://Remocao
							validacao = REMOCAO(&Lixeira_TAM, Lixeira, &TAM, produto_selecionado, produtos);
							system("CLS");
							if(validacao == 1){
								printf("-----------------------------------------------------------\n");
								printf(" Seu produto foi retirado do catalogo, porem ele nao sumiu\n");
								printf("  Caso queira ele novamente, seus dados ainda estao salvos\n");
								printf("-----------------------------------------------------------\n");
							}
							break;

						case 5://Retornar
							system("CLS");
							break;

						default:
							system("CLS");
							printf("-----------------\n");
							printf(" Numero invalido\n");
							printf("-----------------\n");
							break;
					}
				}
				else{
					printf("---------------------------------------\n");
					printf(" Sem produtos catalogados por enquanto\n");
					printf("---------------------------------------\n");
				}
				break;

			case 4://Visualizar catalogo
				LIST(&TAM, produtos);
				scanf("%i", &produto_selecionado);
				getchar();
				produto_selecionado--;
				validacao = LIST_SEL(produto_selecionado, produtos);
				if(validacao == 1){

					sel_menu = EDIT_Menu(&TAM, produtos, &produto_selecionado);
					switch(sel_menu){
						case 0://Edicao no N de temp de alguma serie
							validacao = EDIT_Temp(&produto_selecionado, produtos);
							if (validacao == 1){
								system("CLS");
								printf("--------------------------------------\n");
								printf(" Seu produto foi alterado com sucesso\n");
								printf("--------------------------------------\n");
							}
							break;

						case 1://Edicao do titulo de algum produto
							validacao = EDIT_Titulo(&TAM, produtos, produto_selecionado);
							if(validacao == 1){
								system("CLS");
								printf("------------------------\n");
								printf(" Seu titulo foi editado\n");
								printf("------------------------\n");
							}
							else if(validacao == 0){
								system("CLS");
								printf("------------------------------------------------------------------------------\n");
								printf(" Seu titulo nao pode ser alterado, pois já existe um produto com o mesmo nome\n");
								printf("------------------------------------------------------------------------------\n");
							}
							break;
						
						case 2://Edicao da descricao de algum produto
							validacao = EDIT_Duracao(produto_selecionado, produtos);
							if(validacao == 1){
								system("CLS");
								printf("--------------------------------------\n");
								printf(" Sua duracao foi alterada com sucesso\n");
								printf("--------------------------------------\n");
							}
							break;

						case 3://Edicao da duracao de algum filme.
							validacao = EDIT_Descricao(&produto_selecionado, produtos);
							if(validacao == 1){
								system("CLS");
								printf("----------------------------------------\n");
								printf(" Sua descricao foi alterada com sucesso\n");
								printf("----------------------------------------\n");
							}
							break;

						case 4://Remocao
							validacao = REMOCAO(&Lixeira_TAM, Lixeira, &TAM, produto_selecionado, produtos);
							system("CLS");
							if(validacao == 1){
								printf("-----------------------------------------------------------\n");
								printf(" Seu produto foi retirado do catalogo, porem ele nao sumiu\n");
								printf("  Caso queira ele novamente, seus dados ainda estao salvos\n");
								printf("-----------------------------------------------------------\n");
							}
							break;

						case 5://Retornar
							system("CLS");
							break;

						default:
							system("CLS");
							printf("-----------------\n");
							printf(" Numero invalido\n");
							printf("-----------------\n");
							break;
					}
				}				
				break;
			
			case 5: //Salvar e sair
				SALVAR(&TAM, produtos, &Lixeira_TAM, Lixeira);
				loop = 2;//quebra o While
				break;

			case 6: //Revivendo produto
				REVIVE_LIST(Lixeira, &Lixeira_TAM);
				scanf("%i", &produto_selecionado);
				produto_selecionado--;
				validacao = REVIVE(produtos, Lixeira, &Lixeira_TAM, &TAM, produto_selecionado);
				if(validacao == 1){
					//system("CLS");
					printf("-----------------------------------------------------------\n");
					printf(" Seu produto foi reativado com todas as infomacoes antigas\n");
					printf("-----------------------------------------------------------\n");
				}
				break;

			default:
				printf("------------------\n");
				printf(" Valor nao aceito\n");
				printf("-------------------\n");
		}
	}while(loop==1);
}
