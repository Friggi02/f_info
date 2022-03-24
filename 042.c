/*Scrivere un programma in C che chiede all'utente un numero intero positivo minore di 1024 e se il valore non è valido stampa un 
messaggio di errore e lo richiede. Il programma converte in binario naturale su 10 bit il valore acquisito mediante il metodo dei resti 
e visualizza il risultato.*/

#include <stdio.h>
#define DIM 10

int main(){

	int n, bin[DIM], i;

	scanf("%d", &n);

	while(n<0 || n>1024){
		printf("errore\n");
		scanf("%d", &n);
	}

	for(i=0; i<DIM; i++){
		bin[i] = 0;
	}

	for(i=1; i<DIM; i++){
		n = n/2;
		bin[i] = n%2;
	}

	for(i=DIM-1; i>=0; i--){
		printf("%d",bin[i]);
	}

	printf("\n");

	return 0;
}