/*Date le seguenti strutture dati che rappresentano una biblioteca:

Realizzare un sottoprogramma che riceve come parametri un array di biblioteche bib, la sua dimensione dim ed un array di interi ris di 
egual dimensione. Il sottoprogramma conta il numero totale di pagine di tutti i libri di ciascuna biblioteca in posizione i di bib e 
salva tale risultato nella corrispondente posizione i dell'array ris.

Scrivere un programma che chiede all'utente i dati di 10 biblioteche e li salva in un array.
Il programma invoca il sottoprogramma sopra definito e stampa a video il risultato.*/

#include <stdio.h>

#define N_LIBRI 1000
#define MAX_STR 100

typedef struct{
	char autori[MAX_STR+1];
	char titolo[MAX_STR+1];
	float prezzo;
	int pagine;
} libro_t;

typedef struct{
	char nome[MAX_STR+1];
	char indirizzo[MAX_STR+1];
	libro_t libri[N_LIBRI];
	int n_libri;
} biblioteca_t;

int main(){
	
	return 0;
}