/*
Realizzare un sottoprogramma che riceve come parametro una stringa di testo composta da parole in caratteri minuscoli ciascuna 
di lunghezza indefinita e separate da singoli spazi. Il sottoprogramma modifica la stringa secondo la procedura qui sotto 
riportata e poi ne stampa all'utente la nuova versione.

Procedura: ogni parola all'interno della stringa di testo viene invertita, l'ultima lettera diventa la prima e viceversa.

Esempio
Input: ciao come stai
Output: oaic emoc iats

Scrivere un programma che chiede all'utente una stringa di al massimo 250 caratteri,
invoca su di essa il sottoprogramma sopra definito e stampa a video il risultato.*/

#include <stdio.h>

#define MAXS 250

void invertiparola(char[]);

int main(){

	char str[MAXS+1];

	scanf("%[^\n]", str);

	invertiparola(str);

	printf("%s\n", str);
	
	return 0;
}

void invertiparola(char str[]){

	int len, i, indice, inizio, fine;
	char appoggio[MAXS];

/*INVERTO LA STRINGA INTERA SU UNA STRINGA DI APPOGGIO*/
	for(len=0; str[len]!='\0'; len++);
	for(i=0; str[i]!='\0'; i++){
		appoggio[len-i-1] = str[i];
	}
	appoggio[len] = '\0';

/*INVERTO L'ORDINE DELLE PAROLE DELLA STRINGA DI APPOGGIO DIRETTAMENTE SULLA STRINGA INIZIALE*/
	indice = 0;
    inizio = len-1;
    fine = len-1;

    while(inizio>0)
    {
        if(appoggio[inizio]==' ')
        {
            i = inizio+1;
            while(i<=fine)
            {
                str[indice] = appoggio[i];
                i++;
                indice++;
            }
            str[indice++] = ' ';
            fine = inizio-1;
        }
        inizio--;
    }
    
    for(i=0; i<=fine; i++)
    {
        str[indice] = appoggio[i];
        indice++;
    }

    str[indice] = '\0';
}