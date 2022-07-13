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

int** alloca_matrice(int**, int);
int** dealloca_matrice(int**, int);

int main(){

	int dim, i, j, n, k, l, conto;
	int** mat;

/*ACQUISIZIONE DIMENSIONE MATRICE*/
	printf("inserire dimensione matrice quadrata: ");
	scanf("%d", &dim);

/*ALLOCAZIONE DELLA MATRICE*/
	mat = alloca_matrice(mat, dim);

/*ACQUISIZIONE VALORI DELLA MATRICE*/
	printf("inserire i valori della matrice:\n");
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			scanf("%d", &mat[i][j]);
		}
	}

/*CONTROLLO DELLA MATRICE ACQUISITA*/
	printf("\nmatrice acquisita:\n");
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			printf("%2d ", mat[i][j]);
		}
		printf("\n");
	}

/*ELABORAZIONE*/
	for(n=2; n<=dim; n++){
		printf("\nN=%d\n", n);
		for(i=0; i<dim-n; i++){
			for(j=0; j<dim-n; j++){
				for(k=0, conto=0; k<n; k++){
					for(l=0; l<n; l++){
						conto += mat[i+k][j+l];
					}
				}
				if(conto==0){
					for(k=0; k<n; k++){
						for(l=0; l<n; l++){
							printf("%2d ", mat[i+k][j+l]);
						}
						printf("\n");
					}
				}
			}
		}
	}

/*DEALLOCAZIONE DELLA MATRICE*/
	mat = dealloca_matrice(mat, dim);

	return 0;
}

int** alloca_matrice(int **mat,int dim){

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

int** dealloca_matrice(int **mat, int dim){

	int i;

	for(i=dim; i=0; i--){
		free(mat[i]);
	}

	free(mat);

	return mat;
}