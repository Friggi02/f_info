/*Scrivere un sottoprogramma che riceve in ingresso un array bidimensionale di interi mat (dichiarato nel chiamate con NCOL=10), 
un intero val e qualsiasi parametro ritenuto strettamente necessario e trasmette al chiamate gli indici di riga e colonna che 
identificano la posizione del primo elemento (scandendo l'array per righe) che, sommato a tutti i suoi precedenti, dia come risultato un 
valore > val. Nel caso in cui tal elemento non esista, si trasmettono i valori -1, -1. 
*/

#include <stdio.h>
#define NCOL 10
#define NRIG 10

void somme_precedenti(int[][NCOL], int, int, int, int*, int*);

int main(){

	int mat[NRIG][NCOL], valore, riga, colonna, i, j;

	for(i=0; i<NRIG; i++){
		for(j=0; j<NCOL; j++){
			scanf("%d", &mat[i][j]);	
		}
	}

	printf("inserire soglia: ");
	scanf("%d", &valore);

	somme_precedenti(mat, NRIG, NCOL, valore, &riga, &colonna);

	printf("%d %d\n", riga, colonna);
	
	return 0;
}

void somme_precedenti(int mat[][NCOL], int n_righe, int n_colonne, int soglia, int *righe_fine, int *colonne_fine){

	int i, j, somma, fine;

	for(i=0, somma=0, fine=0; i<n_righe && !fine; i++){
		for(j=0; j<n_colonne && !fine; j++){
			somma += mat[i][j];
			if(somma>soglia){
				fine = 1;
				*righe_fine = i;
				*colonne_fine = j;
			}
		}
	}

	if(!fine){
		*righe_fine = -1;
		*colonne_fine = -1;
	}
}