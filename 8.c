/* 8. Implemente um programa que lê três valores e calcule a média ponderada para pesos 1, 2 e 3,
respectivamente (multiplique cada nota pelo seu peso, some os produtos e divida o resultado pela soma dos pesos). */
#include <stdio.h>

int main(){
	float nota1, nota2, nota3, media;
	
	printf("Informe a nota 1: ");
	scanf("%f", &nota1);
	printf("Informe a nota 2: ");
	scanf("%f", &nota2);
	printf("Informe a nota 3: ");
	scanf("%f", &nota3);
	
	media=(nota1*1+nota2*2+nota3*3)/6;
	
	printf("\nA media e: %.2f", media);
	
	return 0;
}
