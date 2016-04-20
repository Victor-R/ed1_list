#include <stdlib.h>
#include <stdio.h>
#include "parentes.h"

main(){
	char expr[50];
	pilha parent;
	int error=0,i=0;
	parent.topo=-1;
	printf("Verifique os parenteses ( o _o)\n");
	printf("Digite uma frase,sem acentuacao: ");    
    scanf("%[^\n]s",&expr);
    printf("Sua expressao : %s\n",expr);
    while(expr[i] && error!=1){
    	if(expr[i]=='('){
    		push(&parent,expr[i]);
    	}else if(expr[i]==')'){
    		if(parent.vetor[parent.topo]=='('){
    			pop(&parent);
    		}else if(pilha_vazia(parent)){
    			error=1;
    		}
    	}
    	i++;
    }
    if(error==1){
    	printf("Erro = Condicao 2: todo parentese fechado tem que ser precedido por um parentese aberto.\n");
    }else if(pilha_vazia(parent)){
    	printf("Expressao escrita corretamente\n");
    }else{
    	printf("Erro = Condicao 1: o numero de parenteses abertos e fechados nao sao iguais. \n");
    }
    system("pause");
}