/*Scrivere un programma in C che chiede all'utente un numero intero positivo e nel caso questo non sia valido stampa un messaggio 
dell'errore e continua a richiederlo. Il programma verifica se il numero è composto da sole cifre pari (0, 2, 4, 6, 8) e visualizza un 
messaggio con il responso del test (1: vero, 0: falso).*/

#include <stdio.h>

int main(){

	int n, cifra, ok;

	printf("inserire numero: ");
	scanf("%d", &n);

	while(n<1){
		printf("errore\n");
		printf("inserire numero: ");
		scanf("%d", &n);
	}

	ok = 1;

	while(n>0 && ok){
		cifra = n%10;
		if(cifra%2){
			ok = 0;
		}
		n = n/10;
	}

	printf("%d\n", ok);

	return 0;
}