/*Scrivere un programma in C che chiede all'utente due numeri in virgola mobile che rappresentano i parametri a e b di un'equazione 
di primo grado ax+b=0. Il programma calcola e visualizza la soluzione dell'equazione.
Si ricordi che l'equazione può essere impossibile o indeterminata.*/

#include <stdio.h>

int main(){

	float a, b, risultato;

	printf("inserire i due numeri: ");
	scanf("%f %f", &a, &b);

	if(a!=0){
		risultato = -b/a;
		printf("%f\n", risultato);
	}else{
		if(b==0){
			printf("indeterminata\n");
		}else{
			printf("impossibile\n");
		}
	}

	return 0;
}