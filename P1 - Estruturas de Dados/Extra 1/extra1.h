typedef struct reg_no tipo_no;
typedef struct reg_fila tipo_fila;
tipo_fila* criar_fila();
void listar(tipo_fila *);
int fila_vazia(tipo_fila *);
int desalocar_fila(tipo_fila *);
void incluir_no_fim(tipo_fila *, int );
void excluir_do_inicio(tipo_fila *);
