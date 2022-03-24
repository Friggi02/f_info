/*Definire un nuovo tipo di dato per memorizzare una durata temporale in termini di numero di giorni, ore, minuti e secondi. Scrivere un 
programma che riceve da tastiera i dati sulla durata di una serie di 10 intervalli di tempo. Ciascun intervallo di tempo è della durata 
massima di 23 ore, 59 minuti e 59 secondi. Il programma deve assicurarsi che i dati di ciascun intervallo inserito siano validi. 
Successivamente, il programma calcola la somma di tutti gli intervalli e la stampa a video nel formato: giorni, ore, minuti, 
secondi (massimo 23 ore, massimo 59 minuti, massimo 59 secondi. Nessun limite al numero di giorni).

Esempio: per le seguenti durate di due (e non 10 per brevità) intervalli di tempo (ore, minuti, secondi):
- 20 50 15
- 7 20 30
il risultato che dovrà essere stampato sarà: 1 giorno/i, 4 ora/e, 10 minuto/i e 45 secondo/i.

VARIANTE: modificare il programma in modo tale che chieda all'utente il numero di intervalli (massimo 10)
di cui misurare la durata complessiva (e ne caso il valore sia sbagliato lo richiede).*/

#include <stdio.h>

#define MAX_INTERVALLI 10
#define ORE 24
#define MINUTI 60
#define SECONDI 60

typedef struct{
	int giorni, ore, minuti, secondi;
}intervallo_t;

int main(){

	intervallo_t intervalli[MAX_INTERVALLI], somma;
	int i, n_intervalli;	
	
/*ACQUISIZIONE INTERVALLI TEMPO*/
	do{
		printf("numero di intervalli: ");
		scanf("%d", &n_intervalli);
	}while(n_intervalli<=0 || n_intervalli>MAX_INTERVALLI);

	for(i=0; i<n_intervalli; i++){
		printf("\n**INTERVALLO %d**\n", i);
		do{
			printf("ore: ");
			scanf("%d", &intervalli[i].ore);
		}while(intervalli[i].ore<0 || intervalli[i].ore>=ORE);
		do{
			printf("minuti: ");
			scanf("%d", &intervalli[i].minuti);
		}while(intervalli[i].minuti<0 || intervalli[i].minuti>=MINUTI);
		do{
			printf("secondi: ");
			scanf("%d", &intervalli[i].secondi);
		}while(intervalli[i].secondi<0 || intervalli[i].secondi>=SECONDI);
		intervalli[i].giorni = 0;
	}

/*INIZIALIZZAZIONE SOMMA*/
	somma.giorni = 0;
	somma.ore = 0;
	somma.minuti = 0;
	somma.secondi = 0;

/*CALCOLO SOMMA BRUTALMENTE*/
	for(i=0; i<n_intervalli; i++){
		somma.ore += intervalli[i].ore;
		somma.minuti += intervalli[i].minuti;
		somma.secondi += intervalli[i].secondi;
	}

/*TENGO CONTO DEI RIPORTI*/
	somma.minuti += somma.secondi/SECONDI;
	somma.secondi = somma.secondi%SECONDI;
	somma.ore += somma.minuti/MINUTI;
	somma.minuti = somma.minuti%MINUTI;
	somma.giorni += somma.ore/ORE;
	somma.ore = somma.ore%ORE;

/*VISUALIZZAZIONE RISULTATO*/
	printf("%d giorni %d ore %d minuti %d secondi\n", somma.giorni, somma.ore, somma.minuti, somma.secondi);

	return 0;
}