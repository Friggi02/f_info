/*Si definisce triangolare un numero costituito dalla somma dei primi N numeri interi positivi per un certo N.

Esempio: dato N=4, il numero triangolare Q è 10 (Q=1+2+3+4).

Scrivere un programma in C che trova numero triangolare rispetto ad numero intero positivo chiesto all'utente.*/

#include <stdio.h>

int main(){

	int n, q, somma;

	printf("inserire un numero: ");
	scanf("%d", &n);

	for(q=1, somma=0; q<=n; q++){
		somma += q;
	}

	printf("numero triangolare: %d\n", somma);

	return 0;
}