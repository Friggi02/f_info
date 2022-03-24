/*
Definire un tipo di dato opportuno per gli elementi della lista.

Scrivere un sottoprogramma che riceve come parametro una lista di numeri interi codici. Il sottoprogramma crea e restituisce una nuova lista
mancanti contenente tutti i valori interi non presenti in codici compresi tra il valore minimo ed il valore massimo di codici, ordinati
in ordine crescente.

Per esempio, se la lista codici contiene i valori
2 -> 5 -> -1-> -4 -> 3
il sottoprogramma crea e restituisce la seguente lista mancanti:
-3 -> -2 -> 0 -> 1 -> 4
Se la lista codici contiene i valori
0 -> -5 -> -1-> -4 -> -3 -> -2
il sottoprogramma crea e restituisce una lista vuota.

Si consideri disponibile la libreria delle liste.

Scrivere un programma che chiede all'utente una sequenza di lunghezza indefinita di numeri interi chiesta all'utente e terminata dal valore 0
(che non fa parte della sequenza) per popolare una lista dinamica. Il programma richiama il sottoprogramma e visualizza il risultato.*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define TERMINATORE 0

nodo_t* complementare(nodo_t*);

int main(){

	nodo_t *h;
	int n;

	h = NULL;

	printf("inserire lista di valori: ");
	scanf("%d", &n);
	while(n!=TERMINATORE){
		h = inserisciInCoda(h, n);
		scanf("%d", &n);
	}

	h = complementare(h);

	visualizza(h);

	return 0;
}

nodo_t* complementare(nodo_t *codici){

	nodo_t *mancanti, *curr;
	int min, max, v;

	mancanti = NULL;

	if(codici){
		min = codici->num;
		max = codici->num;

		for(curr=codici->next; curr; curr=curr->next){
			if(min>curr->num){
				min = curr->num;
			}else if(max<curr->num){
				max = curr->num;
			}
		}

		for(v=max-1; v>min; v--){
			if(!esisteElemento(codici, v)){
				mancanti = inserisciInTesta(mancanti, v);
			}
		}
	}

	return mancanti;
}