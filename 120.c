/*
Definire le strutture dati per rappresentare un concessionario di automobili.

Il concessionario è descritto in termini di un codice numerico, i dati di un gestore ed una lista di massimo 50 automobili.

Il gestore è a sua volta descritto in termini di una partita IVA, un nome ed un cognome, tre stringhe di al massimo 30 caratteri ciascuna.

L'automobile infine è descritta in termini di un modello (una stringa di al massimo 30 caratteri), una targa (una stringa di al massimo 7 caratteri) e mese ed anno di immatricolazione (due interi).

Realizzare un sottoprogramma che riceve come parametro un array di tipo concessionario, un intero aa che rappresenta un anno, e 
qualsiasi altro parametro ritenuto strettamente necessario. Per ogni concessionario il sottoprogramma stampa a video modello, targa e 
mese (in numero) delle auto immatricolate nell'anno AA. Il report mostrato dovrà avere il seguente formato:

Conc. 0, codice 12345: gestore Paolo Rossi
Immatricolazioni 2015:
* mese 9: Punto, MI80980
* mese 6: Marea, TO12567

Conc. 1, codice 23456: gestore Luca Bianchi
Immatricolazioni 2015:
* mese 2: Panda, VE85980

Conc. 2, codice 23556: gestore Franco Verdi
Immatricolazioni 2015:
NESSUNA

Scrivere un programma che chiede all'utente i dati di 10 concessionari ed invoca la funzione sopra definita per stampare la reportistica*/

#include <stdio.h>
#define DIMSTR30 30
#define DIMTARGA 7
#define MAXAUTO 50
#define NUM_CONC 10

typedef struct{

	char nome[DIMSTR30+1], cognome[DIMSTR30+1], piva[DIMSTR30+1];
}gestore_t;

typedef struct{

	char modello[DIMSTR30+1], targa[DIMTARGA+1];
	int meseImm, annoImm;
}automobile_t;

typedef struct{

	int id;
	gestore_t gestore;
	automobile_t autom[MAXAUTO];
	int nAuto;
}concessionario_t;

void stampa_report(concessionario_t[], int, int);

int main(){
	
	concessionario_t c[NUM_CONC];
	int anno, i, j;

	for(i=0; i<NUM_CONC; i++){
		printf("\n*** CONCESSIONARIO %d ***\n", i);
		printf("codice numerico: ");
		scanf("%d", &c[i].id);
		printf("nome gestore: ");
		scanf("%s", c[i].gestore.nome);
		printf("cognome gestore: ");
		scanf("%s", c[i].gestore.cognome);
		printf("partita IVA gestore: ");
		scanf("%s", c[i].gestore.piva);
		printf("numero di auto: ");
		scanf("%d", &c[i].nAuto);
		for(j=0; j<c[i].nAuto; j++){
			printf("-AUTO %d\n", j);
			printf("	modello: ");
			scanf("%s", c[i].autom[j].modello);
			printf("	targa: ");
			scanf("%s", c[i].autom[j].targa);
			printf("	mese immatricolazione: ");
			scanf("%d", &c[i].autom[j].meseImm);
			printf("	anno immatricolazione: ");
			scanf("%d", &c[i].autom[j].annoImm);
		}
	}

	printf("\nanno di intersse: ");
	scanf("%d", &anno);

	stampa_report(c, NUM_CONC, anno);


	return 0;
}

void stampa_report(concessionario_t c[], int dim, int aa){

	int i, j, trovato;

	for(i=0; i<dim; i++){
		printf("\nConc. %d, codice %d: gestore %s %s\nImmatricolazioni %d:\n", i, c[i].id, c[i].gestore.nome, c[i].gestore.cognome, aa);
		for(j=0, trovato=0; j<c[i].nAuto; j++){
			if(c[i].autom[j].annoImm==aa){
				printf("* mese %d: %s, %s\n", c[i].autom[j].meseImm, c[i].autom[j].modello, c[i].autom[j].targa);
				trovato=1;
			}
		}
	}
	if(!trovato){
		printf("NESSUNA\n");
	}
}