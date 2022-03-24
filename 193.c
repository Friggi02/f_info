/*Scrivere un programma per il calcolo di statistiche sui caratteri presenti in un file di testo il cui nome è specificato come argomento da riga di comando. Il 
programma considera tutti i caratteri ad eccezione degli spazi e fornisce in uscita le seguenti statistiche:
- il numero di righe presenti nel file (ogni riga è al più di 100 caratteri)
- il numero totale di caratteri (esclusi quelli di spaziatura)
- il numero massimo di caratteri per riga
- il numero medio di caratteri per riga
- la riga più lunga presente nel file

Dato il file con il seguente testo:

Prova di contenuto di file
per avere un esempio.
Non e' importante quello che c'e' scritto
presente.		 

il programma visualizza:

numero righe: 4
numero caratteri: 84
caratteri massimi: 35
caratteri medi: 21
riga più lunga: Non e' importante quello che c'e' scritto		*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXS 100

int main(int argc, char* argv[]){

	FILE* fp;
	int n_row, n_char, caratteri_max, i, len;
	char riga[MAXS+1], riga_lunga[MAXS+1];

	if(argc==2){
		fp = fopen(argv[1], "r");
		if(fp){
			n_row = 0;
			n_char = 0;
			caratteri_max = 0;
			fgets(riga, MAXS+1, fp);
			while(!feof(fp)){
				n_row++;
				for(i=0, len=0; riga[i]!='\0'; i++){
					if(riga[i]!=' ' && riga[i]!='\r' && riga[i]!='\n'){
						n_char++;
						len++;
					}
				}
				if(len>caratteri_max){
					caratteri_max = len;
					strcpy(riga_lunga, riga);
				}
				fgets(riga, MAXS+1, fp);
			}
			if(n_row==0){
				printf("file vuoto\n");
			}else{
				printf("numero righe: %d\nnumero caratteri: %d\ncaratteri massimi: %d\ncaratteri medi: %d\nriga più lunga: %s\n", n_row, n_char, caratteri_max, n_char/n_row, riga_lunga);
			}
			fclose(fp);
		}else{
			printf("errore aperturna file\n");
		}
	}else{
		printf("errore argomenti\n");
	}
	
	return 0;
}
