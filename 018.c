/*Si consideri un corso X in cui l'esame è composto da due compitini, ciascuno valutato in trentesimi. Condizione necessaria per essere 
promossi è che entrambi i compitini siano sufficienti e in tal caso il voto finale è calcolato come media dei due valori. Si noti che il 
voto finale è un intero e quindi l'eventuale parte decimale non va considerata.

Scrivere un programma in C che acquisisce due valori interi che rappresentano i punteggi ottenuti da uno studente nelle due prove in 
itinere; si assuma in prima istanza che l'utente inserisca correttamente dei valori compresi tra 0 e 30.
Il programma valuta se lo studente è stato promosso o bocciato visualizzando un apposito messaggio; in caso positivo il programma 
deve anche visualizzare il voto ottenuto. Migliorare poi il programma aggiungendo un controllo di validità dei 
dati inseriti, cioè che ciascun punteggio deve essere compreso tra 0 e 30; nel caso almeno uno dei dati sia non consistente,
il programma deve visualizzare un messaggio di errore.*/

#include <stdio.h>

int main(){

		float a, b;
		int media;

		printf("inserire i due voti: ");
		scanf("%f %f", &a, &b);

		if(a>=0 && a<=30 && b>=0 && b<=30){
			if(a>=18 && b>=18){
				media = (a+b)/2;
				printf("promosso con media %d\n",media);
			}else{
				printf("bocciato\n");
			}
		}else{
			printf("errore\n");
		}

	return 0;
}