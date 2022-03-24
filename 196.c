/*Definire un nuovo tipo di dato per la gestione di una lista dinamica di interi, nodo_t. Scrivere due sottoprogrammi kcon e knocon che ricevuta in ingresso una 
lista del tipo definito ed un intero k, si comportino come specificato di seguito:
- kcon: restituisce 1 se la lista contiene almeno due occorrenze consecutive di k, 0 altrimenti
- knocon: restituisce 1 se la lista contiene almeno due occorrenze non consecutive di k, 0 altrimenti.
Provare a realizzare le versioni sia iterative che ricorsive dei due sottoprogrammi; per le versioni ricorsive è possibile definire ulteriori sottoprogrammi ausiliari.

Esempi (tutti con k=5)

Con la lista: 1 -> 5 -> 5 -> 3 -> 2
kcon: 1
knoncon: 0

Con la lista: 1 -> 5 -> 5 -> 5 -> 2
kcon: 1
knoncon: 1

Con la lista: 1 -> 5 -> 3 -> 5 -> 2
kcon: 0
knoncon: 1			

Scrivere un programma che chiede all'utente una sequenza di lunghezza indefinita di numeri interi chiesta all'utente e terminata dal valore 0
(che non fa parte della sequenza) per popolare una lista dinamica. Il programma invoca i sottoprogrammi sopra definit1 e visualizza i risultat1.
Gestire opportunamente il rilascio di tutte le risorse allocate.	*/

#include <stdio.h>
#include "lista.h"
#define TERMINATORE 0

int kcon(nodo_t*, int);
int kcon_ric(nodo_t*, int);
int knocon(nodo_t*, int);
int knocon_ric(nodo_t*, int);
int _conta_k(nodo_t*, int);

int main(){

	nodo_t *l;
	int k;

	l = NULL;
	
	printf("inserire lista di valori: ");
	scanf("%d", &k);
	while(k!=TERMINATORE){
		l = inserisciInCoda(l, k);
		scanf("%d", &k);
	}

	printf("inserire numero: ");
	scanf("%d", &k);


	printf("kcon: %d\n", kcon(l, k));
	printf("kcon ric: %d\n", kcon_ric(l, k));
	printf("knoncon: %d\n", knocon(l, k));
	printf("knoncon ric: %d\n", knocon_ric(l, k));

	return 0;
}

int kcon(nodo_t *l, int k){

	int trovato;

	trovato = 0;

	if(l){
		while(l->next && !trovato){
			if(l->num==k && l->next->num==k){
				trovato = 1;
			}
			l = l->next;
		}
	}

	return trovato;
}

int knocon(nodo_t *l, int k){

	int occorrenze, prec;

	for(occorrenze=0, prec=0; l && occorrenze<2; l=l->next){
		if(!prec && l->num==k){
			occorrenze++;
			prec = 1;
		}else{
			prec = 0;
		}
	}

	return occorrenze>=2;
}

int kcon_ric(nodo_t *l, int k){

	if(!l || !l->next){
		return 0;
	}

	if(l->num==k && l->next->num==k){
		return 1;
	}

	return kcon_ric(l->next, k);
}

int knocon_ric(nodo_t *l, int k){

	return _conta_k(l, k)>=2;
}

int _conta_k(nodo_t *l, int k){

	if(!l){
		return 0;
	}

	if(l->num==k){
		if(l->next){
			return 1 + _conta_k(l->next->next, k);
		}else{
			return 1;
		}
	}

	return _conta_k(l->next, k);
}