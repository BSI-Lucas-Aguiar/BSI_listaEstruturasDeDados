/*127. O que aconteceria se voc� incrementasse os valores dos par�metros, dentro da fun��o?
Quais seriam seus valores dentro da fun��o? E fora dela? Teste e explique por qu�. */

#include<stdio.h>

int maior(int m, int n){
	int resultado;
	m++;
	n++;
	if(m>n){
		printf("\nM e o maior valor: ");
		printf("%d", m);
		resultado=m;
	}
	if(n>m){
		printf("\nN e o maior valor: ");
		printf("%d", n);
		resultado=n;
	}
	if(n==m){
		printf("\nOs valores sao iguais: %d e %d", m, n);
	}
	return 0;
}/*Caso seja incrementado dentro da fun��o ele ter� o valor incrementado na fun��o, na main o valor original � mantido
Para ter os valores modificados na main uma vari�vel teria que receber o retorno do incremento*/

int main(){
	int m, n;
	int *ptrm, *ptrn;

	printf("Informe o valor de m:\n");
	scanf("%d", &m);
	ptrm=&m;
	printf("Informe o valor de n:\n");
	scanf("%d", &n);
	ptrn=&n;

	maior(m, n);
	printf("\nValores Originais:%d %d", m, n);
	return 0;
}
