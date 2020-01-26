typedef struct conj *conj_int;

int menu();
conj_int criaConjunto(int );
void listarConjunto(conj_int );
void insereElem(conj_int , int );
void removeElem(conj_int , int );
int verificaConjuntoVazio(conj_int );
int testaExistenciaValor(conj_int , int );
int menorValor(conj_int );
int maiorValor(conj_int );
int retornaTamanho(conj_int );
int verificaIgualdade(conj_int , conj_int );
conj_int uneConjuntos(conj_int , conj_int , conj_int );
conj_int intersectaConjuntos(conj_int , conj_int , conj_int );
conj_int diferencaConjuntos(conj_int , conj_int , conj_int , int );
