/*Scrivere un sottoprogramma che riceve due numeri interi positivi e calcola l'elevamento a potenza del primo rispetto al secondo, restituendo il risultato.
Scrivere un sottoprogramma che calcola la radice ennesima intera di un numero intero positivo. Il sottoprogramma prende come parametri 
il numero, il grado della radice, e una variabile, passata per indirizzo, in cui memorizzare la radice intera. Il sottoprogramma 
restituisce 1 se la radice intera è precisa, in alternativa 0. Scrivere un programma che utilizza tale sottoprogramma per calcolare 
la radice ennesima intera di un numero e di un grado chiesti all'utente, e ne visualizza il risultato.*/

#include <stdio.h>

int potenza(int, int);
int radice_ennesima(int, int, int*);

int main(){

	int argomento, grado, risultato, preciso;

	printf("argomento: ");
	scanf("%d", &argomento);
	printf("grado: ");
	scanf("%d", &grado);

	preciso = radice_ennesima(argomento, grado, &risultato);

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

int radice_ennesima(int argomento, int grado, int *radice){

	for(*radice=0; potenza(*radice, grado)<argomento; (*radice)++);

	return (potenza(*radice, grado)==argomento);
}