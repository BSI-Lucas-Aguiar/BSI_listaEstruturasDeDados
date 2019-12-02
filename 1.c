/* 1. Leia um valor de temperatura em graus Celsius e converta-o em graus Fahrenheit e Kelvin.
A fórmula de conversão é:
F = (9C + 160) / 5
K = C + 273 */
#include <stdio.h>

int main(){
	float c, f, k;
	
	printf("Informe a temperatura em celsius: ");
	scanf("%f", &c);
	
	printf("\n\nCelcius: %.0f", c);
	f=(((9*c)+160)/5);
	printf("\nFarenheit: %.0f", f);
	k=c+273;
	printf("\nKelvin: %.0f", k);
	
	return 0;
}
