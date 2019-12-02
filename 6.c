/* 6. Leia um número inteiro e imprima o seu antecessor e o seu sucessor.*/
#include <stdio.h>

int main(){
	int numero;
	
	printf("Informe um numero inteiro: ");
	scanf("%d", &numero);
	
	printf("\nNumero: %d\nAnterior: %d\nSucessor: %d", numero, numero-1, numero+1);
	
	return 0;
}
