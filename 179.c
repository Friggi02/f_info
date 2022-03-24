/*
Si realizzino i seguenti sottoprogrammi utilizzando la struttura dati e funzioni fornite nei file lista.c e lista.h.

Scrivere un sottoprogramma estrai() che riceve come parametro una lista dinamica di numeri interi detta l1, e un parametro intero detto dispari. Il sottoprogramma 
restituisce un puntatore ad una nuova lista l2 contenente gli elementi di l1 in posizione dispari se il parametro dispari vale 1, o gli elementi in posizione pari 
se il parametro dispari vale 0. 
NOTA: con "posizione" si intende l'equivalente dell'indice se stessimo parlando di vettori invece che di liste: il primo elemento della lista ha indice zero (pari), 
il secondo elemento ha indice 1 (dispari), e così via.

Scrivere un sottoprogramma uguali() che verifica se due liste ricevute come parametro sono uguali, cioè contengono la stessa sequenza di numeri e restituisce 1 in caso positivo 0 altrimenti.

Scrivere un sottoprogramma stessoContenuto() che verifica se due liste l1 ed l2 ricevute come parametro contengono gli stessi valori, a prescindere dall'ordine; 
cioè se una lista è una permutazione dell'altra. Il sottoprogramma restituisce 1 incaso positivo 0 altrimenti.
Suggerimento: perché l1 sia permutazione di l2 basta controllare che le due liste abbiano pari lunghezza e che ciascun valore presente in l1 compaia sia in l1 che in
l2 lo stesso numero di volte. Si suggerisce inoltre di implementare anche un sottoprogramma di ausilio conta()
che riceve come parametri una lista ed un valore intero, e restituisce quante volte il valore intero compare nella lista .


Scrivere un sottoprogramma unisci() che riceve come parametri due liste l1 ed l2. Il sottoprogramma crea e restituisce una nuova lista concatenando il contenuto di l1 con quello di l2.

Scrivere un programma che carica dal file di testo "serie.txt" (il cui nome è stato passato come argomento alla chiamata del programma) una serie di lunghezza 
indefinita di numeri interi e li memorizza in una lista lf. Il programma, invocando i sottoprogrammi sopra definiti:

1) crea una nuova lista lp, contenente i valori in posizione pari della lista lf. 
2) crea una nuova lista ld, contenente i valori in posizione dispari della lista lf. 
3) verifica se lp è uguale a ld ed in caso negativo se almeno contengono gli stessi numeri sebbene in ordine diverso. Il programma stampa a video gli esiti dei test.
4) genera una nuova lista u in cui appaiono prima tutti gli elementi di lf originariamente in posizione pari e poi gli elementi originariamente in posizione dispari. 

Il programma visualizza: (a) la lista di partenza, (b) la lista degli elementi in posizione pari, (c) la lista degli elementi in posizione dispari, (d) la nuova 
lista con gli elementi riordinati come specificato.

Infine il programma termina deallocando tutta la memoria allocata.

*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

nodo_t* estrai(nodo_t*, int);
int uguali(nodo_t*, nodo_t*);
int conta(nodo_t*, int);
int stessoContenuto(nodo_t*, nodo_t*);
nodo_t* unisci(nodo_t*, nodo_t*);

int main(int argc, char *argv[]){

	int n;
	nodo_t *lf, *lp, *ld, *u;

	lf = NULL;
	lp = NULL;
	ld = NULL;
	u = NULL;

	FILE *fp;

/*ACQUISIZIONE*/
	if(argc==2){
		fp = fopen(argv[1], "r");
		if(fp){
			fscanf(fp, "%d", &n);
			while(!feof(fp)){
				lf = inserisciInCoda(lf, n);
				fscanf(fp, "%d", &n);
			}
			fclose(fp);		
		}else{
			printf("errore apertura file\n");
		}
	}else{
		printf("errore argomenti\n");
	}

/*ELABORAZIONE 1*/
	lp = estrai(lf, 0);

/*ELABORAZIONE 2*/
	ld = estrai(lf, 1);

/*ELABORAZIONE 3*/
	if(uguali(lp, ld)){
		printf("lp e ld sono uguali\n");
	}else{
		if(stessoContenuto(lp, ld)){
			printf("lp e ld hanno gli stessi elementi in posizioni diverse\n");
		}else{
			printf("lp e ld sono diverse\n");
		}
	}

/*ELABORAZIONE 4*/
	u = unisci(lp, ld);

/*VISUALIZZAZIONE*/
	printf("\nlista di partenza\n");
	visualizza(lf);
	printf("\nlista posizioni pari\n");
	visualizza(lp);
	printf("\nlista posizioni dispari\n");
	visualizza(ld);
	printf("\nlista unione\n");
	visualizza(u);

/*DEALLOCAZIONE*/
	distruggi(lf);
	distruggi(lp);
	distruggi(ld);
	distruggi(u);

	return 0;
}

nodo_t* estrai(nodo_t *l1, int dispari){

	nodo_t* l2;
	int i;

	i = 0;
	l2 = NULL;

	if(dispari){
		while(l1){
			if(i%2){
				l2 = inserisciInCoda(l2, l1->num);
			}
			l1 = l1->next;
			i++;
		}
	}else{
		while(l1){
			if(!(i%2)){
				l2 = inserisciInCoda(l2, l1->num);
			}
			l1 = l1->next;
			i++;
		}
	}

	return l2;
}

int uguali(nodo_t *l1, nodo_t *l2){

	int ok;

	for(ok=1; l1 && l2 && ok; l1=l1->next, l2=l2->next){
		if(l1->num!=l2->num){
			ok = 0;
		}
	}

	if((ok && l1) || (ok && l2)){
		ok = 0;
	}

	return ok;
}

int conta(nodo_t* lista, int n){

	int conto;
   
	for(conto=0; lista; lista=lista->next){
		if(lista->num==n){
			conto++;
		}
	}

	return conto;
}

int stessoContenuto(nodo_t *l1, nodo_t *l2){

	int ok;

	ok = (lunghezza(l1) == lunghezza(l2));

	for(; l1 && ok; l1=l1->next){
		if(conta(l1, l1->num)!=conta(l2, l1->num)){
			ok = 0;
		}		
	}

	return ok;
}

nodo_t* unisci(nodo_t *l1, nodo_t *l2){

	nodo_t* out;
	
	out = NULL;

	while(l1){
		out = inserisciInCoda(out, l1->num);
		l1 = l1->next;
	}

	while(l2){
		out = inserisciInCoda(out, l2->num);
		l2 = l2->next;
	}

	return out;
}
