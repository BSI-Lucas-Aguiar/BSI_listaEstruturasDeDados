/* 129. O que aconteceria se voc� incrementasse os valores dos par�metros, dentro da fun��o?
Quais seriam seus valores dentro da fun��o? E fora dela? Teste e explique por qu�. */

#include<stdio.h>

int maior(int *ptrm, int *ptrn){
	*ptrm+=1;
	*ptrn+=1;
	if(*ptrm>*ptrn){
		printf("\nM e o maior valor: ");
		printf("%d", *ptrm);
	}
	if(*ptrn>*ptrm){
		printf("\nN e o maior valor: ");
		printf("%d", *ptrn);
	}
	if(*ptrn==*ptrm){
		printf("\nOs valores sao iguais: %d e %d", *ptrm, *ptrn);
	}
	return 0;
}/*Quando o valor � incrementado na vari�vel ponteiro ele tamb�m muda em todos os lugares que � chamado,
pois foi alterado diretamente no enrede�o de mem�ria */

int main(){
	int m, n;
	int *ptrm, *ptrn;

	printf("Informe o valor de m:\n");
	scanf("%d", &m);
	ptrm=&m;
	printf("Informe o valor de n:\n");
	scanf("%d", &n);
	ptrn=&n;

	maior(ptrm, ptrn);
	printf("\n%d %d", *ptrm, *ptrn);
	return 0;
}
