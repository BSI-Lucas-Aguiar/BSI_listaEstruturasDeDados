/* 11.Leia o sal�rio mensal atual de um funcion�rio e o percentual de reajuste.
Calcular e escrever o valor do novo sal�rio. */
#include <stdio.h>

int main(){
	float salario, percentual;
	
	printf("Informe o salario atual: ");
	scanf("%f", &salario);
	printf("Informe o percentual de reajuste: ");
	scanf("%f", &percentual);
	
	salario=(salario+(salario/percentual));
	
	printf("\nNovo salario: %.2f", salario);
	
	return 0;
}
