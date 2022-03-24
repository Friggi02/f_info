/*Scrivere un sottoprogramma compattaarray che riceve in ingresso un array di numeri interi positivi e qualsiasi altro parametro ritenuto
strettamente necessario. Il sottoprogramma rimuove dall’array tutti i numeri non primi e restituisce al chiamate il numero di elementi alla fine presenti nell’array.

Scrivere un programma che chiede all’utente quanti dati vorrà fornire (al più 200) e fino a quando l’utente non dà una risposta valida lo richiede.
Acquisiti i valori, il programma chiama il sottoprogramma compattaarray e poi visualizza il contenuto dell’array.*/

#include <stdio.h>
#define DIM 200

int primo(int);
int compattaarray(int[], int);

int main(){

	int dim, arr[DIM], i;

	do{
		printf("numero di valori da inserire: ");
		scanf("%d", &dim);
	}while(dim<=0 || dim>DIM);

	for(i=0; i<dim; i++){
		scanf("%d", &arr[i]);
	}

	dim = compattaarray(arr, dim);

	for(i=0; i<dim; i++){
		printf("%d ", arr[i]);
	}
	printf("\n%d\n", dim);

	return 0;
}

int primo(int n){

	int i, trovato;

	for(i=2, trovato=0; i*i<=n && !trovato; i++){
		if(n%i==0){
			trovato = 1;
		}
	}

	return n!=1 && !trovato;
}

int compattaarray(int arr[], int dim){

	int i, j;

	for(i=0, j=0; i<dim; i++){
		if(primo(arr[i])){
			arr[j] = arr[i];
			j++;
		}
	}

	return j;
}