/* 4. Fa�a um algoritmo para ler valores para as vari�veis A e B, e efetuar a troca dos valores de forma que,
a vari�vel A passe a possuir o valor da vari�vel B e que a vari�vel B passe a possuir o valor da vari�vel A.
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
	printf("\n\nAp�s a troca:\nA: %d\nB: %d", A, B);
	
	return 0;
}
