/* 129. O que aconteceria se você incrementasse os valores dos parâmetros, dentro da função?
Quais seriam seus valores dentro da função? E fora dela? Teste e explique por quê. */

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
}/*Quando o valor é incrementado na variável ponteiro ele também muda em todos os lugares que é chamado,
pois foi alterado diretamente no enredeço de memória */

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
