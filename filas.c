#include <stdlib.h>
#include <stdio.h>
#include "filas.h"

main(){
	item *f=NULL,*f2=NULL,*f3=NULL,*f4=NULL;
	item *fn=NULL,*fn2=NULL,*fn3=NULL,*fn4=NULL;
	item *p;
	int n,cmd;
	do{
		system("cls");
		printf("Digite um numero para a fila: ");
		scanf("%d",&n);
		insert(&f,&fn,novo(n));
		printf("\nDeseja continuar - 1.Sim - 2.Nao\n");		
		scanf("%d",&cmd);
	}while(cmd!=2);
	printf("\n %d \n",f->info);
	printf("\nF = ");
	imprima(f);
	p=f;
	while(p){
		if(p->info%3==0){
			insert(&f3,&fn3,novo(p->info));
		}
		if(p->info%2==0){
			insert(&f2,&fn2,novo(p->info));
		}if(p->info%2!=0 && p->info%3!=0){
			insert(&f4,&fn4,novo(p->info));
		}
		p = p->next;
	}
	printf("\nMULTIPLOS DE 2 - F2 = ");
	imprima(f2);
	printf("\nMULTIPLOS DE 3 - F3 = ");
	imprima(f3);
	printf("\nF4 = ");
	imprima(f4);

}