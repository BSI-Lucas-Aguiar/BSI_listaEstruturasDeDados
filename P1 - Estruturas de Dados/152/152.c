#include <stdlib.h>

typedef struct reg_elem{
	char caractere;
	struct reg_elem *proximo;
}tipo_elem;

typedef struct reg_pilha{
	tipo_elem topo;
}tipo_pilha;

void inserePilha(char caractere, tipo_pilha pilha){
	tipo_elem novo = (tipo_elem)malloc(sizeof(struct reg_elem));
	novo->caractere = caractere;
	if(pilha->topo == NULL){
		novo->proximo = NULL;
		pilha->topo = novo;
	}else{
		novo->proximo = pilha->topo;
		pilha->topo = novo;
	}
}

void preenchePilha(char* frase, tipo_pilha pilha){
	int i = 0;
	
	while(frase[i] != '\0'){
		inserePilha(frase[i], pilha);
		i++;
	}
}

void inverteFrase(char* frase, tipo_pilha pilha){
	int i = 0;
	
	tipo_elem atual;
	atual = pilha->topo;
	
	while(frase[i] != '\0' || atual != NULL){
		frase[i] = atual->caractere;
		i++;
		atual = atual->proximo;
	}
}

void esvaziarPilha(tipo_pilha pilha){
	if(pilha->topo != NULL){
		tipo_elem auxiliar, atual;
		atual = pilha->topo;
		while(atual != NULL){
			if(pilha->topo->proximo == NULL){
				free(pilha->topo);
				pilha->topo = NULL;
				break;
			}else{
				auxiliar = atual;
				if(atual->proximo->proximo == NULL){
					free(auxiliar->proximo);
					auxiliar->proximo = NULL;
					atual = pilha->topo;
				}else{
					atual = atual->proximo;
				}
			}
		}
	}
}

    

