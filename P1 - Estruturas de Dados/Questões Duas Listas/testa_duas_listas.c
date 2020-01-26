/*Lucas de Figueiredo Aguiar - Exercícios do 142 ao 144, 148 e 149, exercicios que utilizam somente duas listas encadeadas
os comentários no código ajudam a identificar a qual questão pertence cada procedimento/função*/
#include <stdio.h>
#include "duas_listas.h"

int main(){
    tipo_lista *lista1, *lista2, *lista3, *lista4, *lista5;
    int opcao, numero;

    lista1 = criar_lista();
    lista2 = criar_lista();
    lista3 = criar_lista();
    lista4 = criar_lista();
    lista5 = criar_lista();
    do{
        printf("\n\n0 - Sair\n");
        printf("1 - Exibir dados\n");
        printf("2 - Lista 1 Excluir dado do inicio\n");
        printf("3 - Lista 1 Excluir do fim\n");
        printf("4 - Lista 1 Incluir ordenado\n\n");
        printf("5 - Lista 2 Excluir dado do inicio\n");
        printf("6 - Lista 2 Excluir do fim\n");
        printf("7 - Lista 2 Incluir ordenado\n\n");
        printf("8 - Tamanho das lista\n");
        printf("9 - Verifica se as listas sao iguais\n");
        printf("10 - Desalocar todos os nos da lista encadeada\n");
        printf("11 - Copia a lista 1 para a lista 3\n");//143
		printf("12 - Concatena as listas 1 e 2, na lista 1\n");//144
		printf("13 - Uniao da lista 1 e 2\n");
		printf("14 - Intersecao da lista 1 e 2\n");
        scanf("%d", &opcao);
        switch (opcao){
        	case 1: if(lista_vazia(lista1)==1){
                        printf("\nLista 1 vazia!\n");
                    }else{
                    	printf("\nLista1:\n");
                        listar(lista1);
                    }
                    if(lista_vazia(lista2)==1){
                        printf("\nLista 2 vazia!\n");
                    }else{
                    	printf("\nLista2:\n");
                        listar(lista2);
                    }
                    if(lista_vazia(lista3)==1){
                        printf("\nLista 3 vazia!\n");
                    }else{
                    	printf("\nLista3:\n");
                        listar(lista3);
                    }
                    if(lista_vazia(lista4)==1){
                        printf("\nLista 4 vazia!\n");
                    }else{
                    	printf("\nLista4:\n");
                        listar(lista4);
                    }
                    if(lista_vazia(lista5)==1){
                        printf("\nLista 5 vazia!\n");
                    }else{
                    	printf("\nLista5:\n");
                        listar(lista5);
                    }
                    break;
                    
			//Lista 1
			case 2: if(lista_vazia(lista1)==1){
                        printf("Lista 1 vazia!\n");
                    }
                    else{
                        excluir_do_inicio(lista1);
                    }
                    break;
                    
            case 3: if(lista_vazia(lista1)==1){
                        printf("Lista 1 vazia!\n");
                    }
                    else{
                        excluir_do_fim(lista1);
                    }
                    break;
                    
            case 4: printf("Entre com um numero:");
                    scanf("%d", &numero);
                    incluir_ordenado(lista1, numero);
                    break;
                    
			//Lista 2
			case 5: if(lista_vazia(lista2)==1){
                        printf("Lista 2 vazia!\n");
                    }
                    else{
                        excluir_do_inicio(lista2);
                    }
					break;
					
			case 6: if(lista_vazia(lista2)==1){
                        printf("Lista 2 vazia!\n");
                    }
                    else{
                        excluir_do_fim(lista2);
                    }
					break;
					
			case 7:printf("Entre com um numero:");
                    scanf("%d", &numero);
                    incluir_ordenado(lista2, numero);
                    break;
                    
            case 8: if(lista_vazia(lista1)==1){
                        printf("Lista 1 vazia!\n");
                    }else{
                    	printf("\nA lista 1 tem %d elementos.\n", tamanho_lista(lista1));
					}
					if(lista_vazia(lista2)==1){
                        printf("Lista 2 vazia!\n");
                    }else{
                    	printf("\nA lista 2 tem %d elementos.\n", tamanho_lista(lista2));
					}
                    break;

			//Operacoes
			case 9: if((tamanho_lista(lista1))==(tamanho_lista(lista2))){
						if((lista_vazia(lista1)==0)&&(lista_vazia(lista2)==0)){
							if(verifica_igual(lista1, lista2)==1){
                    			printf("\nAs listas SAO iguais!");
							}else{
								printf("\nAs listas NAO sao iguais!");
							}
                    	}
					}else{
						printf("\nAs listas NAO sao iguais!");
					}
					break;
					
            case 10:desalocar_nos(lista1);
            		desalocar_nos(lista2);
            		desalocar_nos(lista3);
                    break;
                    
			case 11:copia_lista(lista1, lista3);
					if(lista_vazia(lista3)==1){
                        printf("Lista 3 vazia!\n");
                    }else{
                    	printf("\nLista 3:");
						listar(lista3);
					}
					break;
					
			case 12:concatena_listas(lista1, lista2);
					break;
					
			case 13:uniao_listas(lista1, lista2, lista4);
					printf("\nLista4:\n");
					listar(lista4);
					break;
					
			case 14:intersecao_listas(lista1, lista2, lista5);
					printf("\nLista5:\n");
					listar(lista5);
					break;
					
			default:
				printf("\n\nOpcao invalida");
        }
    }
    while(opcao != 0);

	//Desalocando todas as listas
    printf("Endereco da lista 1:%p\n", lista1);
    lista1 = excluir_lista(lista1);
    printf("Endereco de lista 1:%p\n", lista1);

    printf("Endereco da lista 2:%p\n", lista2);
    lista2 = excluir_lista(lista2);
    printf("Endereco da lista 2:%p\n", lista2);

    printf("Endereco da lista 3:%p\n", lista3);
    lista3 = excluir_lista(lista3);
    printf("Endereco da lista 3:%p\n", lista3);

    printf("Endereco da lista 4:%p\n", lista4);
    lista4 = excluir_lista(lista4);
    printf("Endereco da lista 4:%p\n", lista4);

    printf("Endereco da lista 5:%p\n", lista5);
    lista5 = excluir_lista(lista5);
    printf("Endereco da lista 5:%p\n", lista5);

    return 0;
}
