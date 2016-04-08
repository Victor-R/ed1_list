#include <stdlib.h>
#include <stdio.h>
#include "lista_estatic.h"
/*Nome: VICTOR HENRIQUE RIBEIRO - Curso: CIENCIA DA COMPUTAÇÃO - NOTURNO - 2016 - ED1*/
main(void)
{
	int cmd=0,remo,pos1,pos2,y;
	lista estoque;
	do{		
		menu();
		scanf("%d",&cmd);
		if(cmd==1)
		{
			inserir(&estoque);
		}else if(cmd==2)
		{
			printf("Quantos elementos deseja remover? \n");
			scanf("%d",&remo);
			y = remove_n(&estoque,remo);
			if(y){
				printf("Remocao realizada com sucesso!\n");
			}else{
				printf("Remocao nao realizada\n");
			}
		}else if(cmd==3)
		{
			imprimir_listaprod(&estoque);
		}else if(cmd==4)
		{
			printf("Qual posicao voce deseja trocar:\npos 1: ");
			scanf("%d",&pos1);
			printf("pos 2: ");
			scanf("%d",&pos2);
			trocaProdutos (&estoque,pos1,pos2);
		}else if(cmd==5){
			system("cls");
			printf("Produto com a menor quantidade em estoque:\n");
			y=buscar_produto(&estoque);
			printf("*****************************************\n");
			printf("\nCod: %d\n",estoque.dados[y].codProd);
			printf("Produto: %s\n",estoque.dados[y].nomeProd);
			printf("Preco: %.2f\n",estoque.dados[y].valor);
			printf("Qtde: %d\n",estoque.dados[y].qtdeEstoque);
			system("pause");
		}
	}while(cmd!=6);
	printf("Saindo\n");
}
