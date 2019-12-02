/* 2. Faça um programa que converta uma medida de metros para centímetros. */
#include <stdio.h>

int main(){
	float metros, centimetros;
	
	printf("Informe a medida em metros: ");
	scanf("%f", &metros);
	
	printf("\nMetros: %.2f", metros);
	centimetros=metros*100;
	printf("\nCentimetros: %.2f", centimetros);
	
	return 0;
}
