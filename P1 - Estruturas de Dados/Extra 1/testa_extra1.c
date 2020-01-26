/* Lucas de Figueiredo Aguiar - Extra 1 - Implementar um tipo abstrato de dados fila contendo as operações enfileirar(enqueue)
desenfileirar(dequeue), além das operações de criar fila, desalocar fila e fila vazia */
#include <stdio.h>
#include "extra1.h"

int main(){
	int opcao, numero;
	tipo_fila *fila;
	fila=criar_fila();

	do{
        printf("\n\n0 - Sair\n");
        printf("1 - Enfileirar(enqueue)\n");
        printf("2 - Desenfileirar(dequeue)\n");
        printf("3 - Exibir dados\n");
        printf("4 - Desalocar lista\n");
        scanf("%d", &opcao);
        switch (opcao){
            case 1: printf("Entre com um numero:");
                    scanf("%d", &numero);
                    incluir_no_fim(fila, numero);
                    break;
            case 2: 
            		if (fila_vazia(fila)==1){
                        printf("\nFila vazia!\n");
                    }else{
                    	excluir_do_inicio(fila);
                    	printf("\nPosicao Desenfileirada!\n");
                        
                    }
            		break;
            case 3: if (fila_vazia(fila)==1){
                        printf("\nFila vazia!\n");
                    }else{
                        listar(fila);
                    }
                    break;
            case 4: if (fila_vazia(fila)==1){
                        printf("\nFila vazia!\n");
                    }else{
                    	desalocar_fila(fila);
                    	printf("\n\nFila Desalocada\n");
					}
					break;
            default:
            		printf("\n\nOpcao Invalida\n");
            		break;
        }
    }while(opcao != 0);

	return 0;
}
