/*Scrivere un sottoprogramma che riceve in ingresso due numeri interi e restituisce (mediante parametri passati per indirizzo) sia il massimo che il minimo tra i due.
Scrivere un programma che chiede all'utente due numeri e mediante l'utilizzo del sottoprogramma sopra definito, visualizza il minimo ed il massimo.*/

#include <stdio.h>

void max_min(int, int, int*, int*);

int main(){

	int a, b, min, max;
 	
 	scanf("%d %d", &a, &b);

 	max_min(a, b, &min, &max);

	printf("max: %d\nmin: %d\n", max, min);

	return 0;
}

void max_min(int a, int b, int *min, int *max){

	if(a>b){
		*max = a;
		*min = b;
	}else{
		*max = b;
		*min = a;
	}
}