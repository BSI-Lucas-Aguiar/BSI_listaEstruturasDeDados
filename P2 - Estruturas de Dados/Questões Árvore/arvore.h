#include<stdlib.h>
typedef struct reg_no tipo_no;
void incluir_no(tipo_no **, int );
void listar_pre_ordem(tipo_no *);
void listar_em_ordem(tipo_no *);
void listar_pos_ordem(tipo_no *);
int excluir_maior(tipo_no **);
int excluir_menor(tipo_no **);
int excluir_valor(tipo_no **, int );
//EX 164 - Inclus�o na �rvore de maneira iterariva - Falta arrumar
void incluir_no_iterativo(tipo_no **, int );
//EX 168 - Verificar se um n�mero est� presente na �rvore
int verifica_arvore(tipo_no *, int );
//EX 171 - Essa fun��o chama as fun��es 173 e 175
float calcula_media(tipo_no *);
//EX 172 - Retorna o n�mero de NULLS presentes na �rvore
int calcula_NULL(tipo_no *, int );
//EX 173 - Fiz somente para auxiliar a quest�o da m�dia, calcula a soma de todos os dados da �rvore
int calcula_soma(tipo_no *, int );
//EX 174 - Retorna quantos n�meros presentes na �rvore s�o m�ltiplos de 3
int calcula_multiplos3(tipo_no *, int );
//EX 175 - Retornar quantos n�s a �rvore possui
int calcula_nos(tipo_no *, int );
//EX 176 - Retorna quantos n�s folha a �rvore possui
int calcula_folha(tipo_no *, int );
//EX 177 - Retorna a altura da �rvore, caso retire o +1 ela retorna em n�veis(0, 1)
int altura_arvore(tipo_no *);
//EX 178 - Retorna se a �rvore � estritamente bin�ria, se todos os seus n�s s�o folha ou apontam para outros 2 n�s
int estritamente_binaria(tipo_no *);
//EX179 - Copia a �rvore 1 para a �rvore 2
void copiar_arvore(tipo_no *, tipo_no **);
