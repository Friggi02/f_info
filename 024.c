/*Scrivere un programma in C che chiede all'utente un numero intero positivo (assumiamo per brevità che l'utente inserisca correttamente 
il valore). Il programma stampa a video le cifre che compongono il numero al contrario dalla più piccola alla più grande.
Esempio: se l'utente inserisce il valore 23445, il programma stampa il messaggio "54432".*/

#include <stdio.h>
#define BASE 10      /*se metto base due eseguo la conversione con il metodo dei resti occhio che è al contrario*/

int main(){

	int n, cifra;

	printf("inserire numero: ");
	scanf("%d", &n);

	while(n>0){
		cifra = n%BASE;
		n = n/BASE;
		printf("%d", cifra);
	}

	printf("\n");

	return 0;
}