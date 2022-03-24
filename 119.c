/*Scrivere un sottoprogramma C che riceve come parametri: 
1) una stringa line 
2) una matrice di char tokens per ospitare una lista di parole ciascuna di lunghezza massima pari a 15 caratteri 
3) una variabile wMax indicante il numero di righe della matrice tokens 
4) un intero wNum passato per indirizzo. 

Assumendo che 1) line sia una frase composta da parole separate soltanto da uno spazio e non contenente spazi extra all'inizio e 
alla fine, e 2) ciascuna parola sia di al massimo 15 caratteri, il sottoprogramma salva su ciascuna riga di tokens le parole contenute 
in line. Inoltre se line contiene più di wMax parole, le parole in eccesso vengono scartate. Infine il sottoprogramma trasmette al 
chiamate tramite il parametro wNum il numero effettivo di parole memorizzate in tokens.

Scrivere un programma C che chiede all'utente una stringa di al massimo 150 caratteri ed invoca il sottoprogramma sopra definito per 
separare le parole salvandole in una matrice per contenere al massimo 12 parole da 15 caratteri ciascuna (quindi 12x16!). Il 
programma infine visualizza la lista di parole individuate.

VARIANTE: ciascuna parola in line può anche essere più lunga di 15 caratteri. In tal caso il sottoprogramma deve troncare la parola 
quando la salva in tokens (ad esattamente 15 caratteri), scartando gli eventuali caratteri in eccesso.*/

#include <stdio.h>
#define MAXWORD 15
#define MAXSTR 150
#define MAXNUMWORDS 12

void tokenizer(char[], char[][MAXWORD+1], int, int*);
int main(){

	char line[MAXSTR+1], t[MAXNUMWORDS][MAXWORD+1];
	int num_words, i;

	scanf("%[^\n]", line);

	tokenizer(line, t, MAXNUMWORDS, &num_words);

	for(i=0; i<num_words; i++){
		printf("%s\n", t[i]);
	}

	return 0;
}

void tokenizer(char line[], char tokens[][MAXWORD+1], int wMax, int *wNUM){
 	
 	int i, j;

 	for(i=0, j=0, *wNUM=0; line[i]!='\0' && *wNUM<wMax; i++){
 		if(line[i]!=' ' && j<MAXWORD){
 			tokens[*wNUM][j] = line[i];
 			j++;
 		}else{
 			tokens[*wNUM][j] = '\0';
 			j = 0;
 			(*wNUM)++;
 		}
 	}
 	if(*wNUM<wMax){
 		tokens[*wNUM][j] = '\0';
 		(*wNUM)++;
 	}
}