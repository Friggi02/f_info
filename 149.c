/*
Modificare il programma sul percorso in uno spazio bidimensionale proposto durante la lezione del 2021-10-29 (ed esteso durante il 
laboratorio del 2021-10-29) aggiungendo le seguenti funzionalità (ciascuna implementata tramite un sottoprogramma):

9 - Salvare percorso su file di testo. Il nome del file (al massimo 30 caratteri) è chiesto all'utente.
10- Caricare percorso da file di testo. Il nome del file (al massimo 30 caratteri) è chiesto all'utente. Per semplicità si assuma che il file non contenga più di 50 punti.
11- Salvare percorso su file binario. Il nome del file (al massimo 30 caratteri) è chiesto all'utente.
12- Caricare percorso da file di binario. Il nome del file (al massimo 30 caratteri) è chiesto all'utente.

Segnalare eventuali errori di apertura del file. Infine modificare opportunamente il programma per gestire le nuove opzioni del menù */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXS 30
#define MAXA 50

/*DEFINISCO I NUMERI DI TUTTE LE OPZIONI*/
#define INSERISCI 1
#define AGGIUNGI 2
#define CANCELLA 3
#define VISUALIZZA 4
#define LUNGHEZZA 5
#define COPPIAMAX 6
#define CERCA 7
#define CORNICE 8
#define SALVA_TESTO 9
#define CARICA_TESTO 10
#define SALVA_BINARIO 11
#define CARICA_BINARIO 12
#define USCITA 13

/*DEFINISCO UNA VARIABILE CHE DESCRIVE IL PUNTO*/
typedef struct{
	int x, y;
	char nome[MAXS+1];
}localita_t;

/*DEFINISCO UNA VARIABILE CON L'ARRAY LOCALITA E LA SUA DIMENSIONE EFFETTIVA*/
typedef struct{
	localita_t loc[MAXA];
	int dim;
}percorso_t;

/*DICHIARO TUTTE LE FUNZIONI*/
void menu();
void inserisci(percorso_t[]);
void aggiungi(percorso_t[]);
void cancella(percorso_t[]);
void visualizza(percorso_t[]);
void lunghezza(percorso_t[]);
void coppiamax(percorso_t[]);
void cerca(percorso_t[]);
void cornice(percorso_t[]);
void salva_testo(percorso_t[]);
void carica_testo(percorso_t[]);
void salva_binario(percorso_t[]);
void carica_binario(percorso_t[]);

int main(){

	percorso_t l;
	int scelta;
	l.dim = 0;

	do{
		menu();
		printf("\nopzione selezionata: ");
		scanf(" %d", &scelta);
		switch(scelta){
			case 1:
				inserisci(&l);
				break;
			case 2:
				aggiungi(&l);
				break;
			case 3:
				cancella(&l);
				break;
			case 4:
				visualizza(&l);
				break;
			case 5:
				lunghezza(&l);
				break;
			case 6:
				coppiamax(&l);
				break;
			case 7:
				cerca(&l);
				break;
			case 8:
				cornice(&l);
				break;
			case 9:
				salva_testo(&l);
				break;
			case 10:
				carica_testo(&l);
				break;
			case 11:
				salva_binario(&l);
				break;
			case 12:
				carica_binario(&l);
				break;
			case 13:
				break;
			default:
				printf("comando errato\n");
		}
	}while(scelta!=USCITA);

	return 0;
}

void menu(){
	printf("\n***MENU***\n");
	printf("%d. Inserire in coda una nuova localita\n", INSERISCI);
	printf("%d. Inserire in una specificata posizione una nuova localita\n", AGGIUNGI);
	printf("%d. Cancellare una localita nella lista\n", CANCELLA);
	printf("%d. Visualizzare intero percorso\n", VISUALIZZA);
	printf("%d. Visualizzare la lunghezza complessiva itinerario\n", LUNGHEZZA);
	printf("%d. Visualizza la coppia di localita, anche non consecutive nel percorso, la cui distanza è maggiore\n", COPPIAMAX);
	printf("%d. Cerca localita\n", CERCA);
	printf("%d. Calcola cornice punta-coda\n", CORNICE);
	printf("%d. Salva percorso in formato di testo\n", SALVA_TESTO);
	printf("%d. Carica percorso da file di testo\n", CARICA_TESTO);
	printf("%d. Salva percorso in formato binario\n", SALVA_BINARIO);
	printf("%d. Carica percorso da file binario\n", CARICA_BINARIO);
	printf("%d. Uscita\n", USCITA);
}

void inserisci(percorso_t l[]){
	if(l->dim<MAXA){
		printf("inserisci i dati: ");
		scanf("%d %d %s", &l->loc[l->dim].x, &l->loc[l->dim].y, l->loc[l->dim].nome);
		l->dim++;
	}
}

void aggiungi(percorso_t l[]){
	int i, j;
	if(l->dim<MAXA){
		printf("inserisci indice: ");
		scanf("%d", &i);
		if(i>=0 && i<l->dim){
			for(j=l->dim-1; j>=i; j--){
				l->loc[j+1] = l->loc[j];
			}
			printf("inserisci i dati: ");
			scanf("%d %d %s", &l->loc[i].x, &l->loc[i].y, l->loc[i].nome);
			l->dim++;
		}else{
			printf("indice errato\n");
		}
	}else{
		printf("memoria piena\n");
	}
}

