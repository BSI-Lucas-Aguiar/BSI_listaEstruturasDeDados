/*123. Declare uma variável inteira n e um ponteiro ptrn para essa variável. Atribua um valor para n.
A seguir, imprima o valor de n a partir de ptrn. Imprima também o endereço de n e de ptrn. */

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
