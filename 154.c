/*
Scrivere un programma che esegue due volte le seguenti elaborazioni. 
Il programma chiede all'utente il numero di valori interi da acquisire.
Il programma alloca dinamicamente un array della dimensione specificata e lo popola con i valori acquisiti da tastiera.
In seguito il programma visualizza la sequenza di valori acquisiti al rovescio e libera la memoria allocata dinamicamente. 
Visualizzare un errore nel caso si verifichi un errore di allocazione della memoria.	*/

#include<stdio.h>
#include<stdlib.h>
#define QUANTEVOLTE 2

void* malloc(size_t dim);

int main() {

	int dim, i, *p, j;
	
	for(j=0; j<QUANTEVOLTE; j++){
		
		scanf("%d", &dim);
		
		p = (int*)malloc(dim*sizeof(int));
		
		if(p){
			for(i=0; i<dim; i++){
				scanf("%d", p+i);
			}
			for(i=dim-1; i>=0; i--){
				printf("%d\n", *(p+i));
			}
			free(p);
		}else{
			printf("Errore allocazione\n");
		}
	}

	return 0;
}