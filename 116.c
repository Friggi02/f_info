/*Definire un tipo di dato parola_t che rappresenta una parola nella lingua italiana e la sua traduzione inglese (due stringhe ciascuna di al 
massimo 30 caratteri).

Scrivere un programma che chiede all'utente 10 parole italiane e la loro traduzione in inglese. Il programma esegue le seguenti elaborazioni:
* Il programma cerca e stampa a video quei termini italiani che sono presenti anche nella lingua inglese (anche se con un altro significato).
* Il programma cerca e stampa a video quei termini italiani che hanno più traduzioni in inglese.

Come esempio si consideri la seguente lista di parole:
scope brooms
scopo scope
case houses
scatola case
goal goal
ciao hello
ciao hi
ballo ball
palla ball
ciao bye

Per il primo punto il programma stamperà a video:
scope brooms * scopo scope
case houses * scatola case
goal goal * goal goal

Per il secondo punto il programma stamperà a video:
ciao hello
ciao hi
ciao bye
*/

#include <stdio.h>
#include <string.h>
#define MAX_S 30
#define DIM 10

typedef struct{
	char ita[MAX_S+1], eng[MAX_S+1];
} parola_t;

int main(){
	
	parola_t d[DIM];
	int i, j, conto;

/*ACQUISIZIONE*/
	for(i=0; i<DIM; i++){
		//printf("italiano: ");
		scanf("%s", d[i].ita);
		//printf("inglese: ");
		scanf("%s", d[i].eng);
		//printf("\n");
	}

/*PRIMA ELABORAZIONE*/
	printf("\n");
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			if(!strcmp(d[i].ita, d[j].eng)){
				printf("%s %s * %s %s\n", d[i].ita, d[i].eng, d[j].ita, d[j].eng);
			}
		}
	}

/*SECONDA ELABORAZIONE*/
	printf("\n");
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			if(!strcmp(d[i].ita, d[j].ita)){
				conto++;
			}
		}
		if(conto>1){
			printf("%s %s\n", d[i].ita, d[i].eng);
		}
		conto = 0;
	}

	return 0;
}