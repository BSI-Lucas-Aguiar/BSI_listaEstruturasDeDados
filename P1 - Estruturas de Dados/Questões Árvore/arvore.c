//Lucas de Figueiredo Aguiar - Estruturas de dados P2
#include<stdio.h>
#include<stdlib.h>

typedef struct reg_no
{
    struct reg_no *ptr_esquerda;
    int dado;
    struct reg_no *ptr_direita;
} tipo_no;

void incluir_no(tipo_no **sub_raiz, int dado)
{
    if (*sub_raiz == NULL)
    {
        *sub_raiz = (tipo_no*) malloc(sizeof(tipo_no));
        (*sub_raiz)->dado = dado;
        (*sub_raiz)->ptr_esquerda = NULL;
        (*sub_raiz)->ptr_direita = NULL;
    }
    else
    {
        if (dado < (*sub_raiz)->dado)
        {
            incluir_no(&((*sub_raiz)->ptr_esquerda), dado);
        }
        else
        {
            if (dado > (*sub_raiz)->dado)
            {
                incluir_no(&((*sub_raiz)->ptr_direita), dado);
            }
        }
    }
}

void listar_pre_ordem(tipo_no *sub_raiz)
{
    if (sub_raiz != NULL)
    {
        printf("%d ", sub_raiz->dado);
        listar_pre_ordem(sub_raiz->ptr_esquerda);
        listar_pre_ordem(sub_raiz->ptr_direita);
    }
}

void listar_em_ordem(tipo_no *sub_raiz)
{
    if (sub_raiz != NULL)
    {
        listar_em_ordem(sub_raiz->ptr_esquerda);
        printf("%d ", sub_raiz->dado);
        listar_em_ordem(sub_raiz->ptr_direita);
    }
}

void listar_pos_ordem(tipo_no *sub_raiz)
{
    if (sub_raiz != NULL)
    {
        listar_pos_ordem(sub_raiz->ptr_esquerda);
        listar_pos_ordem(sub_raiz->ptr_direita);
        printf("%d ", sub_raiz->dado);
    }
}

int excluir_maior(tipo_no **sub_raiz)
{
    int dado;
    tipo_no *auxiliar;
    if (*sub_raiz != NULL)
    {
        if ((*sub_raiz)->ptr_direita != NULL)
        {
            return excluir_maior(&((*sub_raiz)->ptr_direita));
        }
        else
        {
            dado = (*sub_raiz)->dado;
            auxiliar = *sub_raiz;
            *sub_raiz = (*sub_raiz)->ptr_esquerda;
            free(auxiliar);
            return dado;
        }
    }
    return -1;
}

int excluir_menor(tipo_no **sub_raiz)
{
    int dado;
    tipo_no *auxiliar;
    if (*sub_raiz != NULL)
    {
        if ((*sub_raiz)->ptr_esquerda != NULL)
        {
            return excluir_menor(&((*sub_raiz)->ptr_esquerda));
        }
        else
        {
            dado = (*sub_raiz)->dado;
            auxiliar = *sub_raiz;
            *sub_raiz = (*sub_raiz)->ptr_direita;
            free(auxiliar);
            return dado;
        }
    }
    return -1;
}

int excluir_valor(tipo_no **sub_raiz, int dado)
{
    tipo_no *auxiliar;
    if ((*sub_raiz) != NULL)
    {
        if (dado < (*sub_raiz)->dado)
        {
            return excluir_valor(&((*sub_raiz)->ptr_esquerda), dado);
        }
        else
        {
            if (dado > (*sub_raiz)->dado)
            {
                return excluir_valor(&((*sub_raiz)->ptr_direita), dado);
            }
            else
            {
                if ((*sub_raiz)->ptr_esquerda == NULL)
                {
                    auxiliar = *sub_raiz;
                    *sub_raiz = (*sub_raiz)->ptr_direita;
                    free(auxiliar);
                }
                else
                {
                    if ((*sub_raiz)->ptr_direita == NULL)
                    {
                        auxiliar = *sub_raiz;
                        *sub_raiz = (*sub_raiz)->ptr_esquerda;
                        free(auxiliar);
                    }
                    else
                    {
                        (*sub_raiz)->dado = excluir_maior(&((*sub_raiz)->ptr_esquerda));
                    }
                }
                return dado;
            }
        }
    }
    return -1;
}

//EX 164 - Inclusão na árvore de maneira iterariva - Falta arrumar
void incluir_no_iterativo(tipo_no **sub_raiz, int dado)
{
   while(*sub_raiz != NULL){
		if(dado < (*sub_raiz)->dado){
			sub_raiz=(&(*sub_raiz)->ptr_esquerda);
		}else{ //Sem esse else o programa trava, assim como na recursiva
			if(dado > (*sub_raiz)->dado){
			sub_raiz=(&(*sub_raiz)->ptr_direita);
		}
		}
	}
	*sub_raiz = (tipo_no*) malloc(sizeof(tipo_no));
	(*sub_raiz)-> dado = dado;
	(*sub_raiz)-> ptr_direita = NULL;
	(*sub_raiz)-> ptr_esquerda = NULL;
}


