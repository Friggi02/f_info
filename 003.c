/*Scrivere un programma in C che chiede all'utente due numeri interi. Il programma calcola e visualizza la media dei valori acquisti.
Si noti che la media è un valore reale.*/

#include <stdio.h>

int main(){

	int a, b;
	float media;

	printf("inserire i due numeri: ");
	scanf("%d %d", &a, &b);

	media = (float)(a+b)/2; 		/*cast esplicito*/

	printf("media: %f\n", media);

	return 0;
}