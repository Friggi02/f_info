/*Scrivere un programma in C che chiede i dati di due matrici quadrate 4x4 di interi.
Il programma calcola e visualizza il loro prodotto matriciale.*/

#include <stdio.h>
#define DIM 4

int main(){

	int mat1[DIM][DIM], mat2[DIM][DIM], mat3[DIM][DIM], i, j, k;

/*ACQUISIZIONE MATRICE 1*/
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			scanf("%d", &mat1[i][j]);
		}
	}

/*ACQUISIZIONE MATRICE 2*/
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			scanf("%d", &mat2[i][j]);
		}
	}

/*ELABORAZIONE*/
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			for(k=0, mat3[i][j]=0; k<DIM; k++){
				mat3[i][j] += mat1[i][k]*mat2[k][j];
			}
		}
	}

/*VISUALIZZAZIONE*/
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			printf("%3d", mat3[i][j]);
		}
		printf("\n");
	}

	return 0;
}