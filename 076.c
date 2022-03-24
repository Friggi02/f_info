/*Scrivere un programma in C che chiede all'utente una stringa di al massimo 15 caratteri contenente
soltanto lettere dell'alfabeto minuscolo (si assuma che l'utente non commetta errori nell'inserimento).
Il programma identifica e visualizza qual è la prima lettera nell'ordinamento
alfabetico che compare nella stringa e quante volte vi compare.

Esempio
Se l'utente inserisce "cocci" il programma stampa "c 3"
Se l'utente inserisce "bacco" il programma stampa "a 1"
Se l'utente inserisce "tiene" il programma stampa "e 2"     */

#include <stdio.h>
#define MAXS 15

int main(){
	
	char str[MAXS+1], carattere;
	int i, occ;

/*ACQUISIZIONE*/
	scanf("%s", str);

/*ELABORAZIONE*/
	for(i=1, occ=1, carattere=str[0]; str[i]!='\0'; i++){
		if(str[i]==carattere){
			occ++;
		}else if(str[i]<carattere){
			carattere=str[i];
			occ = 1;
		}
	}

/*VISUALIZZAZIONE*/
	printf("%c %d\n", carattere, occ);
	
	return 0;
}