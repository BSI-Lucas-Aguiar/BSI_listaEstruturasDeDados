/* 5. Prepare um algoritmo para calcular  o espa�o percorrido por um m�vel em movimento retil�neo uniforme
dada a seguinte f�rmula: S=So+V*T. Inicialmente o algoritmo dever� perguntar ao usu�rio os valores do espa�o inicial(So),
da velocidade(V) e do tempo(T). Ap�s a entrada dos devidos valores estes devem ser substitu�dos na f�rmula,
resultando assim no espa�o percorrido(S) que dever� ser informado na tela do usu�rio. */
#include <stdio.h>

int main(){
	float S, So, V, T;
	
	printf("Informe o valor do espa�o inicial(So): ");
	scanf("%f", &So);
	printf("\nInforme o valor da velocidade(V): ");
	scanf("%f", &V);
	printf("\nInforme o valor do tempo(T): ");
	scanf("%f", &T);
	
	S=So+V*T;
	
	printf("\n\nEspa�o percorrido: %.2f", S);
	
	return 0;
}
