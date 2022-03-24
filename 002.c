/*Scrivere un programma in C che calcola il peso di una scatola contenente un numero di oggetti tutti uguali. Il programma chiede 
all'utente il peso del singolo oggetto in virgola mobile e il loro numero intero; in seguito esegue il calcolo e visualizza il risultato.*/

#include <stdio.h>

int main(){

	int n_oggetti;
	float peso_oggetto, peso_totale;

	printf("inserire numero oggetti: ");
	scanf("%d", &n_oggetti);
	printf("inserire peso oggetto: ");
	scanf("%f", &peso_oggetto);

	peso_totale = n_oggetti*peso_oggetto;					/*operazione tra oggetti eterogenei. avviene un cast implicito con ordine char,int,float,double*/

	printf("peso totale: %f\n", peso_totale);

	return 0;
}