/*123. Declare uma vari�vel inteira n e um ponteiro ptrn para essa vari�vel. Atribua um valor para n.
A seguir, imprima o valor de n a partir de ptrn. Imprima tamb�m o endere�o de n e de ptrn. */

#include <stdio.h>

int main(){
	int n;
	int *ptrn;

	printf("Informe o valor do numero:\n");
	scanf("%d", &n);
	ptrn=&n;
	printf("\nValor do Numero:%d Endereco do Numero:%p Endereco do ponteiro:%p\n", *ptrn, &n, &ptrn);

	return 0;
}
