/*Date le seguenti strutture dati che rappresentano una biblioteca:

Realizzare un sottoprogramma che riceve come parametri un array di biblioteche bib, la sua dimensione dim ed un array di interi ris di 
egual dimensione. Il sottoprogramma conta il numero totale di pagine di tutti i libri di ciascuna biblioteca in posizione i di bib e 
salva tale risultato nella corrispondente posizione i dell'array ris.

Scrivere un programma che chiede all'utente i dati di 10 biblioteche e li salva in un array.
Il programma invoca il sottoprogramma sopra definito e stampa a video il risultato.*/

#include <stdio.h>

#define N_LIBRI 1000
#define MAX_STR 100
#define N_BIBLIOTECHE 10

typedef struct{
	char autore[MAX_STR+1];
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


void analizza(biblioteca_t[], int, int[]);

int main(){

	biblioteca_t bib[N_BIBLIOTECHE];
	int i, j, ris[N_BIBLIOTECHE];
	
	for(i=0; i<N_BIBLIOTECHE; i++){
		printf("\n*** BIBLIOTECA %d ***\n", i);
		printf("nome: ");
		scanf("%s", bib[i].nome);
		printf("indirizzo: ");
		scanf("%s", bib[i].indirizzo);
		printf("numero libri: ");
		scanf("%d", &bib[i].n_libri);
		for(j=0; j<bib[i].n_libri; j++){
			printf("\n\t-LIBRO %d\n", j);
			printf("\tautore: ");
			scanf("%s", bib[i].libri[j].autore);
			printf("\ttitolo: ");
			scanf("%s", bib[i].libri[j].titolo);
			printf("\tprezzo: ");
			scanf("%f", &bib[i].libri[j].prezzo);
			printf("\tnumero pagine: ");
			scanf("%d", &bib[i].libri[j].pagine);
		}
	}

	printf("\n");

	analizza(bib, N_BIBLIOTECHE, ris);

	for(i=0; i<N_BIBLIOTECHE; i++){
		printf("nella biblioteca %d ci sono %d pagine\n", i, ris[i]);
	}

	return 0;
}

void analizza(biblioteca_t bib[], int dim, int ris[]){

	int i, j, risultato;
	
	for(i=0; i<dim; i++){
		for(j=0, risultato=0; j<bib[i].n_libri; j++){
			risultato += bib[i].libri[j].pagine;
		}
		ris[i] = risultato;
	}
}