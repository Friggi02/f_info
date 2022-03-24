/*Scrivere un sottoprogramma ricorsivo che riceve come parametro un array di
interi (e la sua dimensione) e ne calcola e restituisce il valore massimo.

Scrivere un programma che chiede all'utente 10 valori interi, invoca 
il sottoprogramma definito e visualizza il risultato.*/

#include <stdio.h>
#define DIM 10

int trova_max(int*, int);

int main(){
	
	int a[DIM], i, max;

	for(i=0; i<DIM; i++){
		scanf("%d", &a[i]);
	}

	max = trova_max(a, DIM);

	printf("%d\n", max);

	return 0;
}

int trova_max(int *a, int dim){

	int max_altri;

	if(dim==1){
		return *a;
	}

	max_altri = trova_max(a+1, dim-1);

	if(*a>max_altri){
		return *a;
	}

	return max_altri;	
}
