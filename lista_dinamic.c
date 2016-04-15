#include <stdlib.h>
#include <stdio.h>
#include "lista_dinamic.h"
/*Nome: VICTOR HENRIQUE RIBEIRO - Curso: CIENCIA DA COMPUTAÇÃO - NOTURNO - 2016 - ED1*/
main(){
	int cmd,n,result;
	expr *e=NULL;
	do{
		system("cls");
		menu();
		imprimir(e);
		scanf("%d",&cmd);
		if(cmd==1){
			inserir(&e);
		}else if(cmd==2){
			destroy(&e);
			printf("Target destroyed!\n");
			system("pause");
		}else if(cmd==3){
			system("cls");
			printf("Digite o expoente do elemento que vc deseja remover: ");
			scanf("%d",&n);
			remove_n(&e,n);
		}else if(cmd==4){
			printf("Digite um valor para x : \n");
			scanf("%d",&n);
			result = calculo(e,n); //arrumar recursividade
			printf("X = %d\n",result);
		}else if(cmd==5){
			printf("O.E.M.E.M : O espetacular mundo das expressoes matematicas\n");
		}else if(cmd==6){
			printf("Saindo...\n");
			system("pause");
		}
	}while(cmd!=6);
}