/*125. Declare duas vari�veis inteiras m e n e dois ponteiros para elas.
Atribua valores para as vari�veis. Descubra qual o maior valor, acessando-as
somente atrav�s dos ponteiros. Imprima esse valor. */

#include<stdio.h>

int main(){
	int m, n;
	int *ptrm, *ptrn;
	
	printf("Informe o valor de m:\n");
	scanf("%d", &m);
	ptrm=&m;
	printf("Informe o valor de n:\n");
	scanf("%d", &n);
	ptrn=&n;
	
	if(*ptrm>*ptrn){
		printf("\nM e o maior valor.");
	}
	if(*ptrn>*ptrm){
		printf("\nN e o maior valor.");
	}
	if(*ptrn==*ptrm){
		printf("\nOs valores sao iguais.");
	}
	
	return 0;
}
