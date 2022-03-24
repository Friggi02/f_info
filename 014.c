/*Scrivere un programma in C che chiede all'utente un valore intero positivo o nullo che rappresenta una durata di tempo in secondi. Il 
programma converte e visualizza la durata in termini di: N di giorni, N di ore, N di minuti, N di secondi.

Per esempio, se l'utente inserisce il valore 76, il programma visualizzerà "0 giorni, 0 ore, 1 minuti, 16 secondi".*/

#include <stdio.h>

int main(){

	int tempo, resto, giorni, ore, minuti, secondi;

	printf("inserire secondi: ");
	scanf("%d", &tempo);

	giorni = tempo / (24*60*60);
	resto = tempo % (24*60*60);
	ore = resto / (60*60);
	resto = resto % (60*60);
	minuti = resto / (60);
	secondi = resto % (60);

	printf("%d giorni, %d ore, %d minuti e %d secondi\n", giorni, ore, minuti, secondi);

	return 0;
}