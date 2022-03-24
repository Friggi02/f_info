/*Scrivere un sottoprogramma ricorsivo che riceve come parametri un array di interi ordinati in ordine crescente (e la sua dimensione) 
ed un numero n. Il sottoprogramma verifica se n è contenuto nell'array utilizzando il metodo della bisezione.
In caso affermativo restituisce 1 altrimenti 0.

Scrivere un programma che chiede all'utente 10 valori interi, invoca il sottoprogramma definito e visualizza il risultato.*/


#include <stdio.h>
#define DIM 5

int bisezione(int[], int, int);

int main(){
	
	int array[DIM], i, risultato, n;
	
	for(i=0; i<DIM; i++){
		scanf("%d", &array[i]);
	}

	scanf("%d", &n);
	
	risultato = bisezione(array, DIM, n);

	printf("%d\n", risultato);
	
	return 0;
}

int bisezione(int a[], int dim, int n){
	
	if(dim==0){
		return 0;
	}

	if(a[dim/2]==n){
		return 1;
	}

	if(a[dim/2]>n){
		return bisezione(a, dim/2, n);
	}
	
	return contenuto(&a[dim/2+1], dim-(dim/2+1), n);
}