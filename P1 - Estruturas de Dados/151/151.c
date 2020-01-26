#include <stdlib.h>

typedef struct reg_elem{
	int num;
	struct reg_elem *proximo;
}tipo_elem;

typedef struct reg_pilha{
	tipo_elem topo;
}tipo_pilha;

tipo_pilha criaPilha(){
	tipo_pilha pilha = (tipo_pilha)malloc(
	sizeof(struct reg_pilha));
	pilha->topo = NULL;
	return pilha;
}
//Push
void inserePilha(int num, tipo_pilha pilha){
	tipo_elem novo = (tipo_elem)malloc(sizeof(struct reg_elem));
	novo->num = num;
	if(pilha->topo == NULL){
		novo->proximo = NULL;
		pilha->topo = novo;
	}
	else{
		novo->proximo = pilha->topo;
		pilha->topo = novo;
	}
}
//Pop
int removeElemento(tipo_pilha pilha){
	if(pilha->topo != NULL){
		int num;
		num = pilha->topo->num;
		tipo_elem auxiliar;
		auxiliar = pilha->topo;
		pilha->topo = pilha->topo->proximo;
		free(auxiliar);
		auxiliar = NULL;
		return num;
	}
}

int comparaPilha(tipo_pilha pilha1, tipo_pilha pilha2){
	
	if(pilha1->topo == NULL && pilha2->topo == NULL){
		return 1;
	}else if((pilha1->topo != NULL && pilha2->topo == NULL) || (pilha1->topo == NULL && pilha2->topo != NULL)){
		return 0;
	}else{
		tipo_elem atual1, atual2;
		
		int num1, num2;
		
		atual1 = pilha1->topo;
		atual2 = pilha2->topo;
		
		while(pilha1->topo != NULL && pilha2->topo != NULL){
			num1 = removeElemento(pilha1);
			num2 = removeElemento(pilha2);
			if(num1 != num2){
				return 0;
			}
		} 
		if(pilha1->topo == NULL && pilha2->topo == NULL){
			return 1;
		}else{
			return 0;
		}
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
