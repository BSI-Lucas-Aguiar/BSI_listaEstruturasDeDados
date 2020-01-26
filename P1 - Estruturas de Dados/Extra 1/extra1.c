#include <stdlib.h>

typedef struct reg_no{
    int dado;
    struct reg_no *proximo;
} tipo_no;

typedef struct reg_fila{
    struct reg_no *inicio;
} tipo_fila;

tipo_fila* criar_fila(){
    tipo_fila *fila;
    fila = (tipo_fila*) malloc(sizeof(tipo_fila));
    fila->inicio = NULL;
    return fila;
}

void listar(tipo_fila *fila){
    tipo_no *atual;
    atual = fila->inicio;
    printf("\n");
    while (atual != NULL){
        printf("[%d] ", atual->dado);
        atual = atual->proximo;
    }
}

int fila_vazia(tipo_fila *fila){
    if (fila->inicio == NULL){
        return 1;
    }
    return 0;
}

int desalocar_fila(tipo_fila *fila){
    tipo_no *auxiliar = NULL;
    while(!fila_vazia(fila)){
        auxiliar = fila->inicio;
        fila->inicio = auxiliar->proximo; // ou lista->inicio->proximo;
        free(auxiliar);
    }
    return 0;
}

void incluir_no_fim(tipo_fila *fila, int numero){
    tipo_no *novo, *atual;
    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = numero;
    novo->proximo = NULL;
    if (fila_vazia(fila)){
        fila->inicio = novo;
    }else{
        atual = fila->inicio;
        while (atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

void excluir_do_inicio(tipo_fila *fila){
    tipo_no *auxiliar = NULL;
    if (fila->inicio != NULL)
    {
        auxiliar = fila->inicio;
        fila->inicio = auxiliar->proximo; // ou lista->inicio->proximo;
        free(auxiliar);
    }
}

