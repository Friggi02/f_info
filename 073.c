/*Scrivere un programma in C che chiede all'utente i dati di due matrici di interi, la prima 5x5 e la seconda 2x2.
Il programma calcola e visualizza il numero di volte che la seconda matrice è contenuta nella prima.*/

#include <stdio.h>
#define DIM_A 5
#define DIM_B 2

 int main()
{
	int a[DIM_A][DIM_A], b[DIM_B][DIM_B], i, j, h, k, conto, issub;

/*ACQUISIZIONE*/
	printf("matrice A:\n");
	for(i=0; i<DIM_A; i++){
		for(j=0; j<DIM_A; j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("matrice b:\n");
	for(i=0; i<DIM_B; i++){
		for(j=0; j<DIM_B; j++){
			scanf("%d", &b[i][j]);
		}
	}

/*ELABORAZIONE*/
	for(i=0, conto=0; i<=DIM_A-DIM_B; i++){
		for(j=0; j<=DIM_A-DIM_B; j++){
			for(h=0, issub=1; h<DIM_B && issub; h++){
				for(k=0; k<DIM_B && issub; k++){
					if(a[i+h][j+k]!=b[h][k]){
						issub = 0;
					}
				}
			}
			if(issub){
				conto++;
			}
		}
	}

/*VISUALIZZAZIONE*/
	printf("%d\n", conto);
	
	return 0;
}