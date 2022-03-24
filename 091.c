/*Scrivere un programma in C che chiede un numero intero positivo e nel caso in cui l'utente inserisca un numero non valido lo 
richiede. Il programma visualizza in formato "abaco" il numero dalla cifra meno significativa alla più significativa.
Ad esempio se viene inserito il numero 2134, il programma stamperà a video:
|****
|***
|*
|**													*/


#include <stdio.h>
#define BASE 10

int main(){

	int n, cifra;

	do{
		scanf("%d", &n);
	}while(n<=0);

	while(n>0){
		cifra = n%BASE;
		n = n/BASE;
		while(cifra>0){
			printf("*");
			cifra--;
		}
		printf("\n");
	}
	
	return 0;
}