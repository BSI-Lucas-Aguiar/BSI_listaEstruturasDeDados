#include <stdlib.h>
#include <stdio.h>

typedef struct conj{
	int *vet;
	int tam;
	int pos;
}*conj_int;

int menu(){
	int opcao;
	
	printf("\n1 - Insere elemento\n");
	printf("2 - Exclui elemento\n");
	printf("3 - Listar conjunto\n");
	printf("4 - Testa se um numero pertece ao conjunto\n");
	printf("5 - Retorna menor valor\n");
	printf("6 - Retorna maior valor\n");
	printf("7 - Verificar conjunto vazio\n");
	printf("8 - Retorna tamanho\n");
	printf("9 - Verifica igualdade\n");
	printf("10 - Retorna uniao dos conjuntos\n");
	printf("11 - Retorna interseccao dos conjuntos\n");
	printf("12 - Retorna diferenca dos conjuntos\n");
	printf("0 - Sair");
	scanf("%d", &opcao);
	return opcao;
}

conj_int criaConjunto(int tam){
	conj_int novo_conj = (conj_int)malloc(sizeof(struct conj));
	novo_conj->vet = (int*)malloc(tam * sizeof(int));
	novo_conj->pos = 0;
	novo_conj->tam = tam;
	
	return novo_conj;
}

void listarConjunto(conj_int conj){
	
	if(conj->pos == 0){
		printf("Conjunto vazio\n");
	}
	else{
		printf("Conjunto: ");
		for(int i=0; i<conj->pos; i++){
			printf("%d ", conj->vet[i]);
		}
	}
}

void insereElem(conj_int conj, int x){
	if(conj->pos == conj->tam){
		printf("Conjunto cheio\n");
	}
	else{
		conj->vet[conj->pos] = x;
		conj->pos++;
	}
}
void removeElem(conj_int conj, int x){
	int teste = 0;
	
	int i = 0, j = 0;
	while(i < conj->pos){
		if(conj->vet[i] == x){
			teste  = 1;
			for(j = i; j < (conj->pos - 1); j++){
				conj->vet[j] = conj->vet[j+1];
			}
			conj->pos--;
		}else{
			i++;
		}
			
	}
    if(teste != 1){
		printf("Valor nao encontrado no conjunto\n");
	}
}

int verificaConjuntoVazio(conj_int conj){
	if(conj->pos == 0){
		return 0;
	}else{
		return 1;
	}
}

int testaExistenciaValor(conj_int conj, int x){
	int i;
	for(i = 0; i < conj->pos; i++){
		if(conj->vet[i] == x){
			return 1;
		}
	}
	return 0;
}

int menorValor(conj_int conj){
	int i;
	int menor = conj->vet[0];
	for(i = 0; i < conj->pos; i++){
		if(conj->vet[i] < menor){
			menor = conj->vet[i];
		}
	}
	return menor;
}
int maiorValor(conj_int conj){
	int i;
	int maior = conj->vet[0];
	for(i = 0; i < conj->pos; i++){
		if(conj->vet[i] > maior){
			maior = conj->vet[i];
		}
	}
	return maior;
}

int retornaTamanho(conj_int conj){
	return conj->pos;
}

int verificaIgualdade(conj_int conj1, conj_int conj2){
	if(conj1->pos != conj2->pos){
		return 0;
	}else{
		int i, j, teste = 0;
		
		for(i = 0; i < conj1->pos; i++){
			for(j = 0; j < conj2->pos; j++){
				if(conj1->vet[i] == conj2->vet[j]){
					teste++;
					break;
				}
			}
		}
		
		if(teste == conj1->pos){
			return 1;
		}else{
			return 0;
		}
	}
}

