/* Lucas de Figueireo Aguiar - 132. Sabe-se que um n�mero complexo � escrito da forma x + iy, onde i� = -1,
sendo x a sua parte real e y a parte imagin�ria, ambas representadas por valores reais.
Crie um Tipo Abstrato de Dados (TAD) que represente n�meros complexos com as seguintes fun��es:
(a) criar um n�mero complexo
(b) destruir um n�mero complexo
(c) soma de dois n�meros complexos;
(d) subtra��o de dois n�meros complexos;
(e) mutiplica��o de dois n�meros complexos;
(f) divis�o de dois n�meros complexos; */
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

