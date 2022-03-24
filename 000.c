/*Scrivere un programma in C che chiede all'utente un valore in virgola mobile che rappresenta il raggio di un cerchio.
Il programma calcola e visualizza l'area ed il perimetro di tale cerchio.*/

#include <stdio.h>
#define PI 3.14

int main(){

	float r, a, p;

	printf("inserire raggio: ");
	scanf("%f", &r);
	
	a=r*r*PI;
	p=r*2*PI;
	
	printf("area: %f\n", a);
	printf("perimetro: %f\n", p);
	
	return 0;
}