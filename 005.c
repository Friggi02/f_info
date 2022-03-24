/*Scrivere un programma in C che chiede all'utente un carattere dell'alfabeto minuscolo (assumiamo che l'utente non inserisca un 
carattere non valido). Il programma calcola e visualizza il corrispondente carattere maiuscolo.*/

#include <stdio.h>

int main(){

	char maiuscolo, minuscolo;

	printf("inserire carattere: ");
	scanf("%c", &minuscolo);
	
	maiuscolo = minuscolo-'a'+'A';   /*so che una qualsiasi lettera minuscola è equidistante alla sua maiuscola*/
	
	printf("%c\n", maiuscolo);

	return 0;
}