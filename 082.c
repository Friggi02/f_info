/*Scrivere un sottoprogramma che riceve come parametri due numeri interi e restituisce la loro media (un numero float). 

Scrivere un programma che chiede all'utente due coppie di interi e calcola e visualizza la media di ciascuna di esse.*/

#include <stdio.h>

float calcola_media(int, int);

int main(){

	int num1, num2;
	float media;

	printf("prima coppia: ");
	scanf("%d %d", &num1, &num2);
	media = calcola_media(num1, num2);
	printf("media prima coppia: %f\n", media);

	printf("seconda coppia: ");
	scanf("%d %d", &num1, &num2);
	media = calcola_media(num1, num2);
	printf("media prima coppia: %f\n", media);	

	return 0;
}

float calcola_media(int a, int b){

	float m;

	m = (float)(a+b)/2;

	return m;
}