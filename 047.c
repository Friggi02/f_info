/*Scrivere un programma in C che acquisisce 10 numeri interi. In seguito, il programma calcola i primi due valori massimi e li visualizza.*/

#include <stdio.h>
#define DIM 10

int main(){

	int a[DIM], i, max1, max2;

	for(i=0; i<DIM; i++){
		scanf("%d", &a[i]);
	}

	max1 = a[0];
	max2 = a[0];

	for(i=0; i<DIM; i++){
		if(a[i]>max1){
			max1 = a[i];
		}
	}

	for(i=0; i<DIM; i++){
		if(a[i]>max2 && a[i]!=max1){
			max2 = a[i];
		}
	}

	printf("%d %d\n", max1, max2);

	return 0;
}