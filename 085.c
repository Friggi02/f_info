/*Scrivere un sottoprogramma che chiede all'utente un numero intero non negativo; se il valore acquisito non è valido il sottoprogramma 
visualizza un apposito messaggio di errore e ripete la richiesta. Una volta acquisito un valore valido, il sottoprogramma restituisce 
il numero al chiamate.

Scrivere un programma che acquisisce due numeri positivi mediante l'apposito sottoprogramma definito sopra e li stampa a video.*/

#include <stdio.h>

int positivo();

int main(){

	int num1, num2;

	num1 = positivo();
	num2 = positivo();

	printf("%d %d\n", num1, num2);

	return 0;
}

int positivo(){

	int n;

	scanf("%d", &n);
	while(n<0){
		printf("inserire un numero valido: ");
		scanf("%d", n);
	}

	return n;
}