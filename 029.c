/*Scrivere un programma in C che chiede all'utente un numero intero positivo in base 10 che cambia la base del sistema.*/

#include <stdio.h>
#define BASE_IN 10
#define BASE_OUT 2      

int main(){

	int n, cifra, ris, pot10;

	printf("inserire il numero in base %d: ", BASE_IN);
	scanf("%d", &n);

	ris = 0;
	pot10 = 1;

	while(n>0){
		cifra = n%BASE_OUT;
		n = n/BASE_OUT;
		ris = ris+pot10*cifra;
		pot10 = pot10*BASE_IN;
	}

	printf("numero in base %d: %d\n", BASE_OUT, ris);

	return 0;
}