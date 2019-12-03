/* 13.Escrever um algoritmo que leia um valor e calcule qual o menor número possível de notas e moedas de
100, 50, 20, 10, 5, 2 e 1 em que o valor lido pode ser decomposto. Escrever o valor lido e a relação de notas necessárias. */
#include <stdio.h>

int main(){
	int valor;
	
	printf("Informe o valor total: ");
	scanf("%d", &valor);
	
	int v100 = valor / 100;
	valor = valor - v100 * 100;

	int v50 = valor / 50;
	valor = valor - v50 * 50;

	int v20 = valor / 20;
	valor = valor - v20 * 20;

	int v10 = valor / 10;
	valor = valor - v10 * 10;

	int v5 = valor / 5;
	valor = valor - v5 * 5;

	int v2 = valor / 2;
	valor = valor - v2 * 2;

	int v1 = valor;
	
	printf("\nO numero de notas de 100 e: %d", v100);
	printf("\nO numero de notas de 50  e: %d", v50);
	printf("\nO numero de notas de 20  e: %d", v20);
	printf("\nO numero de notas de 10  e: %d", v10);
	printf("\nO numero de notas de 5   e: %d", v5);
	printf("\nO numero de notas de 2   e: %d", v2);
	printf("\nO numero de moedas de 1  e: %d", v1);
	
	return 0;
}
