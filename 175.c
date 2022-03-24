/*
Scrivere un sottoprogramma che riceve in ingresso una lista per la gestione dei numeri interi ed un valore intero dir. Il sottoprogramma
effettua una rotazione a sinistra (se dir vale 0) o a destra (se dir vale 1) del contenuto della lista, restituendola modificata al chiamante.
Nella rotazione a sinistra, il primo valore viene posto in fondo alla lista, nello scorrimento a destra, l’ultimo valore della lista viene messo davanti
a tutti gli altri.

Se per esempio il sottoprogramma riceve in ingresso una lista contenente i valori: 3 → 6 → 10 → −2 → 8
la rotazione a sinistra produce la seguente lista: 6 → 10 → −2 → 8 → 3
la rotazione a destra della lista iniziale produce la seguente lista: 8 → 3 → 6 → 10 → −2

Nel caso in cui la lista è vuota o contiene un solo elemento, il sottoprogramma restituisce la lista ricevuta in ingresso. Si suggerisce di sviluppare
due sottoprogrammi separati, uno che esegua la rotazione a sinistra, uno che esegua quella a destra. Non causare memory leakage: situazione
in cui ci sono nodi non più accessibili senza aver effettivamente rilasciato la memoria.Definire un tipo di dato opportuno per gli elementi della lista.
Si considerino già disponibili e non da sviluppare i sottoprogrammi seguenti:

inserisce in testa alla lista 
elem_t * push(elem_t*, int);

inserisce in coda alla lista
elem_t * append(elem_t*, int);

inserisce un elemento nella lista in ordine crescente 
elem_t * insert_ inc (elem_t*, int);

inserisce un elemento nella lista in ordine decrescente
elem_t * insert_dec(elem_t*, int);

elimina dalla lista il primo elemento 
elem_t * pop (elem_t*);

elimina dalla lista tutti gli elementi con il valore indicato 
elem_t * delete(elem_t*, int);

restituisce il riferimento all’ elemento nella lista che ha il valore indicato, se esiste, NULL altrimenti 
elem_t * exists(elem_t*, int);

restituisce il numero di elementi nella lista 
int length(elem_t*);

Scrivere un programma che chiede all'utente una sequenza di lunghezza indefinita di numeri interi chiesta all'utente e terminata dal valore 0 (che non fa parte della 
sequenza) per popolare una lista dinamica. Il programma chide all'utente in che direzione far ruotare la lista, richiama il sottoprogramma e stampa il risultato.*/

#include <stdio.h>
#include "lista.h"
#define TERMINATORE 0

nodo_t* ruotasinistra(nodo_t* h);
nodo_t* ruotadestra(nodo_t* h);
nodo_t* ruota(nodo_t* h, int dir);

int main(){

	nodo_t *h;
	int n, dir;

	h = NULL;

	printf("inserire lista di valori: ");
	scanf("%d", &n);
	while(n!=TERMINATORE){
		h = inserisciInCoda(h, n);
		scanf("%d", &n);
	}

	printf("inserisci direzione (0dx-1sx): ");
	scanf("%d", &dir);

	h = ruota(h, dir);

	visualizza(h);

	return 0;	
}


nodo_t* ruota(nodo_t* h, int dir){
	if(dir){
		h = ruotadestra(h);
	}else{
		h = ruotasinistra(h);
	}
	return h;
}

nodo_t* ruotasinistra(nodo_t* h){

	nodo_t *tmp, *curr;

	if(h && h->next) {
		tmp = h;
		h = h->next;
		tmp->next = NULL;
		for(curr=h; curr->next; curr = curr->next);
		curr->next=tmp;
	}
	return h;
}

nodo_t* ruotadestra(nodo_t* h){
	
	nodo_t *tmp, *curr;

	if(h && h->next){
		for(curr=h; curr->next->next; curr=curr->next);
		tmp = curr->next;
		curr->next = NULL;
		tmp->next = h;
		h = tmp;
	}
	return h;
}