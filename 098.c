/*Scrivere un sottoprogramma che calcola l'area e il perimetro di un cerchio di un dato raggio. Il sottoprogramma riceve come parametri 
un numero in virgola mobile che rappresenta il raggio del cerchio e altri due parametri, sempre in virgola mobile, in cui verranno 
salvati i due risultati richiesti. Scrivere un programma che chiede all'utente la lunghezza del raggio 
del cerchio, calcola mediante la funzione sopra e visualizza il perimetro e l'area del cerchio. In seguito il programma chiede 
all'utente se vuoi continuare o meno (0 per continuare, qualsiasi altro valore per terminare).*/

#include <stdio.h>
#define PI 3.14

void area_perimetro(float, float*, float*);

int main(){

	float raggio, area, perimetro;
	int continua;

	do{	
		printf("raggio: ");
		scanf("%f", &raggio);
		area_perimetro(raggio, &raggio, &perimetro);
		printf("area: %f\nperimetro: %f\n", raggio, perimetro);
		printf("continuare? ");
		scanf("%d", &continua);
	}while(!continua);


	return 0;
}

void area_perimetro(float raggio, float *area, float *perimetro){

	*area = raggio*raggio*PI;
	*perimetro = 2*raggio*PI;

}
