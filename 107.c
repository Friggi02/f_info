/*
Scrivere un sottoprogramma che riceve come parametri un array di interi e la sua dimensione. Il sottoprogramma popola tutto l'array con valori chiesti all'utente.

Scrivere un secondo sottoprogramma che riceve come parametri un array di interi e la sua dimensione, quest'ultima passata per indirizzo.
Il sottoprogramma rimuove dall'array i valori duplicati ed aggiorna la dimensione ricevuta come parametro con il numero effettivo di valori validi contenuti nell'array.

Scrivere un terzo sottoprogramma che riceve come parametri due array con le relative dimensioni. Il sottoprogramma calcola l'intersezione 
del contenuto dei due array salvando il risultato in un terzo array ricevuto anch'esso come parametro; inoltre il sottoprogramma 
restituisce al chiamate tramite un ultimo parametro passato per indirizzo il numero effettivo di valori contenuti nell'intersezione.

Scrivere un sottoprogramma che riceve come parametri un array di interi e la sua dimensione e visualizza il contenuto dell'array.

Scrivere un programma che mediante l'ausilio dei sottoprogrammi sopra definiti:
1) chiede all'utente i dati di tre array contenenti 20 valori interi ciascuno
2) rimuove i duplicati in ciascuno di essi
3) visualizza i tre insiemi risultanti
4) calcola l'intersezione dei tre insiemi
5) visualizza il risultato finale																			*/

#include <stdio.h>
#define DIM 10

void acquisisci(int[], int);
void doppioni(int[], int*);
void intersezione(int[], int, int[], int, int[], int*);
void visualizza(int[], int);

int main(){

	int arr1[DIM], arr2[DIM], arr3[DIM], out[DIM], i, dim1, dim2, dim3, dim_out;
	dim1 = DIM;
	dim2 = DIM;
	dim3 = DIM;

	printf("array 1: ");
	acquisisci(arr1, DIM);
	printf("array 2: ");
	acquisisci(arr2, DIM);
	printf("array 3: ");
	acquisisci(arr3, DIM);

	doppioni(arr1, &dim1);
	printf("array 1 senza ripetizioni: ");
	visualizza(arr1, dim1);
	doppioni(arr2, &dim2);
	printf("array 2 senza ripetizioni: ");
	visualizza(arr2, dim2);
	doppioni(arr3, &dim3);
	printf("array 3 senza ripetizioni: ");
	visualizza(arr3, dim3);

	intersezione(arr1, dim1, arr2, dim2, out, &dim_out);
	intersezione(arr3, dim3, out, dim_out, arr1, &dim1);

	printf("intersezione: ");
	visualizza(arr1, dim1);



	return 0;
}

void acquisisci(int arr[], int dim){

	int i;

	for(i=0; i<dim; i++){
		scanf("%d", &arr[i]);
	}
}

void doppioni(int arr[], int *dim){

	int i, j, k, a2[*dim], trovato;

	for(i=0, k=0; i<*dim; i++){
		for(j=0, trovato=0; j<i && !trovato; j++){
			if(arr[i]==arr[j]){
				trovato = 1;		
			}
		}
		if(!trovato){
			a2[k]=arr[i];
			k++;
		}
	}
	*dim=k;
	for(i=0; i<*dim; i++){
		arr[i]=a2[i];
	}
}

void intersezione(int a1[], int d1, int a2[], int d2, int out[], int *dimout){

	int i, j;

	for(i=0, (*dimout)=0; i<d1; i++){
		for(j=0; j<d2; j++){
			if(a1[i]==a2[j]){
				out[*dimout] = a2[j];
				(*dimout)++;
			}
		}
	}
}

void visualizza(int arr[], int dim){

	int i;

	for(i=0; i<dim; i++){
		printf(" %d ", arr[i]);
	}
	printf("\n");
}
