/*Scrivere un sottoprogramma chericeve in ingresso un array bidimensionale di interi mat, un intero vale qualsiasi parametro ritenuto strettamente
necessario e trasmette al chiamate gli indici di riga e colonna che identificano la posizione del primo elemento (scandendo l’array per righe) che,
sommato a tutti i suoi precedenti, dia come risultato un valore > val. Nel caso in cui tal elemento non esista, si trasmettono i valori -1, -1. Esiste
una direttiva #define NCOL 10.

Srcivere un programma che popola una matrice di interi 10 per 10 e che chide all'utente un valore soglia.
Il programma invoca il sottoprogramma e visualizza il risultato.*/

#include <stdio.h>
#define NCOL 10
#define NROW 10

void check(int[][NCOL], int, int*, int*, int, int);

int main(){

	int mat[NROW][NCOL], i, j, x, y, val;

	printf("inserisci matrice:\n");
	for(i=0; i<NROW; i++){
		for(j=0; j<NROW; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	printf("inserisci valore: ");
	scanf("%d", &val);

	check(mat, val, &x, &y, NROW, NCOL);
	
	printf("%d %d\n", x, y);

	return 0;
}

void check(int mat[][NCOL], int val, int *x, int *y, int n_row, int n_col){

	int somma, i, j;

	for(i=0, somma=0; i<n_row && somma<=val; i++){
		for(j=0; j<n_col && somma<=val; j++){
			somma += mat[i][j];
		}
	}

	if(somma<=val){
		*x = -1;
		*y = -1;
	}else{
		*x = i;
		*y = j;
	}
}