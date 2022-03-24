/*Scrivere un sottoprogramma che riceve due numeri interi positivi e calcola l'elevamento a potenza del primo rispetto al secondo, restituendo il risultato. 
Scrivere un sottoprogramma che calcola il logaritmo in base 2 intero di un numero intero positivo. Il sottoprogramma riceve come parametri il numero
ed una variabile passata per indirizzo in cui memorizzare il risultato. Il sottoprogramma restituisce 1 se il logaritmo intero è preciso, in alternativa 0. 
Scrivere un programma che utilizza tale sottoprogramma per calcolare il logaritmo in base 2 di un numero chiesto all'utente, e ne visualizza il risultato.
VARIANTE: estendere questo programma per il calcolo del logaritmo in base N, richiesto all'utente.*/

#include <stdio.h>

int potenza(int, int);
int logaritmo(int, int, int*);

int main(){

	int base, argomento, preciso, risultato;

	printf("base: ");
	scanf("%d", &base);
	printf("argomento: ");
	scanf("%d", &argomento);

	preciso = logaritmo(argomento, base, &risultato);

	printf("risultato: %d preciso: %d\n", risultato, preciso);

	return 0;
}

int potenza(int base, int esponente){

	int i, risultato;

	risultato = 1;

	for(i=0; i<esponente; i++){
		risultato *= base;
	}

	return risultato;
}

int logaritmo(int n, int base, int *risultato){

	for(*risultato=0; !(potenza(base, *risultato+1)>n); (*risultato)++);

	return (potenza(base, *risultato)==n);	
}