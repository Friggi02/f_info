/*Scrivere un sottoprogramma int2list che ricevuto in ingresso un numero intero e una lista restituisce una lista in cui ogni cifra del numero in ingresso
compare tante volte quanto il suo valore. Nel caso in cui il valore ricevuto in ingresso sia negativo, il sottoprogramma restituisce la lista creata
a partire dalla cifre in ordine opposto.

Se per esempio il sottoprogramma riceve in ingresso l’intero 3204, il sottoprogramma restituisce la lista seguente:
3 → 3 → 3 → 2 → 2 → 4 → 4 → 4 → 4
Se per esempio il sottoprogramma riceve in ingresso l’intero -3204, il sottoprogramma restituisce la lista seguente:
4 → 4 → 4 → 4 → 2 → 2 → 3 → 3 → 3

Scrivere un programma che acquisisce da riga di comando il valore intero, invoca il sottoprogramma int2list e visualizza il risultato.*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

nodo_t* int2list(nodo_t*, int);

int main(int argc, char *argv[]){
	
	nodo_t *h;
	int n;

	h = NULL;
	
	if(argc==2){
		n = atoi(argv[1]);
		h = int2list(h, n);
		visualizza(h);
	}else{
		printf("errore argomenti\n");
	}

	return 0;
}

nodo_t* int2list(nodo_t *h, int n){

	int cifra, i, neg;
	
	if(n<0){
		n = -n;
		neg = 1;
	}else{
		neg = 0;
	}

	while(n>0){
		cifra = n%10;
		n = n/10;
		for(i=0; i<cifra; i++){
			if(neg){
				h = inserisciInCoda(h, cifra);
			}else{
				h = inserisciInTesta(h, cifra);
			}
		}
	}

	return h;
}