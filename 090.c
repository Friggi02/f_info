/*Scrivere un programma in C che acquisisce una stringa s1 di massimo 50 caratteri e un numero intero n. Il programma controlla se 
n è maggiore di zero e minore della lunghezza della stringa. Se le condizioni non sono verificate, continua a richiedere il valore.
In seguito il programma crea una nuova stringa s2 che contiene la rotazione verso destra di s1 di n posizioni e la visualizza.

Esempio: s1="alfabeto" e n=2 -> s2="toalfabe".*/

#include <stdio.h>
#define MAXS 50

int main(){

	char s1[MAXS+1], s2[MAXS+1];
	int n, len, i;

/*ACQUISISCO STRINGA*/
	scanf("%s", s1);

/*CALCOLO LUNGHEZZA STRINGA*/
	for(len=0; s1[len]!='\0'; len++);

/*ACQUISIZIONE E CONTROLLO*/
	do{
		scanf("%d", &n);
	}while(n<0 || n>len);

/*COPIO LA PARTE FINALE ALL'INIZIO*/
	for(i=0; i<n; i++){
		s2[i] = s1[i+len-n];
	}

/*COPIO LA PARTE INIZIALE ALLA FINE*/	
	for(i=0; i<len; i++){
		s2[i+n] = s1[i];
	}

/*CHIUDO LA STRINGA*/
	s2[i] = '\0';

/*VISUALIZZAZIONE*/
	printf("%s\n", s2);

	return 0;
}