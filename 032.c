/*Scrivere un programma in C che analizza un sequenza di numeri interi di lunghezza indefinita terminata dal valore 0 (che non fa parte 
della sequenza). In particolare, per ciascun valore letto, il programma stabilisce se questo è il doppio del suo precedente; in 
tal caso stampa a video la coppia di numeri. NOTA: attenzione al caso in cui la sequenza sia vuota (cioè l'utente inserisce 0 come 
primo valore).

Esempio:
L'utente inserisce la sequenza: 1 2 5 2 4 8 5 4 5 0
Il programma stamperà:
1 2
2 4
4 8          */

#include <stdio.h>

int main(){

	int prec, curr;

	printf("inserire sequenza: ");
	scanf("%d", &prec);

	if(prec){
		scanf("%d", &curr);
		while(curr){
			if(curr==2*prec){
				printf("%d %d\n", prec, curr);
			}
			prec = curr;
			scanf("%d", &curr);
		}
	}else{
		printf("sequenza vuota\n");
	}

	return 0;
}