/* 9. Uma crian�a quer saber qual � a soma de todas as idades que ela j� teve.
Elaborar programa que l� uma idade qualquer e responde rapidamente a essa pergunta
( f�rmula para calcular a soma dos N primeiros n�meros inteiros: N (N+1)/2 ). */
#include <stdio.h>

int main(){
	int idade, total;
	
	printf("Informe sua idade atual: ");
	scanf("%d", &idade);
	
	total=(idade*(idade+1))/2;
	
	printf("\nO total e: %d", total);
	
	return 0;
}
