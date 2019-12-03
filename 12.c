/* 12.Leia a idade de uma pessoa expressa em anos, meses e dias e escreva a idade dessa pessoa expressa apenas em dias.
Considerar ano com 365 dias e mês com 30 dias. */
#include <stdio.h>

int main(){
	int anos, meses, dias, totaldias;
	
	printf("Informe os anos: ");
	scanf("%d", &anos);
	printf("Informe os meses: ");
	scanf("%d", &meses);
	printf("Informe os dias: ");
	scanf("%d", &dias);
	
	totaldias=(anos*365)+(meses*30)+dias;
	
	printf("\nIdade em dias: %d", totaldias);

	return 0;
}
