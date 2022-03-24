/*Scrivere un sottoprogramma ricorsivo che riceve come parametro un 
array di interi (e la sua dimensione) e ne calcola e trasmette al 
chiamante il valore massimo ed il valore minimo.

Scrivere un programma che chiede all'utente 10 valori interi, invoca 
il sottoprogramma definito e visualizza i due risultati.*/

#include <stdio.h>
#define DIM 10

void maxmin(int[], int, int*, int*);

int main(){
	
	int a[DIM], i, max, min;

	for(i=0; i<DIM; i++){
		scanf("%d", &a[i]);
	}

	maxmin(a, DIM, &max, &min);

	printf("max: %d\nmin: %d\n", max, min);

	return 0;
}

void maxmin(int a[], int dim, int *max, int *min){

	if(dim>0){
		if(dim==DIM){
			*max = a[0];
			*min = a[0];
		}
	
		if(*max<a[0]){
			*max = a[0];
		}
	
		if(*min>a[0]){
			*min = a[0];
		}
		
		maxmin(a+1, dim-1, max, min);
	}
}
