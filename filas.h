#include <stdlib.h>
#include <stdio.h>

typedef struct item item;
struct item
{
	int info;
	item *next;
};

void insert(item **inicio,item **fim,item *novo){
	if(vazia(*inicio)==1){
		*inicio = novo;	
    *fim = novo;
  }else
  {
   	(*fim)->next=novo;
   	*fim=novo;
  }
}

int vazia(item *inicio)
{
    return inicio==NULL;
}

void imprima(item *inicio)
{
    item *p = inicio;
    if(vazia(inicio))
    {
        printf("\nLista vazia");
    }else
    {              
      do{           
        printf(" %d -",p->info);
        p=p->next;
      }while(p);
    }
}

item * novo(int n){
	item *novo = malloc(sizeof(item));
  novo->info = n;
  novo->next = NULL;
  return novo;
}