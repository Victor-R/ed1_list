#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*Nome: VICTOR HENRIQUE RIBEIRO - Curso: CIENCIA DA COMPUTAÇÃO - NOTURNO - 2016 - ED1*/

//GLOBALS
#define Max 50
int fim_list =-1;
//***************************
//STRUCTS
//int fim_list = -1;
typedef struct produto produto;
struct produto{
	int codProd; //código do produto
	char nomeProd[10]; //nome do produto
	float valor; //valor do produto
	int qtdeEstoque; //quantidade disponível em estoque
};

typedef struct lista lista;
struct  lista{
	produto dados[Max]; //arranjo com os elementos da lista
	//int FL; // índice da primeira posição livre da lista
};
//***************************

void menu()
{
	system("cls");
	printf("    Lista Estoque\n");
	printf("1 - Inserir Elemento\n");
	printf("2 - Remover 'n' Elementos\n");
	printf("3 - Exibir Lista\n");
	printf("4 - Trocar elementos\n");
	printf("5 - Produto com o menor estoque\n");
	printf("6 - Sair\n");
	printf("\nDigite um comando: ");
}

produto novo_produto()
{
	produto novo;
	system("cls");
	printf("Digite o codigo do produto: ");
	scanf("%d",&novo.codProd);
	printf("\nDigite o nome do Produto: ");
	scanf("%s",&novo.nomeProd);
	printf("\nDigite o valor do produto: ");
	scanf("%f",&novo.valor);
	printf("\nQtd no Estoque: ");
	scanf("%d",&novo.qtdeEstoque);

	return novo;
}

int cheia(int fim_list)
{
	if(fim_list+1==Max)
	{
		return 1;
	}else
	{
		return 0;
	}
}

int vazia(int fim_list)
{
	if(fim_list==-1)
	{
		return 1;
	}else
	{
		return 0;
	}
}


// A LISTA É ORDENADA, ENTÃO SEMPRE ORDENAR APÓS ALTERAÇÃO NA MESMA
int inserir(lista *estoque)
{
	int i,cmd;
	produto aux,aux2;

	if(vazia(fim_list)==1)
	{		
		// recolher informações do produto, inserir na primeira posição
		fim_list++;
		estoque->dados[fim_list] = (produto)novo_produto();
		//estoque->dados[fim_list].codProd = fim_list;
		return 1;	
	}else if(cheia(fim_list)==1)
	{
		printf("ERRO: Lista cheia impossivel a inserção, por favor remova algum elemento\n");
		return 0;
	}else
	{
		i=0;
		cmd=1;
		aux = novo_produto();
		fim_list++;
		do{
			if(estoque->dados[i].codProd>aux.codProd)
			{
				aux2=estoque->dados[i];
				estoque->dados[i]=aux;
				aux=aux2;
			}
			i++;
		}while(i!=fim_list);
		//recolher informações do produto, inserir na lista e ordenar		
		estoque->dados[fim_list] = aux;
		return 1;
		//estoque.dados[fim_list] = novo_produto();		
		//ordenar_Bubble(estoque);
		//decidir se tenho que encontrar a posição e inserir, ou inserir e ordenar a lista toda
	}
}

void remover(lista *estoque)
{
	int code,i=0;
	produto aux;
	if(vazia(fim_list)==1)
	{
		printf("ERRO: Lista vazia, impossivel remoção\n");
	}else
	{
		//achar o elemento, excluir reordenar lista
		system("cls");
		printf("    Remoção de produto\n");
		printf("Digite o codigo do produto: ");
		scanf("%d",&code);
		do
		{
			if(estoque->dados[i].codProd==code)
			{
				for(i;i<fim_list;i++)
				{
					estoque->dados[i] = estoque->dados[i+1];
				}
				fim_list--;
			}
			i++;
		}while(i!=fim_list);
	}
}

int remove_n(lista *estoque,int n)
{
	int i=0;
	if(vazia(fim_list)==1)
	{
		printf("ERRO: Lista vazia impossivel remover elementos\n");
		return 0;
	}else
	{
		if((fim_list+1)<=n)
		{
			//ou destruo ou erro?
			fim_list=-1;			
		}else
		{			
			/*for(i=estoque->FL;i<n;i++)
			{
				estoque->FL++;
				//printf("FL= %d\n",estoque->FL);
			}*/
			for(i=n;i<=fim_list;i++){
				estoque->dados[i-n]=estoque->dados[i];
			}
			fim_list -= n;
		}
	}
}

