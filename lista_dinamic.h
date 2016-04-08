#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*Nome: VICTOR HENRIQUE RIBEIRO - Curso: CIENCIA DA COMPUTAÇÃO - NOTURNO - 2016 - ED1*/
typedef struct expr expr;
struct expr
{
	int expoente;
	int num;
	item *next;
};

expr novo(int expo,int n){
	expr *novo = malloc(sizeof(expr));
    novo->expoente = expo;
    novo->num = n;
    novo->next = NULL;
    return novo;
}

void menu(){
	printf("   O.E.M.E.M    (vide creditos)\n");
	printf("1 - Insira um componente da expressao\n");
	printf("2 - Creditos\n");
	printf("3 - Sair\n");
}