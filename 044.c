/*Scrivere un programma in C in grado di calcolare il valore di polinomi di grado massimo 8. Il programma chiede all'utente il grado 
n del polinomio desiderato (un intero compreso tra 0 e 8 inclusi e nel caso di valore non valido lo richiede).
Successivamente, chiede all'utente i coefficienti (interi) di tutti i monomi che compongono il polinomio.
Infine, chiede all'utente il valore x (un intero) per cui fornire la soluzione del polinomio, la calcola e la stampa a video.*/

#include <stdio.h>
#define DIM 8

int main(){

	int grado_massimo, polinomio[DIM+1], prodotto, i, x, y;

	printf("immettere grado massimo: ");
	scanf("%d", &grado_massimo);
	while(grado_massimo<0 || grado_massimo>DIM){
		printf("errore\n");
		scanf("%d", &grado_massimo);
	}

	for(i=0; i<=grado_massimo; i++){
		printf("coefficiente per incognita grado %d: ", i);
		scanf("%d", &polinomio[i]);
	}

	printf("valore di x: ");
	scanf("%d", &x);

	for(i=0, y=0, prodotto=1; i<=grado_massimo; i++){
		y += polinomio[i]*prodotto;
		prodotto *= x;
	}

	printf("y=%d\n", y);

	return 0;
}