void imprimir_listaprod(lista *estoque)
{
	int i;
	if(vazia(fim_list)==1)
	{
		system("cls");
		printf("Lista vazia, por favor insira algum produto no estoque.\n");
		system("pause");
	}else
	{
		system("cls");
		for(i=0;i<=fim_list;i++)
		{			
			printf("*****************************************\n");
			printf("\nCod: %d\n",estoque->dados[i].codProd);
			printf("Produto: %s\n",estoque->dados[i].nomeProd);
			printf("Preco: %.2f\n",estoque->dados[i].valor);
			printf("Qtde: %d\n",estoque->dados[i].qtdeEstoque);
		}
		system("pause");
	}
}

int trocaProdutos (lista *estoque, int pos1, int pos2)
{
	char aux[10];
	if(vazia(fim_list)==1)
	{
		printf("ERRO: no minimo dois produtos diferentes no estoque para a troca\n");
	}else if(fim_list==0)
	{
		printf("ERRO: no minimo dois produtos diferentes no estoque para a troca\n");
	}else
	{
		if(0<=pos1<=fim_list && 0<=pos2<=fim_list)
		{
			strcpy(aux,estoque->dados[pos1].nomeProd);			
			strcpy(estoque->dados[pos1].nomeProd,estoque->dados[pos2].nomeProd);			
			strcpy(estoque->dados[pos2].nomeProd,aux);
		}
	}
}



void imprimir_prod(lista *estoque,int code)
{
	int check=0,i;
	if(vazia(fim_list)==1)
	{
		system("cls");
		printf("Lista vazia, impossivel encontrar o elemento\n");
	}else
	{
		for(i=0;i<=fim_list;i++)
		{
			if(estoque->dados[i].codProd==code)
			{
				printf("*****************************************\n");
				printf("\nCod: %d\n",estoque->dados[i].codProd);
				printf("Produto: %s\n",estoque->dados[i].nomeProd);
				printf("Preco: %.2f\n",estoque->dados[i].valor);
				printf("Qtde: %d\n",estoque->dados[i].qtdeEstoque);
				check=1;
			}
		}
		if (check==0)
		{
			system("cls");
			printf("Codigo nao encontrado\n");
		}
	}
}

int buscar(lista *estoque,int codProd){
	int i=0,pos=-1;
	
	if(vazia(fim_list)==1){
		printf("Lista vazia\n");
		return pos;
	}else{		
		pos = 0;		
		do{
			if(estoque->dados[i].codProd==codProd){
				pos = i;
			}
			i++;
		}while(i!=fim_list);
		return pos;
	}
}

int efetuar_compra(lista *estoque, int codProd, int qtde)
{
	int aux;
	if(vazia(fim_list)==1)
	{
		printf("ERRO: lista vazia, insira algum produto para ser possivel a compra\n");
		return 0;
	}else if(buscar(estoque,codProd)!=-1)
	{
		aux = buscar(estoque,codProd);
		if(estoque->dados[aux].qtdeEstoque >= qtde)
		{
			estoque->dados[aux].qtdeEstoque -= qtde;
			return 1;
		}else
		{
			printf("Quantidade em estoque insuficiente para compra\n");
			return 0;
		}
	}else
	{
		printf("Produto nao encontrado no estoque\n");
		return 0;
	}

}


int buscar_produto(lista *estoque)
{
	int i=0,aux,pos;
	if(vazia(fim_list)==1)
	{
		printf("ERRO: Lista de produtos esta vazia, nenhum valor para ser buscado\n");
		return 0;
	}else
	{		
		pos = 0;		
		aux = estoque->dados[pos].qtdeEstoque;		
		do{
			if(aux > estoque->dados[i].qtdeEstoque)
			{
				pos = i;				
				aux = estoque->dados[i].qtdeEstoque;
			}			
			i++;
		}while(i<fim_list);
		return pos;
	}
}


