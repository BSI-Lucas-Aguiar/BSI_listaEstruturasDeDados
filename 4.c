/* 4. Faça um algoritmo para ler valores para as variáveis A e B, e efetuar a troca dos valores de forma que,
a variável A passe a possuir o valor da variável B e que a variável B passe a possuir o valor da variável A.
Apresentar os valores trocados. */
#include <stdio.h>

int main(){
	int A, B, C;
	
	printf("Informe o valor de A: ");
	scanf("%d", &A);
	printf("\nInforme o valor de B: ");
	scanf("%d", &B);
	
	printf("\n\nAntes da troca:\nA: %d\nB: %d", A, B);
	C=B;
	B=A;
	A=C;
	printf("\n\nApós a troca:\nA: %d\nB: %d", A, B);
	
	return 0;
}
