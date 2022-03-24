/*Scrivere un programma che acquisisce un intero che rappresenta un voto e stampa «grav. insuff.» se il voto è minore 10, «insuff.» se 
il voto è compreso tra 10 e 17 estremi inclusi, «suff.» se è compreso tra 18 e 24 estremi inclusi, «ottimo» se maggiore di 24.
Estendere il programma in modo tale che verifichi che il numero inserito rappresenti un voto valido (un intero tra 0 e 30 estremi 
inclusi); in caso affermativo procede con l'analisi altrimenti visualizza un messaggio di errore.*/

#include <stdio.h>

int main(){

	int n;

	printf("inserire voto: ");
	scanf("%d", &n);

	if(n>=0 && n<=30){
		if(n<10){
			printf("gravemente insuffuciente\n");
		}
		else if(n<=17){
			printf("insuffuciente\n");
		}
		else if(n<=24){
			printf("suffuciente\n");
		}
		else{
			printf("ottimo\n");	
		}
	}else{
		printf("errore\n");	
	}

	return 0;
}