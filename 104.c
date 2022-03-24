/*Scrivere un sottoprogramma che riceve come parametri un array di interi e la sua dimensione. Il sottoprogramma sostituisce ciascun 
valore negativo dell'array con il suo valore assoluto. Scrivere un programma che chiede all'utente 10 valori da memorizzare in un 
array, invoca la funzione sopra definita e visualizza il contenuto finale dell'array.*/

#include <stdio.h>
#define DIM 10

void arrayassoluti(int *a, int dim);

int main(){

	int a[DIM], i;

	for(i=0; i<DIM; i++){
		scanf("%d", &a[i]);
	}

	arrayassoluti(a, DIM);

	for(i=0; i<DIM; i++){
		printf("%d", a[i]);
	}

	printf("\n");

	return 0;
}

void arrayassoluti(int *a, int dim){

	int i;

	for(i=0; i<DIM; i++){
		if(*(a+i)<0){
			*(a+i) = -(*(a+i));
		}
	}	
}
