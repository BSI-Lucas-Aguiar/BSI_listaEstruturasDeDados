/*128. Descubra (e imprima) o valor da maior vari�vel do exerc�cio anterior, atrav�s da fun��o maior,
cujos par�metros devem ser as vari�veis ponteiros para m e n.*/

#include<stdio.h>

int maior(int *ptrm, int *ptrn){
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
}

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
