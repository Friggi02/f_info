/*Scrivere un sottoprogramma che esegue la divisione tra due interi positivi, restituendo mediante parametri passati per indirizzo sia 
il risultato che il resto. Scrivere un programma che chiede un numero all'utente e trova il primo divisore più grande di 1, 
visualizzandolo il divisore ed il risultato della divisione.*/

#include <stdio.h>

void divisione(int, int, int*, int*);

int main(){

	int numeratore, denominatore, quoziente, resto;

	scanf("%d", &numeratore);

	for(denominatore=2 ; resto!=0; denominatore++){
		divisione(numeratore, denominatore, &quoziente, &resto);
	}

	printf("primo divisore: %d\nquoziente: %d\n", denominatore-1, quoziente);

	return 0;
}

void divisione(int numeratore, int denominatore, int  *quoziente, int *resto){

	*quoziente = numeratore/denominatore;
	*resto = numeratore%denominatore;
}