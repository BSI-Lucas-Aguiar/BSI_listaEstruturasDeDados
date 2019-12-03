/* 10.Dado o peso e a altura do usuário imprima seu Índice de Massa Corporal. IMC = peso / altura 2 */
#include <stdio.h>

int main(){
	float peso, altura, imc;
	
	printf("Informe o seu peso: ");
	scanf("%f", &peso);
	printf("Informe o sua altura: ");
	scanf("%f", &altura);
	
	imc=peso/(altura*altura);
	
	printf("\nIMC: %.2f", imc);
	
	return 0;
}
