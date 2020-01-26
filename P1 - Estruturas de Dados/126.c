/*126. Descubra (e imprima) o valor da maior variável do exercício anterior,
através da função maior, cujos parâmetros devem ser m e n. */

#include<stdio.h>

int maior(int m, int n){
	int resultado;
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

	maior(m, n);
	printf("\n%d %d", m, n);
	return 0;
}
