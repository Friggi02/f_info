/*
Scrivere un sottoprogramma che riceve come parametro una matrice di interi dichiarata nel chiamante con NC=10 colonne, e le dimensioni 
di tale matrice. Il sottoprogramma chiede all'utente i dati per popolare tale matrice.

Scrivere un sottoprogramma che riceve come parametro una matrice di interi dichiarata nel chiamante con NC=10 colonne, e le dimensioni 
di tale matrice. Il sottoprogramma visualizza sullo schermo il contenuto della matrice.

Scrivere un programma che dichiara una matrice 10x10 di interi. Il programma utilizza i due sottoprogrammi sopra definiti per acquisire 
i dati dell'intera matrice e la visualizza. In seguito il programma chiede all'utente le dimensioni di una sottomatrice della matrice 
sopra dichiarata (si assuma che l'utente inserisca i due valori correttamente). Il programma popola e visualizza la sottomatrice 
mediante i due sottoprogrammi sopra definiti.*/

#include <stdio.h>
#define NC 10
#define NR 10

void acquisisci(int[NR][NC], int, int);
void visualizza(int[NR][NC], int, int);


int main(){

	int m[NR][NC], sub_nr, sub_nc;

	acquisisci(m, NR, NC);
	visualizza(m, NR, NC);

	printf("numero colonne: ");
	scanf("%d", &sub_nc);
	printf("numero righe: ");
	scanf("%d", &sub_nr);

	acquisisci(m, sub_nr, sub_nc);
	visualizza(m, sub_nr, sub_nc);
	
	return 0;
}

void acquisisci(int m[NR][NC], int nr, int nc){

	int i, j;


	for(i=0; i<nr; i++){
		for(j=0; j<nc; j++){
			scanf("%d", &m[i][j]);
		}
	}
}

void visualizza(int m[NR][NC], int nr, int nc){

	int i, j;

	for(i=0; i<nr; i++){
		for(j=0; j<nc; j++){
			printf(" %2d ", m[i][j]);
		}
		printf("\n");
	}
}

