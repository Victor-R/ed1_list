#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
/*Nome: VICTOR HENRIQUE RIBEIRO - Curso: CIENCIA DA COMPUTAÇÃO - NOTURNO - 2016 - ED1*/
typedef struct expr expr;
struct expr
{
	int expoente;
	int num;
	expr *next;
};

expr *novo(int expo,int n){
	expr *novo = malloc(sizeof(expr));
    novo->expoente = expo;
    novo->num = n;
    novo->next = NULL;
    return novo;
}

void menu(){
	printf("   O.E.M.E.M    (vide creditos)\n");
	printf("1 - Insira um componente da expressao\n");
	printf("2 - Resetar Expressao\n");
	printf("3 - Retirar elemento da enesima posicao\n");
	printf("4 - Calcular x\n");
	printf("5 - Creditos\n");
	printf("6 - Sair\n");
}

void inserir(expr **e){
	int expo, n;
	expr *elem;
	expr *p;
	system("cls");
	printf("Format: n*x^expo\n");
	printf("Type the 'n' :");
	scanf("%d",&n);
	printf("Type the 'expo' : \n");
	scanf("%d",&expo);
	elem = novo(expo,n);
	if(*e==NULL){
		*e = elem;
	}else{
		p = *e;
		//proxi = (*e)->prox;
		if(p->expoente>elem->expoente){
			elem->next = p;
			p = elem;
			*e = p;
		}else{
			while((p->next!=NULL) && p->next->expoente<elem->expoente){ //p->next->expoente<elem->expoente) 	
			//printf("ENTROU!!!");
			//if(p->next->expoente<elem->expoente)
			p = p->next;
			//system("pause");
			}
			elem->next = p->next;
			p->next = elem;
		}		
	}
}

void remove_n(expr **e,int n){
	expr *aux,*p;

	if(*e==NULL){
		printf("Lista Vazia, impossivel remocao\n");
	}else{
		p=*e;
		if(p->expoente==n){			
			aux = p->next;
			free(p);
			p = aux;
			*e = p;

		}else{
			while(p){
			if(p->next->expoente==n){
				aux = p->next;
				p->next = aux->next;
				free(aux);
			}
			p=p->next;
			}	
		}						
	}
}

int calculo(expr *e,int x){
	expr *p=e;
	int result=0;
	if(!p){
		return p->num*pow(x,p->expoente);
	}else{
		return calculo(p->next,x);
	}
}

void imprimir(expr *e){
	//to do
	expr *p;
	if(e==NULL){
		printf("X = Lista Vazia: Por favor insira um valor\n");
	}else{
		p = e;
		printf("X = ");
		while(p){
			if(p->expoente==0){
				if(p->num>0){
					printf(" +%d ",p->num);
				}else{
					printf(" %d ",p->num);
				}
			}else if(p->num>0){
				printf(" +%dx^%d ",p->num,p->expoente);			
			}else{
				printf(" %dx^%d ",p->num,p->expoente);
			}
			p=p->next;
		}
		printf("\n");
	}
}

void destroy(expr **e){
	if(!(*e))
		return;
	destroy(&(*e)->next);
	free(*e);
	*e = NULL;
}