void cancella(percorso_t l[]){
	int i;
	printf("inserisci indice: ");
	scanf("%d", &i);
	if(i>=0 && i<l->dim){
		for(; i<l->dim; i++){
			l->loc[i] = l->loc[i+1];
		}
		l->dim--;
	}else{
		printf("indice errato\n");
	}
}

void visualizza(percorso_t l[]){
	int i;
	printf("percorso:\n");
	for(i=0; i<l->dim; i++){
		printf("%d. %d %d %s\n", i, l->loc[i].x, l->loc[i].y, l->loc[i].nome);
	}
}

void lunghezza(percorso_t l[]){
	int i, quadrato;
	float lunghezza;
	for(i=0, lunghezza=0; i<l->dim-1; i++){
		quadrato = (l->loc[i].x-l->loc[i+1].x)*(l->loc[i].x-l->loc[i+1].x)+(l->loc[i].y-l->loc[i+1].y)*(l->loc[i].y-l->loc[i+1].y);
		lunghezza += sqrt(quadrato);
	}
	printf("lunghezza: %f\n", lunghezza);
}

void coppiamax(percorso_t l[]){
	localita_t coppia_a, coppia_b;
	int i, quadrato;
	float max, appoggio;
	for(i=0, max=0; i<l->dim-1; i++){
		quadrato = (l->loc[i].x-l->loc[i+1].x)*(l->loc[i].x-l->loc[i+1].x)+(l->loc[i].y-l->loc[i+1].y)*(l->loc[i].y-l->loc[i+1].y);
		appoggio = sqrt(quadrato);
		if(max<appoggio){
			max = appoggio;
			coppia_a = l->loc[i];
			coppia_b = l->loc[i+1];
		}
	}
	printf("il tratto piu lungo e di %f:\n%d %d %s\n%d %d %s", max, coppia_a.x, coppia_a.y, coppia_a.nome, coppia_b.x, coppia_b.y, coppia_b.nome);
}

void cerca(percorso_t l[]){
	int i;
	char str[MAXS+1];
	printf("localita da cercare: ");
	scanf("%s", str);
	for(i=0; i<l->dim; i++){
		if(!strcmp(str, l->loc[i].nome)){
			printf("%d. %d %d %s\n", i, l->loc[i].x, l->loc[i].y, l->loc[i].nome);
		}
	}
}

void cornice(percorso_t l[]){
	int i, x_min, x_max, y_min, y_max;
	if(l->dim==0){
		printf("percorso vuoto\n");
	}else{
		x_min = l->loc[0].x;
		y_min = l->loc[0].y;
		x_max = l->loc[0].x;
		y_max = l->loc[0].y;
		for(i=0; i<l->dim; i++){
			if(l->loc[i].x<x_min){
				x_min = l->loc[i].x;
			}
			if(l->loc[i].x>x_max){
				x_max = l->loc[i].x;
			}
			if(l->loc[i].y<y_min){
				y_min = l->loc[i].y;
			}
			if(l->loc[i].y>y_max){
				y_max = l->loc[i].y;
			}
		}
		printf("estremo inferiore sinistro: %d %d\n", x_min, y_min);
		printf("estremo superiore destro: %d %d\n", x_max, y_max);
	}
}

void salva_testo(percorso_t l[]){
	
	FILE *fp;
	int i;
	char filename[MAXS+1];

	printf("nome del file: ");
	scanf("%s", filename);

	fp = fopen(filename, "w");

	if(fp){
		for(i=0; i<l->dim; i++){
			fprintf(fp, "%d %d %s\n", l->loc[i].x, l->loc[i].y, l->loc[i].nome);
		}
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
	}
}

void carica_testo(percorso_t l[]){
	
	FILE *fp;
	int i;
	char filename[MAXS+1];

	printf("nome del file: ");
	scanf("%s", filename);

	fp = fopen(filename, "r");

	if(fp){
		l->dim = 0;
		fscanf(fp, "%d %d %s\n", &l->loc[l->dim].x, &l->loc[l->dim].y, l->loc[l->dim].nome);
		while(!feof(fp)){
			l->dim++;
			fscanf(fp, "%d %d %s", &l->loc[l->dim].x, &l->loc[l->dim].y, l->loc[l->dim].nome);
		}
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
	}
}

void salva_binario(percorso_t l[]){
	
	FILE *fp;
	char filename[MAXS+1];

	printf("nome del file: ");
	scanf("%s", filename);

	fp = fopen(filename, "wb");

	if(fp){
		fwrite(l, sizeof(percorso_t), 1, fp);
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
	}
}

void carica_binario(percorso_t l[]){
	
	FILE *fp;
	char filename[MAXS+1];

	printf("nome del file: ");
	scanf("%s", filename);

	fp = fopen(filename, "rb");

	if(fp){
		fread(l, sizeof(percorso_t), 1, fp);
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
	}
}
