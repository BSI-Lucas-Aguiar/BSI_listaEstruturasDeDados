/* 3. Faça um Programa que peça o comprimento a largura e a altura de uma caixa d'água retangular.
Calcule e informe o volume da caixa. */
#include <stdio.h>

int main(){
	float altura, largura, comprimento, volume;
	
	printf("Informe o comprimento: ");
	scanf("%f", &comprimento);
	printf("\nInforme a largura: ");
	scanf("%f", &largura);
	printf("\nInforme a altura: ");
	scanf("%f", &altura);
	
	volume=(comprimento*largura)*altura;
	printf("\n\nVolume: %.2f", volume);
	
	return 0;
}
