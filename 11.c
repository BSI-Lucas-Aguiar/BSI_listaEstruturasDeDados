/* 11.Leia o salário mensal atual de um funcionário e o percentual de reajuste.
Calcular e escrever o valor do novo salário. */
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
