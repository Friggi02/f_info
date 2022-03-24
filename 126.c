/*Realizzare un sottoprogramma che riceve come parametro una matrice bidimensionale di interi dichiarata nel chiamate con un numero di 
colonne pari a 5, e qualsiasi altro parametro ritenuto strettamente necessario. Il sottoprogramma visualizza il contenuto della matrice.
Scrivere un programma che dichiara una matrice di interi 5x5, chiede all'utente quanti dati si vuole inserire nella matrice (numero di 
righe e colonne - che si assume vengano inseriti correttamente dall'utente) ed i dati per popolare la matrice; il programma invoca 
il sottoprogramma sopra definito.*/

#include <stdio.h>
#define NC 5
#define NR 5
void stampa(int[][NC], int, int);

int main(){
	
	int m[NC][NR], nr, nc, i, j;

	printf("numero righe: ");
	scanf("%d", &nr);
	printf("numero colonne: ");
	scanf("%d", &nc);

	for(i=0; i<nr; i++){
		for(j=0; j<nc; j++){
			scanf("%d", &m[i][j]);
		}
	}

	stampa(m, nr, nc);

	return 0;
}

void stampa(int m[][NC], int nr, int nc){

	int i, j;

	for(i=0; i<nr; i++){
		for(j=0; j<nc; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}
