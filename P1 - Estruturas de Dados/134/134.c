#include <stdlib.h>
#include <stdio.h>

typedef struct numero{
	int numerador, denominador;

}racional;

racional *cria_racional(int numerador, int denominador){
	racional *valor=(racional *)malloc(sizeof (racional));

	valor->numerador=numerador;
	valor->denominador=denominador;

	return valor;
}

racional *soma_racionais(racional *numero, racional *numero2){
	racional *soma=(racional *)malloc(sizeof (racional));

	soma->numerador=((numero->numerador * numero2->denominador)+(numero->denominador*numero2->numerador));
	soma->denominador=(numero->denominador*numero2->denominador);

	return soma;
}

racional *multiplica_racionais(racional *numero, racional *numero2){
	racional *multiplica=(racional *)malloc(sizeof (racional));
	multiplica->numerador=numero->numerador*numero2->numerador;
	multiplica->denominador=numero->denominador*numero2->denominador;

	return multiplica;
}

int testa_igualdade(racional *numero, racional *numero2){
	if((numero->numerador==numero2->numerador)&&(numero->denominador==numero2->denominador)){
		return 1;
	}else{
		return 0;
	}

}

void imprime_dados(racional *impressao){
	printf("\n%d", impressao->numerador);
	printf("/%d\n", impressao->denominador);
}

