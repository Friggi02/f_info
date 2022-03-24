/*Supponendo di avere a disposizione una struttura dati per liste dinamiche e una serie di funzioni standard di manipolazione delle 
liste, scrivere un programma che acquisisce da tastiera due sequenze di lunghezza indefinita di 
numeri interi ciascuna terminata da uno 0 (che non fa parte della sequenza); ciascuna sequenza va memorizzata in una lista. Il 
programma calcola l'intersezione delle due sequenze rimuovendo eventuali duplicati, salvando il risultato in una terza lista e 
visualizzandolo. Il programma libera tutta la memoria allocata prima di terminare.*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){

	nodo_t *h1, *h2, *h3, *curr;
	int n;

	h1 = NULL;
	h2 = NULL;
	h3 = NULL;

	scanf("%d", &n);
	while(n!=0){
		h1 = inserisciInCoda(h1, n);
		scanf("%d", &n);
	}

	scanf("%d", &n);
	while(n!=0){
		h2 = inserisciInCoda(h2, n);
		scanf("%d", &n);
	}

	for(curr=h1; curr; curr=curr->next){
		if(esisteElemento(h2, curr->num) && !esisteElemento(h3, curr->num)){
			h3 = inserisciInCoda(h3, curr->num);
		}
	}

	visualizza(h3);

	h1 = distruggi(h1);
	h2 = distruggi(h2);
	h3 = distruggi(h3);

	return 0;
}


