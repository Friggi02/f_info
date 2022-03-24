/*Scrivere un programma che chiede all'utente tre numeri interi e, mediante l'utilizzo di un puntatore, identifica e visualizza il valore massimo.
Estendere il programma in modo tale che chieda 10 valori da salvare in un array ed in seguito calcoli e visualizzi il valore massimo.*/

#include <stdio.h>
#define DIM 10

int main(){

	int a[DIM], *max, i;

	for(i=0; i<DIM; i++){
		scanf("%d", &a[i]);
	}

	max = &a[0];

	for(i=0; i<DIM; i++){
		if(*max<a[i]){
			max = &a[i];
		}
	}

	printf("%d\n", *max);

	return 0;
}