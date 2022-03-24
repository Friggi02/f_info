/*Scrivere un sottoprogramma che riceve come parametri un array a1 di interi e la sua dimensione dim. Il sottoprogramma alloca 
dinamicamente un array della stessa dimensione dim, vi copia il contenuto di a1 e lo restituisce al chiamante. Gestire 
opportunamente gli eventuali errori di allocazione della memoria.

Scrivere un programma che dichiara un array da 10 elementi interi e lo popola con i valori letti da tastiera.
Il programma invoca il sottoprogramma sopra definito e visualizza il suo risultato.
Infine il programma rilascia la memoria allocata dinamicamente.
Gestire opportunamente gli eventuali errori di allocazione della memoria.*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 10

int* arraycopy(int[], int);

int main(){

	int a1[DIM], *a2, i;

	for(i=0; i<DIM; i++){
		scanf("%d", &a1[i]);
	}

	a2 = arraycopy(a1, DIM);

	if(a2){
		for(i=0; i<DIM; i++){
			printf("%d\n", *(a2+i));
		}
		free(a2);
	}

	return 0;
}

int* arraycopy(int a[], int dim){

	int i, *p;

	p = malloc(sizeof(int)*dim);

	if(p){
		for(i=0; i<dim; i++){
			*(p+i)= a[i];
		}
	}else{
		printf("errore\n");
	}

	return p;
}