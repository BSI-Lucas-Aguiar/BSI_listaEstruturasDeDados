#include <stdlib.h>
#include <stdio.h>

typedef struct reg_no{
    int dado;
    struct reg_no *proximo;
} tipo_no;

typedef struct reg_lista{
    struct reg_no *inicio;
} tipo_lista;

//136 aloca e inicia a lista chamada na main
tipo_lista* criar_lista(){
    tipo_lista *lista;
    lista = (tipo_lista*) malloc(sizeof(tipo_lista));
    lista->inicio = NULL;
    return lista;
}
//Case 11 - Verifica se a lista possui elementos
int lista_vazia(tipo_lista *lista){
    if (lista->inicio == NULL)
    {
        return 1;
    }
    return 0;
}
//Inclui dado no inicio da lista
void incluir_no_inicio(tipo_lista *lista, int numero){
    tipo_no *novo;
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = numero;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
}
//Inclui dado no fim da lista
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
//Case 1 - Imprime toda a lista
void listar(tipo_lista *lista){
    tipo_no *atual;
    atual = lista->inicio;
    printf("\n");
    while (atual != NULL){
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
}
//Exclui o valor que esta na primeira posicao da lista
void excluir_do_inicio(tipo_lista *lista){
    tipo_no *auxiliar = NULL;
    if (lista->inicio != NULL){
        auxiliar = lista->inicio;
        lista->inicio = auxiliar->proximo;
        free(auxiliar);
    }
}
//Exclui toda a lista, chamado ao finalizar o programa
tipo_lista* excluir_lista(tipo_lista *lista){
    while (!lista_vazia(lista)){
        excluir_do_inicio(lista);
    }
    free(lista);
    return NULL;
}
//Exclui o elemento ao fim da lista
int excluir_do_fim(tipo_lista *lista){
    tipo_no *atual = lista->inicio, *anterior = NULL;
    if(lista_vazia(lista)) return 1;
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
//Inclui um novo elemento na lista de maneira ordenada
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
//146 - Exclui um valor especifico, somente o primeiro que for encontrado com este valor
int excluir_especifico(tipo_lista *lista, int numero){
    tipo_no *atual, *anterior;

	atual = lista->inicio;
	anterior = NULL;

    while((atual!=NULL) && (numero!=atual->dado)){
        anterior = atual;
        atual = atual-> proximo;
    }
    if (anterior==NULL){
        lista->inicio = atual->proximo;
        free(atual);
		return  0;
    }
    if(atual != NULL){
        anterior->proximo = atual->proximo;
        free(atual);
		return 0;
    }
}
//Case 8 - 136 Retorno o tamanho da lista para a main
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
//Case 9 - 136 - Informa a média aritmetica da lista, soma de todos os valores/numero de elementos
float media_aritmetica(tipo_lista *lista){
    int contador_da_lista = 0;
    float resultado = 0;
    tipo_no* atual;

    atual = lista -> inicio;

    while (atual != NULL){
        contador_da_lista++;
        resultado += atual -> dado;
        atual = atual -> proximo;
    }
    resultado = resultado/contador_da_lista;
    return resultado;
}
//Case 10 - Desaloca todos os valores da lista, mantendo somente a lista vazia
int desalocar_nos(tipo_lista *lista){
    tipo_no *auxiliar = NULL;
    while(!lista_vazia(lista)){
        auxiliar = lista->inicio;
        lista->inicio = auxiliar->proximo;
        free(auxiliar);
    }
    return 0;
}
//Case 12 - 137 - Profundidade
int profundidade_lista(tipo_lista *lista, int numero){
	int contador_da_lista = 0;
    tipo_no* atual;

    atual = lista -> inicio;

    while (atual != NULL){
        contador_da_lista++;
		if(atual->dado==numero){
			return contador_da_lista;
		}
        atual = atual -> proximo;
    }
}
//Case 13 - 138 - Crescente
int verificar_crescente(tipo_lista *lista){
	tipo_no *atual;
    atual = lista->inicio;

    while (atual != NULL){
    	if((atual->proximo!=NULL)&&atual->dado>atual->proximo->dado){
    		return 0;
		}
        atual = atual->proximo;
    }
	return 1;
}
//Case 14 - 139 - Criar vetor com elementos da lista
int* cria_vetor(tipo_lista *lista, int tamanho){
	int *vetor, i=0;
	vetor=(int *)malloc(tamanho*sizeof(int));

	if (lista_vazia(lista)==1){
		vetor = NULL;
		return vetor;
	}else{
	tipo_no* atual;

    atual = lista -> inicio;

    while (atual != NULL){
		vetor[i]=atual->dado;
        atual = atual -> proximo;
        i++;
    }
    return vetor;
	}

}
//Case 15 - 140 - Busca endereco
tipo_no* busca_endereco(tipo_lista *lista, int numero){
	tipo_no* atual;

    atual = lista -> inicio;

    while (atual != NULL){
		if(atual->dado==numero){
			return atual;
		}
        atual = atual -> proximo;
    }
}
//Case 16 - 141 - Busca minimo
int busca_minimo(tipo_lista *lista){
	tipo_no* atual;
	int menor;

    atual = lista -> inicio;
	menor = atual->dado;
    while (atual != NULL){
		if((menor)>(atual->dado)){
			menor=atual->dado;
		}
        atual=atual -> proximo;
    }
	return menor;
}
//Case 17 - 146 O usuario informa um valor e todos iguais sao excluidos da lista
void excluir_especifico_todos(tipo_lista *lista, int numero){
	tipo_no *atual, *anterior;

	atual = lista->inicio;
	anterior = NULL;

    while((atual!=NULL)){
    	if(numero==atual->dado){
    		if (anterior==NULL){
        		lista->inicio = atual->proximo;
        		free(atual);
        		atual=lista->inicio;
		    }else if(atual != NULL){
		        anterior->proximo = atual->proximo;
		        free(atual);
		        atual=anterior->proximo;
		    }
		}else{
			anterior = atual;
        	atual = atual-> proximo;
		}
    }
}
//Case 18 - 147 Excluir os dados de uma posicao especifica
int exclui_posicao(tipo_lista *lista, int numero){
	tipo_no *atual, *anterior;
	int contador_da_lista=1;

	atual = lista->inicio;
	anterior = NULL;

    while((atual!=NULL) && (numero!=contador_da_lista)){
        anterior = atual;
        atual = atual-> proximo;
        contador_da_lista++;
    }
    if (anterior==NULL){
        lista->inicio = atual->proximo;
        free(atual);
		return  0;
    }
    if(atual != NULL){
        anterior->proximo = atual->proximo;
        free(atual);
		return 0;
    }
}

//Case 19 - 145 Inverter a posicao dos elementos na lista
void inverte_lista(tipo_lista *lista){
    tipo_no *atual;
    tipo_no *final;
	atual = lista->inicio;

	int tam = 0;
	int i = 0;

	while(atual != NULL){
		i++;
		if(atual->proximo == NULL){
			final = atual;
		}
		atual = atual->proximo;
	}

	tam = i;
	i = 1;

	atual = lista->inicio;

	while(i <= tam){
		if(tam == 1){
			atual->proximo = NULL;
			break;
		}
		if(i == tam-1){
			atual->proximo->proximo = atual;
			atual = lista->inicio;
			i = 1;
			tam--;
		}else{
			atual = atual->proximo;
			i++;
		}

	}
	lista->inicio = final;
}
