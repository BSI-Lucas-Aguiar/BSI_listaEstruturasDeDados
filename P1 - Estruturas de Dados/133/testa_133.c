/* Lucas de Figueiredo Aguiar - 133. Crie um Tipo Abstrato de Dados (TAD) que represente o tipo conjunto de inteiros,
utilizando uma representação de vetor de inteiros e que contenha as seguintes funções:
(a) União
(b) Cria um conjunto vazio
(c) Insere
(d) Remove
(e) Intersecção
(f) Diferença
(g) Testa se um número pertence ao conjunto
(h) Menor valor
(i) Maior valor
(j) Testa se os conjuntos são iguais
(k) Tamanho
(l) Testa se o conjunto é vazio */
#include <stdio.h>
#include "133.h"

int main(){
	conj_int conj1 = criaConjunto(100);
	conj_int conj2 = criaConjunto(100);
	conj_int uniao = criaConjunto(1);
	conj_int interseccao = criaConjunto(1);
	conj_int diferenca = criaConjunto(1);
	int opcao = 1;
	int resp;
	int x;
	//Dois cases, um para cada conjunto, o mesmo menu chamado para os dois numa funcao
	do{
		printf("\nManipular conjunto 1 ou conjunto 2[1/2]:");
		scanf("%d", &resp);
		while(resp != 1 && resp != 2){
			printf("Resposta invalida!\n");
			printf("Manipular conjunto 1 ou conjunto 2[1/2]:");
			scanf("%d", &resp);
		}
		opcao = menu();//Chama um menu com as opcoes
		
		if(resp == 1){
			switch(opcao){
				case 1:
		            printf("Informe um numero:");
			        scanf("%d", &x);
			        insereElem(conj1, x);
			    break;
			    
			    case 2:
			        if(verificaConjuntoVazio(conj1) == 0){
			        	printf("Conjunto vazio");
			        }else{
			        	printf("Informe um numero:");
			            scanf("%d", &x);
			            removeElem(conj1, x);
			        }
			    
			    break;
			    
			    case 3:
			        listarConjunto(conj1);
			    break;
			    
			    case 4:
			        if(verificaConjuntoVazio(conj1) == 0){
			        	printf("Conjunto vazio\n");
			        }else{
			        	printf("Informe um numero:");
			            scanf("%d", &x);
			            getchar();
		                if(testaExistenciaValor(conj1, x) == 1){
		            	     printf("Valor existe no conjunto\n");
		                }else{
		            	    printf("Valor nao existe no conjunto\n");
		                }
		            }
		        break;
		        
		        case 5:
		            if(verificaConjuntoVazio(conj1) == 0){
			        	printf("Conjunto vazio\n");
			        }else{
			        	printf("Menor valor do conjunto: %d", menorValor(conj1));
			        }
			    break;
			    
			    case 6:
		            if(verificaConjuntoVazio(conj1) == 0){
			        	printf("Conjunto vazio\n");
			        }else{
			        	printf("Maior valor do conjunto: %d", maiorValor(conj1));
			        }
			    break;
			    
			    case 7:
			        if(verificaConjuntoVazio(conj1) == 0){
			        	printf("Conjunto vazio");
			        }else{
			        	printf("Conjunto nao vazio");
			        }
			    break;
			    
			    case 8:
			        printf("Tamanho do conjunto: %d\n", retornaTamanho(conj1));
			    break;
			    
			    case 9:
			        if(verificaConjuntoVazio(conj1) == 0 && verificaConjuntoVazio(conj2) == 0){
			        	printf("Conjuntos vazios\n");
			        }else{
			        	if(verificaIgualdade(conj1, conj2) == 0){
			        		printf("Conjuntos diferentes\n");
			        	}else{
			        		printf("Conjuntos iguais\n");
			        	}
			        }
			    break;
			    
			    case 10:
			        if(verificaConjuntoVazio(conj1) == 0 && verificaConjuntoVazio(conj2) == 0){
			        	printf("Conjuntos vazios\n");
			        }else{
			    	    uniao = uneConjuntos(conj1, conj2, uniao);
			        }
			    break;
			    
			    case 11:
			        if(verificaConjuntoVazio(conj1) == 0 && verificaConjuntoVazio(conj2) == 0){
			        	printf("Conjuntos vazios\n");
			        }else{
			    	    uniao = intersectaConjuntos(conj1, conj2, interseccao);
			        }
			    break;
			    
			    case 12:
			        if(verificaConjuntoVazio(conj1) == 0 && verificaConjuntoVazio(conj2) == 0){
			        	printf("Conjuntos vazios\n");
			        }else{
			        	if(verificaConjuntoVazio(conj1) == 0){
			        		printf("Conjunto 1 esta vazio\n");
			        	}else{
			        		printf("Diferenca: Conjunto 1 - Conjunto 2\n");
			   
			        		diferenca =diferencaConjuntos(conj1, conj2, interseccao, 1);
			        	}
			        }
			    break;
			        
			    default: 
			        opcao = 0;
			    break;
			}
		}
		else{
			switch(opcao){
				case 1:
		            printf("Informe um numero:");
			        scanf("%d", &x);
			        insereElem(conj2, x);
			    break;
			    
			    case 2:
			        if(verificaConjuntoVazio(conj2) == 0){
			        	printf("Conjunto vazio");
			        }else{
			        	printf("Informe um numero:");
			            scanf("%d", &x);
			            removeElem(conj2, x);
			        }
			    break;
			    
			    case 3:
			        listarConjunto(conj2);
			    break;
			    
			    case 4:
			        if(verificaConjuntoVazio(conj2) == 0){
			        	printf("Conjunto vazio\n");
			        }else{
			        	printf("Informe um numero:");
			            scanf("%d", &x);
		                if(testaExistenciaValor(conj1, x) == 1){
		            	     printf("Valor existe no conjunto\n");
		                }else{
		            	    printf("Valor nao existe no conjunto\n");
		                }
		            }
			    break;
			    
		        case 5:
		            if(verificaConjuntoVazio(conj2) == 0){
			        	printf("Conjunto vazio\n");
			        }else{
			        	printf("Menor valor do conjunto: %d", menorValor(conj2));
			        }
			    break;
			    
			    case 6:
		            if(verificaConjuntoVazio(conj2) == 0){
			        	printf("Conjunto vazio\n");
			        }else{
			        	printf("Maior valor do conjunto: %d", maiorValor(conj2));
			        }
			    break;
			    
			    case 7:
			        if(verificaConjuntoVazio(conj2) == 0){
			        	printf("Conjunto vazio");
			        }else{
			        	printf("Conjunto nao vazio");
			        }
			    break;
			    
			    case 8:
			        printf("Tamanho do conjunto: %d\n", retornaTamanho(conj2));
			    break;
			        
			    case 9:
			        if(verificaConjuntoVazio(conj1) == 0 && verificaConjuntoVazio(conj2) == 0){
			        	printf("Conjuntos vazios\n");
			        }else{
			        	if(verificaIgualdade(conj1, conj2) == 0){
			        		printf("Conjuntos diferentes\n");
			        	}else{
			        		printf("Conjuntos iguais");
			        	}
			        }
			    break;
			    
			    case 10:
			        if(verificaConjuntoVazio(conj1) == 0 && verificaConjuntoVazio(conj2) == 0){
			        	printf("Conjuntos vazios\n");
			        }else{
			    	    uniao = uneConjuntos(conj1, conj2, uniao);
			    
			        }
			    break;
			   case 11:
			        if(verificaConjuntoVazio(conj1) == 0 && verificaConjuntoVazio(conj2) == 0){
			        	printf("Conjuntos vazios\n");
			        }else{
			    	    uniao = intersectaConjuntos(conj1, conj2, interseccao);
			        }
			    break;
			    case 12:
			        if(verificaConjuntoVazio(conj1) == 0 && verificaConjuntoVazio(conj2) == 0){
			        	printf("Conjuntos vazios\n");
			        }else{
			        	if(verificaConjuntoVazio(conj2) == 0){
			        		printf("Conjunto 2 esta vazio\n");
			        	}else{
			        		printf("Diferenca: Conjunto 2 - Conjunto 1:\n");
			        		diferenca =diferencaConjuntos(conj1, conj2, interseccao, 2);
			        	}
			        }
			    break;
			    
			    default: 
			        opcao = 0;
			    break;
			}
		}
	}while(opcao != 0);
	
	return 0;
}
