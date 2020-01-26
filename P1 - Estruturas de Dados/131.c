/* Lucas de Figueiredo Aguiar - 131. Implemente uma fun��o que receba um vetor de inteiros (vet) de tamanho n.
Essa fun��o deve alocar din�micamente um outro vetor tamb�m de tamanho n que contenha os
endere�os dos valores do vetor de inteiros de forma ordenada crescente, ficando a
primeira posi��o do vetor de ponteiros o endere�o do menor valor at� a �ltima posi��o,
que conter� o endere�o do maior valor. Essa fun��o deve obedecer ao prot�tipo: int**inverte2 (int n, int* vet); */

#include <stdio.h>
#include<stdlib.h>

//Aloca��o dinamica usando malloc, a ordena��o foi feita utilizando bubblesort
int** aloca_e_ordena(int n, int **vet_ordenado, int vetor[]){
	int i, j, *aux;
	vet_ordenado = (int **) malloc(sizeof(int*) * n);
	
	//Recebimento dos valores originais no vetor dinamicamente alocado
	for(i=0; i<n; i++){
		vet_ordenado[i]=&vetor[i];
	}
	
	//Ordena��o
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
	
	//Impress�o do vetor 1, sem altera��o
	printf("\nVetor digitado: ");
	for(i=0; i<n; i++){
		printf("\nPosicao:%d Valor:%d ", i, vet[i]);
	}
	
	//Chamada da fun��o
	vet_ordenado=aloca_e_ordena(n, vet_ordenado, vet); //Aloca dinamicamente as posicoes e ordena
	
	//Impressao do vetor de ponteiros
	printf("\n\nVetor de ponteiros:");
	for(i=0; i<n; i++){
		printf("\nPosicao:%d Valor:%d Endereco:%p", i, *(*(vet_ordenado+i)), *(vet_ordenado+i));
	}
	
	return 0;
}
