/*Scrivere un programma in C che chiede all'utente una serie di numeri interi terminata dal valore 0 (che non fa parte della sequenza).
Il programma stabilisce se la serie, se non vuota, è monotona crescente (non strettamente) e visualizza un apposito messaggio di testo. */

#include <stdio.h>

int main(){

	int prec, curr, monotona;

	printf("inserire sequenza: ");
	scanf("%d", &prec);

	if(prec){
		monotona = 1;
		scanf("%d", &curr);
		while(curr){
			if(prec>curr){
				monotona = 0;
			}
			prec = curr;
			scanf("%d", &curr);
		}
		if(monotona){
			printf("serie monotona crescente\n");
		}else{
			printf("serie non monotona crescente\n");
		}
	}else{
		printf("sequenza vuota\n");
	}

	return 0;
}