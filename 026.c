/*Scrivere un programma in C che calcola il massimo di una sequenza di 50 numeri interi inseriti dall'utente e visualizza il risultato.*/

#include <stdio.h>
#define ELEMENTI 50

int main(){

	int n, max, i;

	scanf("%d", &max);

	i = 0;
	while(i<(ELEMENTI-1)){
		scanf("%d", &n);
		if(n>max){
			max = n;
		}
		i = i+1;
	}

	printf("massimo: %d\n", max);

	return 0;
}