/*Scrivere un programma in C che chieda all'utente di inserire da tastiera due angoli in formato gradi, primi e secondi (valori interi 
positivi o nulli - si assuma che l'utente non inserisca valori negativi). Il programma deve normalizzare gli angoli inseriti, farne 
la somma e stampare a video i due angoli inseriti (in formato normale) e la loro somma, anch'essa normalizzata*/

#include <stdio.h>

int main(){

	int gradi1, primi1, secondi1, gradi2, primi2, secondi2;
	float angolo1, angolo2, somma;

	printf("interire angolo 1: ");
	scanf("%d %d %d", &gradi1, &primi1, &secondi1);
	printf("interire angolo 2: ");
	scanf("%d %d %d", &gradi2, &primi2, &secondi2);
	printf("\n");

	angolo1 = gradi1+(primi1*0.01)+(secondi1*0.0001);
	angolo2 = gradi2+(primi2*0.01)+(secondi2*0.0001);

	somma = angolo1+angolo2;

	printf("angolo 1 = %f\n", angolo1);
	printf("angolo 2 = %f\n", angolo2);
	printf("somma = %f\n", somma);

	return 0;
}