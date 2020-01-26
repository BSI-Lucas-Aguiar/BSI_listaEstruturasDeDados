#include <stdio.h>
#include "134.h"

int main(){
	int escolha=0, numerador, denominador;
	racional *numero, *numero2, *soma, *mult;
	do{
		printf("Informe uma opcao:\n1-Cria racional\n2-Soma racionais\n3-Multiplica racionais\n4-Testa se são iguais\n0-Sair\n");
		scanf("%d", &escolha);
		switch(escolha){
			case 1:
				printf("\nCriar racional:");
				printf("\nInforme o numerador:\n");
				scanf("%d", &numerador);
				printf("\nInforme o denominador:\n");
				scanf("%d", &denominador);

				numero=cria_racional(numerador, denominador);
				imprime_dados(numero);

				printf("\nInforme o numerador:\n");
				scanf("%d", &numerador);
				printf("\nInforme o denominador:\n");
				scanf("%d", &denominador);

				numero2=cria_racional(numerador, denominador);
				imprime_dados(numero2);

				break;
				
			case 2:
				printf("\nSomar racionais:\n");

				soma=soma_racionais(numero, numero2);

				printf("\nValor somado:");
				imprime_dados(soma);

				break;
				
			case 3:
				printf("\nMultiplica racionais:\n");

				mult=multiplica_racionais(numero, numero2);

				printf("\nValor multiplicado:");
				imprime_dados(mult);

				break;
				
			case 4:
				printf("\nTesta se sao iguais:\n");

				if(testa_igualdade(numero, numero2)==1){
					printf("\nOs valores sao iguais\n\n");
				}else{
					printf("\nOs valores NAO sao iguais\n\n");
				}

				break;
				
			case 0:
				printf("\nSair do programa.\n");
				break;
				
			default:
				printf("\nOpcao Invalida\n");
		}
	}while(escolha!=0);

	return 0;
}
