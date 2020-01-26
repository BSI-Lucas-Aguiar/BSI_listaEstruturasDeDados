/* Lucas de Figueireo Aguiar - 132. Sabe-se que um número complexo é escrito da forma x + iy, onde i² = -1,
sendo x a sua parte real e y a parte imaginária, ambas representadas por valores reais.
Crie um Tipo Abstrato de Dados (TAD) que represente números complexos com as seguintes funções:
(a) criar um número complexo
(b) destruir um número complexo
(c) soma de dois números complexos;
(d) subtração de dois números complexos;
(e) mutiplicação de dois números complexos;
(f) divisão de dois números complexos; */
#include <stdio.h>
#include "132.h"

int main(){
	num_complexo num1, num2, sum, subtracao, multiplicao, divisao;

	float x1, y1, x2, y2;

	printf("Numero 1:");

	printf("Informe a parte real:");
	scanf("%f", &x1);

	printf("Informe a parte imaginaria:");
	scanf("%f", &y1);

	printf("Numero 2:\n");

	printf("Informe a parte real:");
	scanf("%f", &x2);

	printf("Informe a parte imaginaria:");
	scanf("%f", &y2);

	num1 = cria(x1, y1);
	num2 = cria(x2, y2);

	printf("Numero complexo 1:");
	imprimeNum(num1);

	printf("Numero complexo 2:");
	imprimeNum(num2);

	printf("Soma:");
	sum = soma(num1, num2);
	imprimeNum(sum);

	printf("Subtracao:");
	subtracao = subtrai(num1, num2);
	imprimeNum(subtracao);

	printf("Multiplicacao:");
	multiplicao = multiplica(num1, num2);
	imprimeNum(multiplicao);

	printf("Divisao:");
	divisao = divide(num1, num2);
	imprimeNum(divisao);
	
	return 0;
}

