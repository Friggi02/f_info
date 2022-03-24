/*Scrivere un programma in C che chiede all'utente di inserire una sequenza 10 numeri interi.
Il programma visualizza tutti i pari, poi tutti i dispari.*/

#include <stdio.h>
#define DIM 10

int main(){

	int a[DIM] ;
	int i;

	printf("inserire sequenza: ");

	for(i=0; i<DIM; i++){
		scanf("%d", &a[i]);
	}

	for(i=0; i<DIM; i++){
		if(!(a[i]%2)){
			printf("%d\n", a[i]);
		}
	}

	for(i=0; i<DIM; i++){
		if(a[i]%2){
			printf("%d\n", a[i]);
		}
	}

	return 0;
}