conj_int uneConjuntos(conj_int conj1, conj_int conj2, conj_int uniao){
	free(uniao->vet);
	
	int i, j;
	int teste;
	
	int tamConj1 = conj1->pos;
	int tamConj2 = conj2->pos;
	
	int tamUniao = tamConj1 + tamConj2;
	uniao->vet = (int *)malloc(tamUniao * sizeof(int));
	uniao->tam = tamUniao;
	uniao->pos = 0;
	
	
	for(i = 0; i < conj1->pos; i++){
		teste = 0;
		for(j = 0; j < uniao->pos; j++){
			if(conj1->vet[i] == uniao->vet[j]){
				teste = 1;
			}
		}
		
		if(teste != 1){
			uniao->vet[uniao->pos++] = conj1->vet[i];
		}
	}
	
	for(i = 0; i < conj2->pos; i++){
		teste = 0;
		for(j = 0; j < uniao->pos; j++){
			if(conj2->vet[i] == uniao->vet[j]){
				teste = 1;
			}
		}
		
		if(teste != 1){
			uniao->vet[uniao->pos++] = conj2->vet[i];
		}
	}
	
	uniao->vet = (int *)realloc(uniao->vet, uniao->pos * sizeof(int));
	uniao->tam = uniao->pos;
	
	listarConjunto(uniao);
	
	return uniao;
}

conj_int intersectaConjuntos(conj_int conj1, conj_int conj2, conj_int interseccao){
	free(interseccao->vet);
	
	int i, j, k;
	int teste, teste2;
	
	int tamConj1 = conj1->pos;
	int tamConj2 = conj2->pos;
	
	int tamInterseccao = tamConj1 + tamConj2;
	interseccao->vet = (int *)malloc(tamInterseccao * sizeof(int));
	interseccao->tam = tamInterseccao;
	interseccao->pos = 0;
	
	
	for(i = 0; i < conj1->pos; i++){
		teste = 0;
		for(j = 0; j < conj2->pos; j++){
			if(conj1->vet[i] == conj2->vet[j]){
				teste = 1;
			}
		}
		
		if(teste == 1){
			teste2 = 0;
			for(k = 0; k < interseccao->pos; k++){
				if(interseccao->vet[k] == conj1->vet[i]){
					teste2 = 1;
				}
			}
			
			if(teste2 != 1){
				interseccao->vet[interseccao->pos++] = conj1->vet[i];
			}
		}
	}
	
	interseccao->vet = (int *)realloc(interseccao->vet, interseccao->pos * sizeof(int));
	
	listarConjunto(interseccao);
	
	return interseccao;
}

conj_int diferencaConjuntos(conj_int conj1, conj_int conj2, conj_int diferenca, int idConjunto){
	free(diferenca->vet);
	
	int i, j, k;
	int teste, teste2;
	
	if(idConjunto == 1){
		diferenca->vet = (int *)malloc(conj1->pos * sizeof(int));
		diferenca->pos = 0;
		for(i = 0; i < conj1->pos; i++){
			teste = 0;
			for(j = 0; j < conj2->pos; j++){
				if(conj1->vet[i] == conj2->vet[j]){
					teste = 1;
				}
			}if(teste != 1){
				teste2 = 0;
			    for(k = 0; k < diferenca->pos; k++){
				    if(diferenca->vet[k] == conj1->vet[i]){
				    	teste2 = 1;
				    }
			    }if(teste2 != 1){
			    	diferenca->vet[diferenca->pos++] = conj1->vet[i];
			    }
			}
	    }
	}else{
		diferenca->vet = (int *)malloc(conj2->pos * sizeof(int));
		diferenca->pos = 0;
		for(i = 0; i < conj2->pos; i++){
			teste = 0;
			for(j = 0; j < conj1->pos; j++){
				if(conj2->vet[i] == conj1->vet[j]){
					teste = 1;
				}
			}if(teste != 1){
				teste2 = 0;
			    for(k = 0; k < diferenca->pos; k++){
				    if(diferenca->vet[k] == conj2->vet[i]){
				    	teste2 = 1;
				    }
			    }
			    if(teste2 != 1){
			    	diferenca->vet[diferenca->pos++] = conj2->vet[i];
			    }
			}
	    }
	}
	
	diferenca->vet = (int *)realloc(diferenca->vet, diferenca->pos * sizeof(int));
	diferenca->tam = diferenca->pos;
	
	listarConjunto(diferenca);
	
	return diferenca;
}


