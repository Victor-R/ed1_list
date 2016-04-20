#include <stdlib.h>
#include <stdio.h>

#define MAX 50

typedef struct pilha pilha;
struct pilha
{
	char vetor[MAX];
	int topo;
};

int pilha_cheia(pilha p){
	if(p.topo==49){
		return 1;
	}else{
		return 0;
	}
} // retorna 1 se pilha cheia, 0 caso contrário
int pilha_vazia(pilha p){
	if(p.topo==-1){
		return 1;
	}else{
		return 0;
	}
} // retorna 1 se pilha vazia, 0 caso contrário
//void cria_pilha(pilha *p) // inicializa uma pilha
void push(pilha *p, char elem){
	if(pilha_cheia(*p)){
		printf("Erro: Pilha cheia\n");
	}else{
		p->topo++;
		p->vetor[p->topo] = elem;
	}
} // empilha um elemento
char pop(pilha *p){
	if(pilha_vazia(*p)){
		printf("Erro: Pilha vazia nenhum elemento para desempilhar\n");
	}else{
		p->topo--;
		//return p->vetor[p->topo+1];
	}
} // desempilha um elemento
void libera_pilha(pilha *Ptp){
	Ptp->topo=-1;	
} // esvazia a pilha
