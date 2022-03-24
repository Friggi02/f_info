/*Scrivere un programma in C che chiede all'utente una numero in virgola mobile. Il programma calcola e visualizza su due righe 
separate la parte intera e quella decimale di tale numero.

Per esempio nel caso in cui l'utente inserisce il numero 4.14, il programma visualizzerà:
4
0.14		*/

#include <stdio.h>

int main(){

	float n, decimale;
	int intera;

	printf("inserire numero: ");
	scanf("%f", &n);

	intera = n;						/*perdo la parte decimale*/
	decimale = n-intera;

	printf("%d\n%f\n", intera, decimale);

	return 0;
}