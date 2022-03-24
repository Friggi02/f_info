/*
Si considerino le seguenti strutture dati che rappresentano delle scatole da spedire. Si noti che una scatola può contenere un numero 
variabile di oggetti e per ogni oggetto si specifica il peso per unità ed il numero di unità contenute nella scatola.

Realizzare un sottoprogramma che riceve come parametri un array di scatole sc, un valore in virgola mobile che rappresenta un peso, 
e qualsiasi altro parametro ritenuto strettamente necessario. Analizzando le scatole nell'ordine in cui si trovano nell'array, il 
sottoprogramma valuta e restituisce il numero di scatole che può essere immagazzinato in un container avente una capienza pari al 
peso ricevuto come ultimo parametro.

Scrivere un programma che chiede all'utente i dati contenuti in dieci scatole; per ciascuna scatola il programma chiede prima quanti 
oggetti sono contenuti e poi i dati di ciascun oggetto. In seguito il programma invoca il sottoprogramma sopra definito specificando il 
valore 100.0 come capienza del container e visualizza il risultato a video.
*/

#include<stdio.h>

#define N_OGGETTI 100
#define MAX_STR 100
#define PESO_CONTAINER 100.0
#define N_SCATOLE 10

typedef struct{
	char descrizione[MAX_STR+1];
	float peso_per_unita;
	int quanti;
	int codice;
} oggetto_t;

typedef struct{
	oggetto_t oggetti[N_OGGETTI];
	int n_oggetti;
	char descrizione[MAX_STR+1];
	int codice;
} scatola_t;

int analizza(scatola_t[], int, float);

int main(){
	
	scatola_t sc[N_SCATOLE];
	int i, j, risultato;

	for(i=0; i<N_SCATOLE; i++){
		printf("\n*** SCATOLA %d ***\n", i);
		printf("codice: ");
		scanf("%d", &sc[i].codice);
		printf("descrizione: ");
		scanf("%s", sc[i].descrizione);
		printf("numero oggetti: ");
		scanf("%d", &sc[i].n_oggetti);
		for(j=0; j<sc[i].n_oggetti; j++){
			printf("-OGGETTO %d\n", j);
			printf("codice: ");
			scanf("%d", &sc[i].oggetti[j].codice);
			printf("descrizione: ");
			scanf("%s", sc[i].oggetti[j].descrizione);
			printf("peso: ");
			scanf("%f", &sc[i].oggetti[j].peso_per_unita);
			printf("numero quanti: ");
			scanf("%d", &sc[i].oggetti[j].quanti);
		}
	}

	risultato = analizza(sc, N_SCATOLE, PESO_CONTAINER);

	printf("%d\n", risultato);

	return 0;
}

int analizza(scatola_t sc[], int dim, float capienza){

	int i, j;

	for(i=0; i<dim && capienza>0; i++){
		for(j=0; j<sc[i].n_oggetti && capienza>=0; j++){
			capienza = capienza - sc[i].oggetti[j].quanti * sc[i].oggetti[j].peso_per_unita;
		}
	}
	if(capienza<0){
		i--;
	}

	return i;
}