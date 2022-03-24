/*Scrivere un programma in C che chiede all'utente di inserire i dati interi di un array
bidimensionale quadrato di dimensione 4x4 e visualizza 1 se la matrice è simmetrica, altrimenti 0.*/

#include <stdio.h>
#define DIM 4

int main(){

	int mat[DIM][DIM], i, j, simmetrica;

	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			scanf("%d", &mat[i][j]);
		}
	}

	for(i=0, simmetrica=1; i<DIM && simmetrica; i++){
		for(j=0, simmetrica=1; j<DIM && simmetrica; j++){
			if(mat[i][j]!=mat[j][i]){
				simmetrica = 0;
			}
		}
	}

	printf("esito: %d\n", simmetrica);

	return 0;
}