/*Scrivere un sottoprogramma ricorsivo che riceve due numeri interi positivi a e b e calcola
risultato e resto della divisione intera a/b (senza l'utilizzo degli operatori / e %).

Scrivere un programma che acquisisce due valori x e y ed invoca la 
funzione sopra definita, visualizzando poi il risultato.*/

#include <stdio.h>

void divisione(int, int, int*, int*);

int main(){

	int a, b, quoziente, resto;

	scanf("%d %d", &a, &b);

	divisione(a, b, &quoziente, &resto);

	printf("quoziente: %d\nresto: %d\n", quoziente, resto);

	return 0;
}

void divisione(int a, int b, int *quoziente, int *resto){
	if(a<b){
		*quoziente = 0;
		*resto = a;
	}else{
		divisione(a-b, b, quoziente, resto);
		*quoziente += 1;
	}
}
