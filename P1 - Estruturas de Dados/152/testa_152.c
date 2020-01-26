/* Lucas de Figueiredo Aguiar - 152. Faça um programa para inverter a ordem dos elementos existentes em uma string de tamanho máximo 20.
Utilize, obrigatoriamente, uma pilha como memória temporária para armazenar a string. Imprima a string após a inversão. */
#include <stdio.h>
#include "152.h"

int main(){
	char frase[20];
	printf("Informe uma frase:");
	scanf("%[^\n]s", frase);
	tipo_pilha pilha = (tipo_pilha)malloc(sizeof(struct reg_pilha));
	pilha->topo = NULL;
	preenchePilha(frase, pilha);
	inverteFrase(frase, pilha);
	printf("Frase invertida: %s", frase);
	esvaziarPilha(pilha);
	
	return 0;
}
