/* Lucas de Figueiredo Aguiar - 151. Desenvolva um algoritmo para testar se duas pilhas P1 e P2 são iguais.
Duas pilhas são guais se possuem os mesmos elementos, na mesma ordem.
Sua função deverá retornar 1 para p1 == p2 e 0 para p1 != p2. */
#include <stdio.h>
#include "151.h"

int main(){
	int num;
	
	tipo_pilha pilha1 = criaPilha();
	tipo_pilha pilha2 = criaPilha();
	
	do{
		printf("Pilha 1 - Informe um valor (Informe 0 para parar):");
		scanf("%d", &num);
		getchar();
		if(num != 0){
			inserePilha(num, pilha1);
		}
	
	}while(num != 0);
	
	do{
		printf("Pilha 2 - Informe um valor (Informe 0 para parar):");
		scanf("%d", &num);
		getchar();
		if(num != 0){
			inserePilha(num, pilha2);
		}
	
	}while(num != 0);
	
	if(comparaPilha(pilha1, pilha2) == 1){
		printf("As Pilhas sao iguais");
	}else{
		printf("As Pilhas sao diferentes");
	}
	//Desalocar as pilhas
	esvaziarPilha(pilha1);
	esvaziarPilha(pilha2);
	
	pilha1 = NULL;
	pilha2 = NULL;

	return 0;
}
