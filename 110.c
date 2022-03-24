/*
Definire un tipo di dato strutturato per rappresentare una frazione in termini di numeratore e denominatore (due numeri interi).

Scrivere un sottoprogramma che riceve come parametro passato per indirizzo una frazione e la visualizza sullo schermo.

Scrivere un sottoprogramma che riceve come parametro passato per indirizzo una variabile frazione, chiede all'utente numeratore e 
denominatore (verificando la correttezza di quest'ultimo e nel caso richiedendone il valore) e salva i due valori nella variabile 
ricevuta come parametro.

Scrivere un sottoprogramma che riceve come parametro passato per indirizzo una frazione e la semplifica.

Scrivere un programma che chiede mediante i sottoprogrammi sopra definiti chiede all'utente una frazione, la semplifica e mostra il 
risultato a video.*/



#include <stdio.h>

typedef struct 
{
	int numeratore, denominatore;
} frazione_t;

void visualizza(frazione_t*);
void acquisisci(frazione_t*);
void semplifica(frazione_t*);

int main(){

	frazione_t f;
	acquisisci(&f);
	semplifica(&f);
	visualizza(&f);
	
	return 0;
}

void visualizza(frazione_t *frazione){

	/*printf("%d/%d\n", (*frazione).numeratore, (*frazione).denominatore);*/
	printf("%d/%d\n", frazione->numeratore, frazione->denominatore);
}

void acquisisci(frazione_t *frazione){

	do{
	printf("inserisci frazione: ");
	scanf("%d %d",  &frazione->numeratore, &frazione->denominatore);
	}while(frazione->denominatore==0);
}

void semplifica(frazione_t *frazione){

	int meno, mcd;

 /*CONTROLLO IL SEGNO DEL NUMERATORE*/
	if(frazione->numeratore<0){
		meno = 1;
		frazione->numeratore = -frazione->numeratore;
	}else{
		meno = 0;
	}

 /*CONTROLLO IL SEGNO DEL DENOMINATORE*/
	if(frazione->denominatore<0){
		meno = !meno;
		frazione->denominatore = -frazione->denominatore;
	}

 /*CALCOLO MCD*/
	if(frazione->numeratore<frazione->denominatore){
		mcd = frazione->numeratore;
	}else{
		mcd = frazione->denominatore;
	}
	while(frazione->numeratore%mcd || frazione->denominatore%mcd){
		mcd--;			
	}

 /*ESEGUO LE DIVISIONI*/
	frazione->numeratore /= mcd;
	frazione->denominatore /= mcd;

 /*RIMETTO IL SEGNO*/
	if(meno){
		frazione->numeratore = -frazione->numeratore;
	}
}