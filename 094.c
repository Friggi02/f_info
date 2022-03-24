/*Scrivere un programma in C che chiede un numero intero positivo e nel caso in cui l'utente inserisca un numero non valido lo 
richiede. Il programma visualizza in formato "abaco" il numero dalla cifra più significativa alla meno significativa.
Ad esempio se viene inserito il numero 2134, il programma stamperà a video:
|**
|*
|***
|****													*/

#include <stdio.h>
#define BASE 10

int main(){

	int num, cifra, pot;

	do{
		scanf("%d", &num);
	}while(num<=0);

	pot=10;
	
	while (num/pot){
		pot *=10;
	}
	
	pot/=10;
	
	while (num>0) {
		printf("|");
		cifra=num/pot;
		num-=(cifra*pot);
		pot/=10;
		for(; cifra>0; cifra--){
			printf("*");
		}	
		printf("\n");
	}
	
	return 0;
}