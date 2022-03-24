/*Scrivere un programma in C che chiede all'utente un carattere dell'alfabeto minuscolo (assumiamo che l'utente non inserisca un 
carattere non valido). Il programma calcola e visualizza il carattere successivo.Se si inserisce la z devo tornare alla a.*/

#include <stdio.h>
#define PASSO 1

int main(){

	char c_in, c_out;

	printf("inserire carattere: ");
	scanf("%c", &c_in);

	c_out = (c_in -'a'+PASSO+('z'-'a'+1))%('z'-'a'+1)+'a';
	
	printf("%c\n", c_out);

	return 0;
}