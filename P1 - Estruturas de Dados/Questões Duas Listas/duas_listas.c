#include <stdlib.h>

typedef struct reg_no{
    int dado;
    struct reg_no *proximo;
} tipo_no;

typedef struct reg_lista{
    struct reg_no *inicio;
} tipo_lista;

//Urilizado para criar as duas listas
tipo_lista* criar_lista(){
    tipo_lista *lista;
    lista = (tipo_lista*) malloc(sizeof(tipo_lista));
    lista->inicio = NULL;
    return lista;
}

//Procedimentos de manipulação das listas
int lista_vazia(tipo_lista *lista){
    if (lista->inicio == NULL)
    {
        return 1;
    }
    return 0;
}

void listar(tipo_lista *lista){
    tipo_no *atual;
    atual = lista->inicio;
    printf("\n");
    while (atual != NULL)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
}

void excluir_do_inicio(tipo_lista *lista){
    tipo_no *auxiliar = NULL;
    if (lista->inicio != NULL){
        auxiliar = lista->inicio;
        lista->inicio = auxiliar->proximo;
        free(auxiliar);
    }
}

int excluir_do_fim(tipo_lista *lista){
    tipo_no *atual = lista->inicio, *anterior = NULL;
    if(lista_vazia(lista)==1){
    	return 1;
	}
    if(atual->proximo==NULL){
        free(atual);
        lista->inicio = NULL;
        return 0;
    }
    while(atual->proximo != NULL){
        anterior = atual;
        atual = atual->proximo;
    }
    free(atual);
    anterior->proximo = NULL;
    return 0;
}

tipo_lista* excluir_lista(tipo_lista *lista){
    while (lista_vazia(lista)==1){
        excluir_do_inicio(lista);
    }
    free(lista);
    return NULL;
}

int incluir_ordenado(tipo_lista *lista, int numero){
    tipo_no *atual = lista->inicio, *novo = NULL,*anterior=NULL;
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = numero;
    if(lista_vazia(lista)){
        novo->proximo = NULL;
        lista->inicio = novo;
        return 0;
    }
    while((atual!=NULL)  &&  (novo->dado > atual->dado)){
        anterior = atual;
        atual = atual-> proximo;
    }
    if(anterior != NULL){
        anterior-> proximo = novo;
    }
    else{
        lista->inicio = novo;
    }
    novo-> proximo = atual;
    return 0;
}

int tamanho_lista(tipo_lista *lista){
    int contador_da_lista = 0;
    tipo_no* atual;

    atual = lista -> inicio;

    while (atual != NULL){
        contador_da_lista++;
        atual = atual -> proximo;
    }
    return contador_da_lista;

}

//Só para a funcao de copiar listas
void incluir_no_fim(tipo_lista *lista, int numero){
    tipo_no *novo, *atual;
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = numero;
    novo->proximo = NULL;
    if (lista_vazia(lista)){
        lista->inicio = novo;
    }
    else{
        atual = lista->inicio;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}
//Case 10 - Desalocar todos os nos de uma lista
int desalocar_nos(tipo_lista *lista){
    tipo_no *auxiliar = NULL;
    while(lista_vazia(lista)==1){
        auxiliar = lista->inicio;
        lista->inicio = auxiliar->proximo; // ou lista->inicio->proximo;
        free(auxiliar);
    }
    return 0;
}

//142 - Case 9 - Verifica se as listas são iguais
int verifica_igual(tipo_lista *lista1, tipo_lista *lista2){
	tipo_no *atual1, *atual2;
	int igualdade=0;

	atual1=lista1->inicio;
	atual2=lista2->inicio;

	while((atual1->proximo!=NULL)){
		if(atual1->dado==atual2->dado){
			igualdade=1;
		}else{
			igualdade=0;
			return igualdade;
		}
		atual1=atual1->proximo;
		atual2=atual2->proximo;
	}

	return igualdade;
}
//Case 11 - 143 Copiar uma lista
void copia_lista(tipo_lista *lista1, tipo_lista *lista3){
    tipo_no *atual;
	atual = lista1->inicio;
	while(atual != NULL){
		incluir_no_fim(lista3, atual->dado);
		atual = atual->proximo;
	}
}

//Case 12 - 144 Concatena duas listas
int concatena_listas(tipo_lista *lista1, tipo_lista *lista2){
	if(lista1->inicio == NULL){
		lista1->inicio = lista2->inicio;
	}
	else{
		tipo_no *atual;
		atual = lista1->inicio;
		while(atual != NULL){
			if(atual->proximo == NULL){
				atual->proximo = lista2->inicio;
				break;
			}else{
				atual = atual->proximo;
			}
		}
	}
}
//Case 13 - 148 União das listas
void uniao_listas(tipo_lista *lista1, tipo_lista *lista2, tipo_lista *lista4){

	tipo_no *atual;
	tipo_no *atualAux;
	int teste;

	atual = lista1->inicio;

	while(atual != NULL){
		atualAux = lista4->inicio;
		teste = 0;
		if(lista4->inicio == NULL){
			incluir_no_fim(lista4, atual->dado);
		}else{
			while(atualAux != NULL){
				if(atual->dado == atualAux->dado){
					teste = 1;
					break;
				}else{
					atualAux = atualAux->proximo;
				}
			}
			if(teste != 1){
				incluir_no_fim(lista4, atual->dado);
			}
		}

		atual = atual->proximo;
	}

	atual = lista2->inicio;

	while(atual != NULL){
		atualAux = lista4->inicio;
		teste = 0;
		if(lista4->inicio == NULL){
			incluir_no_fim(lista4, atual->dado);
		}else{
			while(atualAux != NULL){
				if(atual->dado == atualAux->dado){
					teste = 1;
					break;
				}else{
					atualAux = atualAux->proximo;
				}
			}
			if(teste != 1){
				incluir_no_fim(lista4, atual->dado);
			}
		}

		atual = atual->proximo;
	}
}

//Case 14 - 149 Intersecao das listas
void intersecao_listas(tipo_lista *lista1, tipo_lista *lista2, tipo_lista *lista5){
	int i, j, valor_anterior;
	tipo_no *atual;
	tipo_no *atualAux;

	atual = lista1->inicio;
	atualAux = lista2->inicio;

	for(i=0; i<tamanho_lista(lista1); i++){

		for(j=0; j<tamanho_lista(lista2); j++){
			if((atual->dado==atualAux->dado)&&(atual->dado!=valor_anterior)){
				incluir_no_fim(lista5, atual->dado);
			}
			valor_anterior=atual->dado;
			atualAux=atualAux->proximo;
		}
		atualAux = lista2->inicio;
		atual=atual->proximo;
	}
}
