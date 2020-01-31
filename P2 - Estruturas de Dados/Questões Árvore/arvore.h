#include<stdlib.h>
typedef struct reg_no tipo_no;
void incluir_no(tipo_no **, int );
void listar_pre_ordem(tipo_no *);
void listar_em_ordem(tipo_no *);
void listar_pos_ordem(tipo_no *);
int excluir_maior(tipo_no **);
int excluir_menor(tipo_no **);
int excluir_valor(tipo_no **, int );
//EX 164 - Inclusão na árvore de maneira iterariva - Falta arrumar
void incluir_no_iterativo(tipo_no **, int );
//EX 168 - Verificar se um número está presente na árvore
int verifica_arvore(tipo_no *, int );
//EX 171 - Essa função chama as funções 173 e 175
float calcula_media(tipo_no *);
//EX 172 - Retorna o número de NULLS presentes na árvore
int calcula_NULL(tipo_no *, int );
//EX 173 - Fiz somente para auxiliar a questão da média, calcula a soma de todos os dados da árvore
int calcula_soma(tipo_no *, int );
//EX 174 - Retorna quantos números presentes na árvore são múltiplos de 3
int calcula_multiplos3(tipo_no *, int );
//EX 175 - Retornar quantos nós a árvore possui
int calcula_nos(tipo_no *, int );
//EX 176 - Retorna quantos nós folha a árvore possui
int calcula_folha(tipo_no *, int );
//EX 177 - Retorna a altura da árvore, caso retire o +1 ela retorna em níveis(0, 1)
int altura_arvore(tipo_no *);
//EX 178 - Retorna se a árvore é estritamente binária, se todos os seus nós são folha ou apontam para outros 2 nós
int estritamente_binaria(tipo_no *);
//EX179 - Copia a árvore 1 para a árvore 2
void copiar_arvore(tipo_no *, tipo_no **);
