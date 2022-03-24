/*Scrivere un programma in C che visualizza la tabella pitagorica.*/

#include <stdio.h>
#define MAX 10

int main(){

	int i, j, prodotto;

	i = 1;
	while(i<=MAX){
		j = 1;
		while(j<=MAX){
			prodotto = i*j;
			printf("%4d", prodotto);
			j = j+1;
		}
		printf("\n");
		i = i+1;
	}

	return 0;
}