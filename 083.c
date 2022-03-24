/*Scrivere un sottoprogramma che riceve in ingresso un valore intero e ne restituisce il valore assoluto.

Scrivere un sottoprogramma che riceve in ingresso due numeri interi e ne restituisce il minore.

Scrivere un programma che chiede all'utente due valori interi; il programma calcola e visualizza
il minore tra i valori assoluti dei due numeri mediante i sottoprogrammi sopra definiti.*/

#include <stdio.h>

int modulo(int);
int minore(int, int);

int main(){

	int num1, num2, risultato;

	scanf("%d %d", &num1, &num2);

	risultato = minore(modulo(num1), modulo(num2));

	printf("%d\n", risultato);

	return 0;
}

int modulo(int n){

	int num;

	if(n>=0){
		num = n;
	}else{
		num = -n;
	}

	return num;
}

int minore(int a, int b){
	int m;

	if(a<b){
		m = a;
	}else{
		m = b;
	}

	return m;
}