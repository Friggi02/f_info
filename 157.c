/*
Scrivere un sottoprogramma che riceve come parametro un intero positivo N, alloca dinamicamente e restituisce una matrice quadrata 
NxN. Il sottoprogramma restituisce NULL nel caso di errore di allocazione (deallocando l'eventuale memoria già allocata).

Scrivere un sottoprogramma che riceve come parametro una matrice bidimensionale allocata dinamicamente ed il suo numero di righe, e 
ne libera la memoria.

Scrivere un programma che chiede all'utente la dimensione di una matrice quadrata m e poi i dati per popolarla; non sapendo a priori 
le dimensioni della matrice m, il programma allocherà la matrice mediante il sottoprogramma sopra definito. Il programma cerca nella 
matrice m la sottomatrice di dimensione massima che parte da m[0][0] e la cui somma dei valori è pari a zero e, se esiste, la salva in 
una seconda matrice allocata anch'essa dinamicamente. In seguito, il programma stampa a video la nuova matrice calcolata (se esiste), 
libera la memoria e termina. Gestire opportunamente gli eventuali errori nell'allocazione della memoria.

Esempio: se l'utente inserisce la matrice 3x3:
1 2 3
-1 -2 3
3 3 3
La sottomatrice a somma nulla di dimensione massima che parte da m[0][0] è:
1  2
-1 -2		*/

#include <stdio.h>
#include <stdlib.h>

void* alloca_matrice(int**, int);
void* dealloca_matrice(int**, int);

int main(){

	int dim;

	printf("inserire dimensione matrice quadrata: ");
	scanf("%d", &dim);
	
	return 0;
}

void* alloca_matrice(int **mat,int dim){

	int i;

	mat = (int**)malloc(dim*sizeof(int*));

	if(mat){
		mat[0] = (int*)malloc(dim*dim*sizeof(int));
		if(mat[0]){
			for(i=1; i<dim; i++){
				mat[i] = mat[0]+(i*dim);
			}
		}else{
			free(mat[0]);
			return NULL;
		}
	}else{
		free(mat);
		return NULL;
	}

	return mat;
}

void* dealloca_matrice(int **mat, int dim){

	int i;

	for(i=dim; i=0; i--){
		free(mat[i]);
	}

	free(mat);

	return mat;
}