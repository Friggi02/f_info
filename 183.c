/*Scrivere un sottoprogramma ricorsivo che riceve come parametro la testa di una lista di interi e la modifica sommando a ogni elemento 
il valore di tutti gli elementi ad esso successivi (l'ultimo elemento resta invariato), e restituisca la somma di tutti i valori nella lista.

Es: Data la lista 
l: 1->2->10->3->6 
il sottoprogramma la modifica in 
l: 22->21->19->9->6 
e restituisce il valore 22

Scrivere un programma che chiede all'utente una sequenza di lunghezza indefinita di numeri interi chiesta all'utente e terminata dal valore 0 (che non fa parte della 
sequenza) per popolare una lista dinamica. Il programma invoca il sottoprogramma e visualizza il risultato.*/

#include<stdio.h>
#include<stdlib.h>
#include"lista.c"
#define TERMINATORE 0

int calcolaSomme(nodo_t*);

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

	n = calcolaSomme(h);

	visualizza(h);

	printf("%d\n", n);

	return 0;
}

int calcolaSomme(nodo_t *h){

	if(h==NULL){
		return 0;
	}
	h->num += calcolaSomme(h->next);

	return h->num;
}