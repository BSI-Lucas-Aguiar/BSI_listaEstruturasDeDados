/* 5. Prepare um algoritmo para calcular  o espaço percorrido por um móvel em movimento retilíneo uniforme
dada a seguinte fórmula: S=So+V*T. Inicialmente o algoritmo deverá perguntar ao usuário os valores do espaço inicial(So),
da velocidade(V) e do tempo(T). Após a entrada dos devidos valores estes devem ser substituídos na fórmula,
resultando assim no espaço percorrido(S) que deverá ser informado na tela do usuário. */
#include <stdio.h>

int main(){
	float S, So, V, T;
	
	printf("Informe o valor do espaço inicial(So): ");
	scanf("%f", &So);
	printf("\nInforme o valor da velocidade(V): ");
	scanf("%f", &V);
	printf("\nInforme o valor do tempo(T): ");
	scanf("%f", &T);
	
	S=So+V*T;
	
	printf("\n\nEspaço percorrido: %.2f", S);
	
	return 0;
}
