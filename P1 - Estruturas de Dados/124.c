/*124. A partir do exerc�cio anterior, incremente o valor de n usando apenas o ponteiro ptrn.
Imprima o novo valor de n para confirmar se est� correto. */

#include <stdio.h>

int main(){
	int n;
	int *ptrn;

	printf("Informe o valor do numero:\n");
	scanf("%d", &n);
	ptrn=&n;
	printf("\nValor do Numero:%d Endereco do Numero:%p Endereco do ponteiro:%p\n", *ptrn, &n, &ptrn);
	*ptrn+=1;
	printf("\nValor do Numero:%d Endereco do Numero:%p Endereco do ponteiro:%p\n", *ptrn, &n, &ptrn);
	
	return 0;
}
