/* Lucas de Figueiredo Aguiar - 131. Implemente uma função que receba um vetor de inteiros (vet) de tamanho n.
Essa função deve alocar dinâmicamente um outro vetor também de tamanho n que contenha os
endereços dos valores do vetor de inteiros de forma ordenada crescente, ficando a
primeira posição do vetor de ponteiros o endereço do menor valor até a última posição,
que conterá o endereço do maior valor. Essa função deve obedecer ao protótipo: int**inverte2 (int n, int* vet); */

#include <stdio.h>
#include<stdlib.h>

//Alocação dinamica usando malloc, a ordenação foi feita utilizando bubblesort
int** aloca_e_ordena(int n, int **vet_ordenado, int vetor[]){
	int i, j, *aux;
	vet_ordenado = (int **) malloc(sizeof(int*) * n);
	
	//Recebimento dos valores originais no vetor dinamicamente alocado
	for(i=0; i<n; i++){
		vet_ordenado[i]=&vetor[i];
	}
	
	//Ordenação
	for(i=0; i<n; i++){
		for(j=0; j<n-1; j++){
			if(*vet_ordenado[j]>*vet_ordenado[j+1]){
				aux=vet_ordenado[j];
				vet_ordenado[j]=vet_ordenado[j+1];
				vet_ordenado[j+1]=aux;
			}	
		}
	}
	
	return vet_ordenado;
}

int main(){
	int n,i;
	printf("Informe o tamanho do vetor:");
	scanf("%d", &n);
	int vet[n], **vet_ordenado;
	
	//Preenchimento do vetor 1
	for(i=0; i<n; i++){
		printf("\nInforme o valor da posicao %d:", i);
		scanf("%d", &vet[i]);
	}
	
	//Impressão do vetor 1, sem alteração
	printf("\nVetor digitado: ");
	for(i=0; i<n; i++){
		printf("\nPosicao:%d Valor:%d ", i, vet[i]);
	}
	
	//Chamada da função
	vet_ordenado=aloca_e_ordena(n, vet_ordenado, vet); //Aloca dinamicamente as posicoes e ordena
	
	//Impressao do vetor de ponteiros
	printf("\n\nVetor de ponteiros:");
	for(i=0; i<n; i++){
		printf("\nPosicao:%d Valor:%d Endereco:%p", i, *(*(vet_ordenado+i)), *(vet_ordenado+i));
	}
	
	return 0;
}
