/* Lucas de Figueiredo Aguiar - 153. Construa um programa, que use a estrutura pilha e verifique se o n�mero de abre par�nteses � igual
ao n�mero de fecha par�nteses em uma express�o matem�tica. */
#include <stdio.h>
#include <string.h>
#include "153.h"

int main(){
	char exp[100];
	printf("Informe uma expressao matematica:");
	scanf("%[^\n]s", exp);//Expressao matematica em string lendo os espa�os
	tipo_pilha pilha = (tipo_pilha)malloc(sizeof(struct reg_pilha));
	pilha->topo = NULL;
	preenchePilha(exp, pilha);
	if(verificaParenteses(pilha) == 1){
		printf("A Expressao tem o mesmo numero de parenteses");
	}else{
		printf("A Expressao tem um numero diferente de parenteses");
	}
	//Desalocar Pilha
	esvaziarPilha(pilha);
	
	return 0;
}

