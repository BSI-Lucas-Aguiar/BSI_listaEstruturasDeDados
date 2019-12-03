/* 9. Uma criança quer saber qual é a soma de todas as idades que ela já teve.
Elaborar programa que lê uma idade qualquer e responde rapidamente a essa pergunta
( fórmula para calcular a soma dos N primeiros números inteiros: N (N+1)/2 ). */
#include <stdio.h>

int main(){
	int idade, total;
	
	printf("Informe sua idade atual: ");
	scanf("%d", &idade);
	
	total=(idade*(idade+1))/2;
	
	printf("\nO total e: %d", total);
	
	return 0;
}
