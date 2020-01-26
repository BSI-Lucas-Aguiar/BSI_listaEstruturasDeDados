#include <stdlib.h>
#include <math.h>

typedef struct complexo{
	float x, y;
}*num_complexo;

num_complexo cria(float x, float y){
	num_complexo num = malloc(sizeof(num_complexo));

	num->x=x;
	num->y=y;

	return num;
}//Retorna o numero preenchido e dinamicamente alocado

num_complexo destroi(num_complexo num){
	free(num);
	return NULL;
}//"Limpa" o numero complexo

num_complexo soma(num_complexo num1, num_complexo num2){

	num_complexo soma = malloc(sizeof(num_complexo));

	soma->x = num1->x + num2->x;
	soma->y = num1->y + num2->y;

	return soma;
}

num_complexo subtrai(num_complexo num1, num_complexo num2){
	num_complexo sub = malloc(sizeof(num_complexo));

	sub->x = num1->x - num2->x;
	sub->y = num1->y - num2->y;

	return sub;
}

num_complexo multiplica(num_complexo num1, num_complexo num2){
	num_complexo mult = malloc(sizeof(num_complexo));

	mult->x = (num1->x * num2->x) + (-1 * (num1->y * num2->y));
	mult->y = (num1->x * num2->y) + (num1->y * num2->x);

	return mult;
}

num_complexo divide(num_complexo num1, num_complexo num2){

	num_complexo div = malloc(sizeof(num_complexo));

	float x = (num1->x * num2->x) + (-1 * (num1->y * (-1 * num2->y)));

	float y = (num1->x * (-1 * num2->y)) + (num1->y * num2->x);

	float n = pow(num2->x, 2) - ((-1)*pow(num2->y, 2));

	div->x = x/n;
	div->y = y/n;

	return div;
}

void imprimeNum(num_complexo num){
	printf("%.1f ", num->x);
	if(num->y > 0){
		printf("+ %.2f", num->y);
	}else if(num->y < 0){
		printf("%.2f", num->y);
	}
	printf("\n");
}
