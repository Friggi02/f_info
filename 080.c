/*Scrivere un sottoprogramma che riceve come parametro un numero intero non negativo e calcola e restituisce il suo fattoriale.

Scrivere in seguito un sottoprogramma che riceve come parametri due numeri interi non negativi e calcola il coefficiente binomiale.

Scrivere un programma che chiede all'utente due numeri interi non negativi e utilizza il sottoprogramma
sopra definito per calcolarne il coefficiente binomiale mostrando a video il risultato.*/

#include <stdio.h>

int fattoriale(int n);
int coefficientebin(int m, int k);

int main(){

	int num1, num2, coeff;

/*ACQUISIZIONE*/
	do{
		scanf("%d %d", &num1, &num2);
	}while(num1<=0 || num2<=0);

/*ELABORAZIONE*/
	coeff = coefficientebin(num1, num2);

/*VISUALIZZAZIONE*/
	printf("%d\n", coeff);

	return 0;
}

int fattoriale(int n){

	int f;

	f = 1;
	while(n>1){
		f = f*n;
		n--;
	}

	return f;
}

int coefficientebin(int m, int k){
	
	return fattoriale(m)/(fattoriale(k)*fattoriale(m-k));
}