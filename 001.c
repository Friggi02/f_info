/*Scrivere un programma in C che chiede all'utente un valore intero positivo o nullo che rappresenta l'importo che un cassiere deve 
restituire al cliente. Assumendo che l'utente abbia solo banconote da 5 euro, monete da 2 euro e monete da 1 euro,
il programma stabilisce e visualizza quante banconote da 5 euro, quante monete da 2 euro e quante da 1 euro il cassiere deve restituire.*/

#include <stdio.h>
#define TAGLIO 5
#define MONETA1 1
#define MONETA2 2

int main(){

	int resto, n_banconote, n_monete1, n_monete2;

	printf("inserire importo: ");
	scanf("%d", &resto);
	
	n_banconote = resto/TAGLIO;
	resto = resto%TAGLIO;
	n_monete2 = resto/MONETA2;
	n_monete1 = resto%MONETA2;

	printf("il resto è di %d banconote da %d€, %d monete da 2€ e %d monete da 1€\n", n_banconote, TAGLIO, n_monete2, n_monete1);
	
	return 0;
}