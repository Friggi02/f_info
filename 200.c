/*Una successione seq2 è una sottosuccessione di seq1 se gli elementi di seq2
occorrono ordinatamente (non necessariamente in modo consecutivo) in seq1.

Ad esempio, la successione di interi < 2; 6; 7 > è una sottosuccessione di < 2; 1; 2; 3; 4; 6; 7; 9 >,
ma non di <7; 2; 1; 6; 3 > (perchè i valori 2, 6, 7 non sono presenti nel giusto ordine).

Una successione vuota non è una sottosuccessione.

Scrivere un sottoprogramma che ricevute due liste di interi seq1 e seq2 controlli se seq2
corrisponde ad una sottosuccessione di seq1: in caso positivo restituisce 1, 0 altrimenti.

Scrivere un programma che chiede all'utente due sequenze di lunghezza indefinita di numeri interi terminate dal
valore 0 (che non fa parte della sequenza). Il programma richiama il sottoprogramma e visualizza il risultato.*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define TERMINATORE 0

int check(nodo_t*, nodo_t*);

int main(){

	nodo_t *seq1, *seq2;
	int n;

	seq1 = NULL;
	seq2 = NULL;

	printf("Inserire i valori della lista principale:\n");
	scanf("%d", &n);
	while(n!=TERMINATORE){
		seq1 = inserisciInCoda(seq1, n);
		scanf("%d", &n);
	}

	printf("Inserire i valori della sottolista:\n");
	scanf("%d", &n);
	while(n!=TERMINATORE){
		seq2 = inserisciInCoda(seq2, n);
		scanf("%d", &n);
	}

	printf("\nesito: %d\n", check(seq1, seq2));

	return 0;
}

int check(nodo_t *seq1, nodo_t *seq2){

	int esito;

	if(seq2){
		while(seq1 && seq2){
			if(seq1->num==seq2->num){
				seq2 = seq2->next;
			}
			seq1 = seq1->next;
		}
		esito = seq2==NULL;
	}else{
		esito = 0;
	}

	return esito;
}
