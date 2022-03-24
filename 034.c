/*Scrivere un programma in C che ricevuto in ingresso due numeri interi positivi a e b (e se così non è, li richiede),
visualizza un rettangolo di dimensione a*b usando il carattere '*'.   */

#include <stdio.h>

int main(){

	int a, b, i;

	do{
		printf("inserire la lunghezza dei due lati: ");
		scanf("%d %d", &a, &b);
	}while(a<=0 || b<=0);

	while(a>0){
		i = b;
		while(i>0){
			printf("*");
			i--;
		}
		printf("\n");
		a--;
	}

	return 0;
}