/*Scrivere un programma in C che chiede all'utente di inserire 5 numeri interi e poi li visualizza in ordine inverso.*/

#include <stdio.h>
#define DIM 5

int main(){

	int array[DIM] ;
	int i;

	printf("inserire sequenza: ");
	
	for(i=0; i<DIM; i++){
		scanf("%d", &array[i]);
	}
	
	for(i=DIM-1; i>=0 ; i--){
		printf("%d\n", array[i]);
	}

	return 0;
}