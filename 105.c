/*Scrivere un sottoprogramma che riceve come parametri due array a1 e a2 di interi e le relative dimensioni d1 e d2, quest'ultima passata 
per indirizzo. Il sottoprogramma individua i valori pari contenuti in a1 e li salva in a2, aggiornando in d2 il numero effettivo di valori salvati.
Scrivere un programma che chiede all'utente 10 valori da memorizzare in un array, invoca la funzione sopra definita e visualizza il contenuto finale dell'array.*/

#include <stdio.h>
#define DIM 10

void arraypari(int[], int, int*, int*);
int main(){

	int x[DIM], y[DIM], dy, i;

	for(i=0; i<DIM; i++){
		scanf("%d", &x[i]);
	}

	arraypari(x, DIM, y, &dy);

	for(i=0; i<dy; i++){
		printf("%d", y[i]);
	}

	printf("\n");

	return 0;
}

void arraypari(int a1[], int d1, int *a2, int *d2){

	int i;

	for(i=0, *d2=0; i<d1; i++){
		if(a1[i]%2==0){
			*a2 = a1[i];
			a2++;
			(*d2)++;
			/* EQUIVALENTE A
			*(a2+*d2)=a1[i];
			(*d2)++;
			*/
		}
	}
}
