/*
Scrivere un sottoprogramma che dato un array bidimensionale A di numeri interi di dimensione N M e un array b di dimensione inferiore al numero
di colonne presenti nell'array bi-dimensionale verifica e restituisce al chiamante il numero di righe in cui l'array b compare nell'array A.

Se l'array b compare in una riga dell'array A, compare una unica volta.
Si assuma che l'array bidimensionale sia stato dichiarato nel chiamante con dimensione
definita con le direttive
#define N
#define M

Ad esempio, siano dati l'array bidimensionale A e l'arrayb sotto riportati:

A:
10  4  7  3  8  4  5
 2  1  3  8  5  5  9
 1 17  6  5  4 11  6
 3  7  3  8  3  8  5
 1  3  8  2  4 12 16

B:
3 8 5

il sottoprogramma restituisce 2.	

Scrivere un programma che chiede all'utente le dimensione di un array bidimensionale e lo popola.
Chiede la dimensione di un array monodimensionale, controlla sia minore del numero di colonne della matrice a e lo popola.
Il programma richiama il sottoprogramma e visualizza il risultato.*/

#include <stdio.h>

#define N 10
#define M 10

int conta(int[][M], int, int, int[], int);

int main(){

	int a[N][M], b[M-1], nc, nr, n, dim, i, j;

	do{
		printf("inerisci numero colonne: ");
		scanf("%d", &nc);
	}while(nc<=0);

	do{
		printf("inerisci numero righe: ");
		scanf("%d", &nr);
	}while(nr<=0);

	printf("iserisci matrice A:\n");
	for(i=0; i<nr; i++){
		for(j=0; j<nc; j++){
			scanf("%d", &a[i][j]);
		}
	}

	do{
		printf("inerisci dimensione array b: ");
		scanf("%d", &dim);
	}while(dim>=M);

	printf("iserisci array B:\n");
	for(i=0; i<dim; i++){
		scanf("%d", &b[i]);
	}

	printf("\noccorenze: %d\n", conta(a, nr, nc, b, dim));

	return 0;
}

int conta(int a[] [M], int nr, int nc, int b[], int dim){
	
	int i, j, k, conteggio, ok, trovato;
	
	for(i=0, conteggio=0; i<nr; i++){
		for(j=0, trovato=0; j<=nc-dim && !trovato; j++){
			for(k=0, ok=1; k<dim && ok; k++){
				if(a[i][j+k] !=b[k]){
					ok=0;
				}
			}
			if(ok){
				conteggio++;
				trovato = 1;
			}
		}
	}

	return conteggio;
}