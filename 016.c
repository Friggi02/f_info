/*Scrivere un programma in C che realizza le funzionalità base di una calcolatrice.
Il programma chiede all'utente due numeri in virgola mobile ed un carattere che rappresenta l'operazione che si vuole eseguire (+ - * /).
Il programma esegue l'operazione richiesta e visualizza il risultato.
Nel caso l'utente inserisce un carattere che non rappresenta alcuna operazione ammissibile, il programma visualizza un messaggio di errore.*/

#include <stdio.h>

int main(){

	float a, b, risultato;
	char operazione, errore;

	scanf("%f %c %f", &a, &operazione, &b);

	errore = 0;

	if(operazione=='+'){
		risultato = a+b;
	}else if(operazione=='-'){
		risultato = a-b;
	}else if(operazione=='*'){
		risultato = a*b;
	}else if(operazione=='/'){
		risultato = a/b;
	}else{
		errore = 1;
	}

	if(errore==0){
		printf("%f\n", risultato);
	}else{
		printf("errore\n");
	}

	return 0;
}