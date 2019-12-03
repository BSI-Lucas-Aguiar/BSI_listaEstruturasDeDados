/* 7. Prepare um algoritmo para informar o total gasto em uma lavanderia.
O algoritmo inicialmente deverá perguntar o total de camisas, o total de calças e o total de meias e informar o total gasto,
levando em conta a seguinte tabela de preços: Camisas: 5.00 Calças:10.00 Meias:2.00 */
#include <stdio.h>

int main(){
	int camisas, calcas, meias;
	float total;
	
	printf("Informe a quantidade de camisas: ");
	scanf("%d", &camisas);
	printf("Informe a quantidade de calcas: ");
	scanf("%d", &calcas);
	printf("Informe a quantidade de meias: ");
	scanf("%d", &meias);
	
	total=camisas*5+calcas*10+meias*2;
	
	printf("\n\nO total a pagar e: %.2f", total);
	
	return 0;
}
