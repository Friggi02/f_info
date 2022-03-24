/*Scrivere un sottoprogramma che riceve come parametri due array di caratteri, il primo contenente una stringa ed il secondo vuoto. 
Assumendo che la stringa sia composta da una sequenza di parole separate da spazi, il sottoprogramma inverte di ordine le parole 
della stringa e salva il risultato nel secondo array.

Esempio: Se il programma riceve come stringa "ciao come stai", il sottoprogramma restituisce "stai come ciao".

Scrivere un programma che acquisisce una stringa di al massimo 100 caratteri contenente anche spazi,
invoca il sottoprogramma sopra definito e visualizza il risultato.*/

#include <stdio.h>
#define MAXS 100

void reverse(char[], char[]);

int main(){

	char in[MAXS+1], out[MAXS+1];

	scanf("%[^\n]", in);

	reverse(in, out);

	printf("%s\n", out);
	
	return 0;
}

void reverse(char in[], char out[]){
	
	int len, i, indice, inizio, fine;

    for(len=0; in[len]!='\0'; len++);
    indice = 0;
    inizio = len-1;
    fine = len-1;

    while(inizio>0)
    {
        if(in[inizio]==' ')
        {
            i = inizio+1;
            while(i<=fine)
            {
                out[indice] = in[i];
                i++;
                indice++;
            }
            out[indice++] = ' ';
            fine = inizio-1;
        }
        inizio--;
    }
    
    for(i=0; i<=fine; i++)
    {
        out[indice] = in[i];
        indice++;
    }

    out[indice] = '\0'; 
}