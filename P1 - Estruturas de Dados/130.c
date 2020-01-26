/* Lucas de Figueiredo Aguiar - 130. Implemente uma fun��o que receba como par�metro um vetor v de n n�meros inteiros e
retorne um novo vetor w, alocado dinamicamente, cujos elementos s�o definidos pelas f�rmulas:
w[0] = v[0] w[i] = v[i] + w[i - 1] , 0 < i < n
Essa fun��o n�o deve alterar o conte�do do vetor original v e seu prot�tipo deve ser:
int* somatorios (int n, int* v); */

#include <stdio.h>
#include <stdlib.h>
//vetor v representado como vetorV, vetor W como vetorW e n como total_posicoes

//Preenchimento de acordo com os par�metros da quest�o
int* somatorios(int total_posicoes, int vetorV[]){
	int *vetorW;
	vetorW = (int *) malloc(sizeof(int) * total_posicoes);
	int posicao;
	
	for(posicao=0; posicao<total_posicoes; posicao++){
		if(posicao==0){
			vetorW[0]=vetorV[0];
		}else{
			vetorW[posicao]=(vetorV[posicao]+vetorW[posicao-1]);
		}
	}
	return vetorW;
}

int main(){
	int total_posicoes, posicao;
	printf("Quantos elementos ter� o vetor?");
	scanf("%d", &total_posicoes);
	int vetorV[total_posicoes];
	
	for(posicao=0; posicao<total_posicoes; posicao++){
		printf("\nInforme o valor na posicao %d:", posicao);
		scanf("%d", &vetorV[posicao]);
	}
	//Impress�o do vetor V
	printf("\nVetor V: ");
	for(posicao=0; posicao<total_posicoes; posicao++){
		printf("%d ", vetorV[posicao]);
	}
	
	int *vetorW;//Recebe os parametros informados de maneira dinamicamente alocada
	vetorW=somatorios(total_posicoes, vetorV);

	printf("\n\nVetor W:");
	for(posicao=0; posicao<total_posicoes; posicao++){
		printf("\nPosicao:%d Valor:%d Endereco:%p", posicao, *(vetorW+posicao), vetorW+posicao);
	}

	return 0;
}
