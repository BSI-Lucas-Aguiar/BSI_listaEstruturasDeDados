//Lucas de Figueiredo Aguiar - Estruturas de dados P2
#include<stdio.h>
#include "arvore.h"

int main()
{
    tipo_no *raiz = NULL, *raiz2 = NULL;
    int dado, opcao, resultado_exclusao, verifica, contador, soma;
    float media;

    do
    {
        printf("\n\n0 - Sair\n");
        printf("1 - Incluir na arvore - Recursivo\n");
        printf("2 - Listar Pre-ordem\n");
        printf("3 - Listar em ordem\n");
        printf("4 - Listar Pos-ordem\n");
        printf("5 - Excluir maior\n");
        printf("6 - Excluir menor\n");
        printf("7 - Excluir valor especifico\n");
        printf("8 - Incluir na arvore - Iterativo\n"); //EX 164
        printf("9 - Verificar se um valor n esta na arvore\n"); //EX 168
        printf("10 - Calcular media dos valores na arvore\n"); //EX 171
        printf("11 - Numero de NULLS\n"); //EX 172
        printf("12 - Numero de nos multiplos de 3\n"); //EX 174
        printf("13 - Numero de nos na arvore\n"); //EX 175
        printf("14 - Numero de nos folha na arvore\n"); // EX 176
        printf("15 - Altura da arvore\n"); //EX 177
        printf("16 - Estritamente Binaria\n"); //EX 178
        printf("17 - Copiar Arvore\n"); //EX 179
        printf("Entre com a sua opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1: printf("Entre com um valor:");
                    scanf("%d", &dado);
                    incluir_no(&raiz, dado);
                    break;
            case 2: listar_pre_ordem(raiz);
                    break;
            case 3: listar_em_ordem(raiz);
                    break;
            case 4: listar_pos_ordem(raiz);
                    break;
            case 5: dado = excluir_maior(&raiz);
                    printf("\nDado excluido: %d", dado);
                    break;
            case 6: dado = excluir_menor(&raiz);
                    printf("\nDado excluido: %d", dado);
                    break;
            case 7: printf("Entre com um valor a excluir:");
                    scanf("%d", &dado);
                    resultado_exclusao = excluir_valor(&raiz, dado);
                    break;
			case 8: printf("Entre com um valor:");
                    scanf("%d", &dado);
                    incluir_no_iterativo(&raiz, dado);
					break;
			case 9: printf("Entre com um valor para verificar:");
                    scanf("%d", &dado);
					verifica = verifica_arvore(raiz, dado);
					if(verifica==1){
						printf("\nO valor: %d esta presente.");
					}else{
						printf("\nO valor %d nao esta presente.");
					}
					break;
			case 10:contador=0;
					soma=0;
					printf("\nQtd nos: %d, Soma nos: %d, Media: %.2f", calcula_nos(raiz, contador), calcula_soma(raiz, soma), calcula_media(raiz));
					printf("\nA media dos valores na arvore e: %.2f", calcula_media(raiz));
					break;
			case 11:contador=0;
					contador=calcula_NULL(raiz, contador);
					printf("\nO numero de NULLS e: %d", contador);
					break;
			case 12:contador=0;
					contador=calcula_multiplos3(raiz, contador);
					printf("\nO numero de Multiplos de 3 e: %d", contador);
					break;
			case 13:contador=0;
					contador=calcula_nos(raiz, contador);
					printf("\nO numero de nos na arvore e: %d", contador);
					break;
			case 14:contador=0;
					contador=calcula_folha(raiz, contador);
					printf("\nO numero de nos folha na arvore e: %d", contador);
					break;
			case 15:contador=0;
					contador=altura_arvore(raiz);
					printf("\nA altura da arvore e: %d", contador);
					break;
			case 16:verifica=0;
					verifica=estritamente_binaria(raiz);
					if(verifica==1){
						printf("\nA arvore e estritamente binaria.");
					}else{
						printf("\nA arvore nao e estritamente binaria.");
					}
					break;
			case 17:copiar_arvore(raiz, &raiz2);
					printf("\nArvore2: ");
					listar_em_ordem(raiz2);
					break;
			case 0: printf("\nObrigado por utilizar!");
					break;
			default:printf("\n\nOpcao invalida!");
					break;
        }
    }
    while (opcao != 0);
}
