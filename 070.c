/*Definire un tipo di dato strutturato in C per rappresentare una frazione in termini di numeratore e denominatore
(due numeri interi). Scrivere un programma in C che acquisisce due frazioni ed esegue la somma.
Il programma deve in seguito semplificare il risultato dell'operazione rappresentando l'eventuale segno meno nel numeratore.*/

#include <stdio.h>

typedef struct{
	int n, d;
}frazione_t;

int main(){

	frazione_t a, b, somma;
	int meno, mcd;

/*ACQUISISCO LE DUE FRAZIONI*/
	do{
		scanf("%d %d", &a.n, &a.d);
	}while(a.d==0);
	do{
		scanf("%d %d", &b.n, &b.d);
	}while(b.d==0);

/*CALCOLO LA SOMMA*/
	somma.d = a.d*b.d;
	somma.n = a.n*b.d+b.n*a.d;

/*GESTISCO IL SEGNO*/
	if(somma.n>=0){
		meno = 0;
	}else{
		somma.n = -somma.n;
		meno = 1;
	}
	if(somma.d<0){
		somma.d = -somma.d;
		meno = !meno;
	}

/*CALCOLO MCD*/
	if(somma.n>somma.d){
		mcd = somma.d;
	}else{
		mcd = somma.n;
	}
	while(somma.n%mcd || somma.d%mcd){
		mcd--;
	}

/*RIDUCO*/
	somma.n /= mcd;
	somma.d /= mcd;

/*RIMETTO IL SEGNO*/
	if(meno){
		somma.n = -somma.n;
	}

/*VISUALIZZAZIONE*/
	printf("%d/%d\n", somma.n, somma.d);

	return 0;
}