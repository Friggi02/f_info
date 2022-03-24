/*
Scrivere un sottoprogramma che riceve in ingresso un array bidimensionale di interi (dichiarato con NC=5 colonne) e le 
dimensioni effettive della parte della matrice utilizzata. Il sottoprogramma restituisce la media dei valori contenuti nella matrice.

Scrivere un sottoprogramma che riceve in ingresso un array bidimensionale di interi (dichiarato con NC=5 colonne), le 
dimensioni effettive della parte della matrice utilizzata e un valore n in virgola mobile. Il sottoprogramma trasmette
al chiamante le coordinate del valore più si avvicina a n. Se più valori hanno stessa distanza minima selezionare l'ultimo.

Scrivere un programma che chiede all'utente i dati di una matrice 5x5 di interi, invoca i sottoprogrammi sopra definiti e visualizza i risultati.*/

#include <stdio.h>

#define NCOL 5
#define NROW 5

void media_matrice(int[][NCOL], int, int, float*);
void trova_vicino(int[][NCOL], int, int, float, int*, int*);

int main(){

	int mat[NROW][NCOL], riga, colonna, i, j;
	float media;

	for(i=0; i<NROW; i++){
		for(j=0; j<NCOL; j++){
			scanf("%d", &mat[i][j]);	
		}
	}

	media_matrice(mat, NROW, NCOL, &media);

	printf("media: %f\n", media);

	trova_vicino(mat, NROW, NCOL, media, &riga, &colonna);
	printf("valore che si avvicina maggiormente alla media: %d\ndi coordinate: %d %d\n", mat[riga][colonna], riga, colonna);
	
	return 0;
}

void media_matrice(int mat[][NCOL], int n_rows, int n_columns, float *media){

	int i, j, somma;

	for(i=0, somma=0; i<n_rows; i++){
		for(j=0; j<n_columns; j++){
			somma += mat[i][j];
		}
	}

	*media = (float)somma/(float)(n_rows*n_columns);
}

void trova_vicino(int mat[][NCOL], int n_rows, int n_columns, float n, int *riga, int *colonna){

	int i, j;
	float delta_curr, delta_min;

	delta_min = (mat[0][0]-n)*(mat[0][0]-n);

	for(i=0; i<n_rows; i++){
		for(j=0; j<n_columns; j++){
			delta_curr = (mat[i][j]-n)*(mat[i][j]-n);
			if(delta_curr<=delta_min){
				delta_min = delta_curr;
				*riga = i;
				*colonna = j;
			}
		}
	}
}
