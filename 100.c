/*Scrivere un sottoprogramma che calcola la radice quadrata intera un numero intero positivo. Il sottoprogramma riceve come parametro 
il numero intero ed un'altra variabile, passata per indirizzo, in cui memorizzare la radice intera. Il sottoprogramma restituisce 1 se 
la radice intera è precisa, in alternativa 0. Scrivere un programma che utilizza tale sottoprogramma per calcolare la radice quadrata 
intera di un numero chiesto all'utente, e ne visualizza il risultato.*/

#include <stdio.h>
int radicequadra(int, int*);

int main(){

	int n, preciso, risultato;

	scanf("%d", &n);

	preciso = radicequadra(n, &risultato);

	printf("risultato: %d preciso: %d\n", risultato, preciso);

	return 0;
}

int radicequadra(int x, int *radice){

	for(*radice=0; (*radice)*(*radice)<x; (*radice)++);

	return ((*radice)*(*radice)==x);
}
