/*Scrivere un programma in C che chiede all'utente un valore intero e lo stampa a video.
Si utilizzino i sottoprogrammi fprintf e fscanf sugli stream stdin e stdout.*/

#include <stdio.h>

int main(){

	int n;

	fscanf(stdin, "%d", &n);
	fprintf(stdout, "%d\n", n);
	
	return 0;
}