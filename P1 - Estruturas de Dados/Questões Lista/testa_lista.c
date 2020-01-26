/*Lucas de Figueiredo Aguiar - Exercícios do 136 ao 141, 145 a 147, exercicios que utilizam somente uma lista encadeada
os comentários no código ajudam a identificar a qual questão pertence cada procedimento/função*/
#include <stdio.h>
#include "lista.h"

int main()
{
    tipo_lista *lista;
    int opcao, numero, *vetor, i;

	//Inicializa a lista
    lista = criar_lista(); //136
    do
    {
        printf("\n\n0 - Sair\n");
        //Impressão da lista
        printf("1 - Exibir dados\n");
        //Inclusão de dados
        printf("2 - Incluir dado no inicio\n");
        printf("3 - Incluir dado no fim\n");
        printf("4 - Incluir ordenado\n"); //136
        //Exclusão de dados
        printf("5 - Excluir dado do inicio\n");
        printf("6 - Excluir dado do fim\n");
        printf("7 - Excluir dado especifico\n"); //136
        //Outras operações
        printf("8 - Tamanho da lista\n"); //136
        printf("9 - Media aritmetica dos elementos da lista\n"); //136
        printf("10 - Desalocar todos os nos da lista encadeada\n"); //136
        printf("11 - Verificar lista vazia\n"); //136
        printf("12 - Profundidade da lista\n"); //137
        printf("13 - Verificar ordem crescente\n"); //138
        printf("14 - Criar vetor com elementos da lista\n"); //139
        printf("15 - Busca endereco de numero da lista\n"); //140
        printf("16 - Busca o valor minimo da lista\n"); //141
        printf("17 - Exclui todos os dados iguais ao numero informado\n");//146
        printf("18 - Exclui uma posicao especifica\n");//147
        printf("19 - Inverter as posicoes existentes na lista\n");//145
        scanf("%d", &opcao);
        switch (opcao){
        	case 1: if (lista_vazia(lista)){
                        printf("\nLista vazia!\n");
                    }else{
                    	printf("\nLista impressa:");
                        listar(lista);
                    }
                    break;
                    
            case 2: printf("Entre com um numero:");
                    scanf("%d", &numero);
                    incluir_no_inicio(lista, numero);
                    break;
                    
            case 3: printf("\nEntre com um numero:");
                    scanf("%d", &numero);
                    incluir_no_fim(lista, numero);
                    break;
                    
			case 4: printf("\nEntre com um numero:");
                    scanf("%d", &numero);
                    incluir_ordenado(lista, numero);
                    break;
                    
            case 5: if (lista_vazia(lista)==1){
                        printf("\nLista vazia!\n");
                    }
                    else{
                        excluir_do_inicio(lista);
                    }
                    break;
                    
            case 6: excluir_do_fim(lista);
                    break;
                    
            case 7: if (lista_vazia(lista)==1){
                        printf("\nLista vazia!\n");
                    }else{
						printf("\nEntre com um numero:");
                    	scanf("%d", &numero);
                    	excluir_especifico(lista, numero);
                	}
                    break;
                    
            case 8: printf("\nA lista tem %d elementos.\n", tamanho_lista(lista));
                    break;
                    
            case 9: if (lista_vazia(lista)==1)
                    {
                        printf("\nLista vazia! Nao e possivel calcular a media aritmetica!\n");
					}else{
						printf("\nA media aritmetica e: %.2f", media_aritmetica(lista));
					}
                    break;
                    
            case 10:desalocar_nos(lista);
					printf("\nLista completamente desalocada!\n");
                    break;
			case 11:if (lista_vazia(lista)==1){
                        printf("\nLista vazia!\n");
                    }else{
                    	printf("\nA Lista possui elementos!\n");
					}
					break;
					
			case 12:printf("\nInforme o numero da celula desejada:");
					scanf("%d", &numero);
					printf("\nA celula com o valor %d possui profundidade %d\n", numero, profundidade_lista(lista, numero));
			case 13:if (lista_vazia(lista)==1){
                        printf("\nLista vazia!\n");
                    }else if(verificar_crescente(lista)==1){
						printf("\nA Lista esta em ordem crescente!");
					}else{
						printf("\nA Lista NAO esta em ordem crescente!");
					}
					break;
					
			case 14:vetor = cria_vetor(lista, tamanho_lista(lista));
					printf("\nVetor Impresso:\n");
					for(i=0; i<tamanho_lista(lista); i++){
						printf("[%d] ", vetor[i]);
					}
					break;
					
			case 15:printf("\nInforme a o valor da lista que deseja buscar:");
					scanf("%d", &numero);
					if (lista_vazia(lista)==1){
                        printf("\nNao e possivel buscar endereco numa Lista vazia!\n");
                    }else{
                    	printf("\nO endereco do primeiro numero %d e: %p\nEndereco 0 quando numero nao existe na Lista", numero, busca_endereco(lista, numero));
					}
					break;
					
			case 16:if (lista_vazia(lista)==1){
                        printf("\nNao e possivel buscar o valor minimo numa Lista vazia!\n");
                    }else{
                    	printf("\nO conteudo minimo da lista e: %d", busca_minimo(lista));
					}
					break;
					
			case 17:if (lista_vazia(lista)==1){
                        printf("\nLista vazia!\n");
                    }else{
						printf("\nInforme o numero a ser removido de todas as celulas da lista:");
						scanf("%d", &numero);
						excluir_especifico_todos(lista, numero);
					}
					break;
					
			case 18:printf("\nInforme a posicao a ser deletada:");
					scanf("%d", &numero);
					if(numero<=0){
						printf("\nValor invalido");
					}else if(tamanho_lista(lista)>=numero){
						exclui_posicao(lista, numero);
	 				}else{
						printf("\nPosicao invalida!\n");
					}
	 				break;
	 				
			case 19:if (lista_vazia(lista)==1){
                        printf("\nLista vazia!\n");
                    }else{
						inverte_lista(lista);
					}
                    break;
                    
			default:
				printf("\n\nOpcao invalida");
		}
    }
    while(opcao != 0);

    printf("\nEndereco de lista:%p\n", lista);
    lista = excluir_lista(lista);
    printf("Endereco de lista:%p\n", lista);
    return 0;
}
