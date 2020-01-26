//Lucas de Figueiredo Aguiar
#include <stdio.h>
#include "135.h"

int main(){
	area *cilindro;
	float raio, altura;

	printf("\nInforme o raio:\n");
	scanf("%f", &raio);
	printf("\nInforme a altura:\n");
	scanf("%f", &altura);

	cilindro=preenche_cilindro(cilindro, raio, altura);
	printf("\nRaio: %.2f", raio);
	printf("\nAltura: %.2f", altura);

	printf("\nArea total: %.2f", preenche_area(cilindro));
	printf("\nVolume: %.2f", preenche_volume(cilindro));

	return 0;
}
