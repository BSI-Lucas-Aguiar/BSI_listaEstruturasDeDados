typedef struct reg_no tipo_no;
typedef struct reg_lista tipo_lista;

tipo_lista* criar_lista();
int lista_vazia(tipo_lista *;
void listar(tipo_lista *);
void excluir_do_inicio(tipo_lista *);
int excluir_do_fim(tipo_lista *);
tipo_lista* excluir_lista(tipo_lista *);
int incluir_ordenado(tipo_lista *, int );
int tamanho_lista(tipo_lista *);
void incluir_no_fim(tipo_lista *, int );
int desalocar_nos(tipo_lista *);
int verifica_igual(tipo_lista *, tipo_lista *);
void copia_lista(tipo_lista *, tipo_lista *);
int concatena_listas(tipo_lista *, tipo_lista *);
void uniao_listas(tipo_lista *, tipo_lista *, tipo_lista *);
void intersecao_listas(tipo_lista *, tipo_lista *, tipo_lista *);