//EX 168 - Verificar se um número está presente na árvore
int verifica_arvore(tipo_no *sub_raiz, int dado){
	int verifica;
	if (sub_raiz != NULL)
    {
    	verifica=sub_raiz->dado; //Verificar direto o primeiro dado não o encontrava, dúvida aqui
        if(verifica==dado){
        	return 1;
		}
		if(dado<sub_raiz->dado){
			verifica_arvore(sub_raiz->ptr_esquerda, dado);
		}
		if(dado>sub_raiz->dado){
			verifica_arvore(sub_raiz->ptr_direita, dado);;
		}
    }
}

//EX 171 - Essa função chama as funções 173 e 175
float calcula_media(tipo_no *sub_raiz){
	float media;
	int soma=0, contador=0;
	soma=calcula_soma(sub_raiz, soma);
	contador=calcula_nos(sub_raiz, contador);

	media=soma/contador;
	return media;
}

//EX 172 - Retorna o número de NULLS presentes na árvore
int calcula_NULL(tipo_no *sub_raiz, int contador){
	if(sub_raiz != NULL){
		contador=calcula_NULL(sub_raiz->ptr_esquerda, contador);
		contador=calcula_NULL(sub_raiz->ptr_direita, contador);
	}else{
		return contador+1;
	}
	return contador;
}

//EX 173 - Fiz somente para auxiliar a questão da média, calcula a soma de todos os dados da árvore
int calcula_soma(tipo_no *sub_raiz, int soma){
	if (sub_raiz != NULL)
    {
    	soma+=sub_raiz->dado;
    	soma=calcula_soma(sub_raiz->ptr_esquerda, soma);
		soma=calcula_soma(sub_raiz->ptr_direita, soma);
    }
 	return soma;
}

//EX 174 - Retorna quantos números presentes na árvore são múltiplos de 3
int calcula_multiplos3(tipo_no *sub_raiz, int contador){
	if (sub_raiz != NULL)
    {
    	if((sub_raiz->dado%3)==0){
			contador++;
		}
		contador=calcula_multiplos3(sub_raiz->ptr_esquerda, contador);
		contador=calcula_multiplos3(sub_raiz->ptr_direita, contador);
    }
	return contador;
}

//EX 175 - Retornar quantos nós a árvore possui
int calcula_nos(tipo_no *sub_raiz, int contador){
	if (sub_raiz != NULL)
    {
        contador++;
		contador=calcula_nos(sub_raiz->ptr_esquerda, contador);
		contador=calcula_nos(sub_raiz->ptr_direita, contador);
    }

	return contador;
}

//EX 176 - Retorna quantos nós folha a árvore possui
int calcula_folha(tipo_no *sub_raiz, int contador){
	if(sub_raiz==NULL){
		return 0;
	}
	if (sub_raiz != NULL)
    {
    	if((sub_raiz->ptr_direita == NULL)&&(sub_raiz->ptr_esquerda == NULL)){
    		contador++;
		}
        if(sub_raiz->ptr_esquerda != NULL){
    		contador=calcula_folha(sub_raiz->ptr_esquerda, contador);
		}
		if(sub_raiz->ptr_direita != NULL){
    		contador=calcula_folha(sub_raiz->ptr_direita, contador);
		}
    }

	return contador;
}

//EX 177 - Retorna a altura da árvore, caso retire o +1 ela retorna em níveis(0, 1)
int altura_arvore(tipo_no *sub_raiz){
	if((sub_raiz) == NULL){
		return 0;
	}

    int altura_esquerda = altura_arvore((sub_raiz)->ptr_esquerda);
    int altura_direita = altura_arvore((sub_raiz)->ptr_direita);

    if (altura_esquerda > altura_direita){
        return (altura_esquerda+1);
    }else{
        return (altura_direita+1);
    }
}

//EX 178 - Retorna se a árvore é estritamente binária, se todos os seus nós são folha ou apontam para outros 2 nós
int estritamente_binaria(tipo_no *sub_raiz){
	if(sub_raiz==NULL){
		return 0;
	}else{
		if((sub_raiz->ptr_esquerda == NULL) && (sub_raiz->ptr_direita == NULL)){
			return 1;
		}else{
			return (estritamente_binaria(sub_raiz->ptr_esquerda)) && (estritamente_binaria(sub_raiz->ptr_direita));
		}
	}
}

//EX179 - Copia a árvore 1 para a árvore 2
void copiar_arvore(tipo_no *sub_raiz, tipo_no **sub_raiz2){
	if (sub_raiz != NULL){
        *sub_raiz2 = (tipo_no*) malloc(sizeof(tipo_no));
		(*sub_raiz2)->dado = sub_raiz->dado;
		(*sub_raiz2)->ptr_direita = NULL;
		(*sub_raiz2)->ptr_esquerda = NULL;

        copiar_arvore(sub_raiz->ptr_esquerda,(&(*sub_raiz2)->ptr_esquerda));
        copiar_arvore(sub_raiz->ptr_direita,(&(*sub_raiz2)->ptr_direita));
    }
}
