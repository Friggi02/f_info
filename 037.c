/*Un numero intero è palindromo quando le sue cifre rappresentano lo stesso valore sia che siano lette da destra che da sinistra.
Esempi di numeri palindromi sono 111, 121, 13431. Scrivere un programma in C che chiede all'utente un numero intero 
positivo (nel caso il valore non sia valido il programma stampa un messaggio di errore e richiede il valore).
Il programma verifica se il numero è palindromo; in caso affermativo stampa a video 1 altrimenti 0.*/

#include <stdio.h>

int main(){

	int n, resto, somma, temp, palindromo;

	do{
		printf("inserire numero: ");
		scanf("%d", &n);
	}while(n<=0);

	temp = n;
	somma = 0;
	palindromo = 0;

	while(n>0 && !palindromo){
		resto = n%10;
		somma = (somma*10)+resto;
		n = n/10;
		if(temp==somma){
			palindromo = 1;
		}
	}

	printf("esito: %d\n", palindromo);

	return 0;
}