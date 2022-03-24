/*Scrivere un programma che apre in scrittura un file di testo 
"ciao.txt" e vi scrive le cifre da '0' a '9'.*/

#include <stdio.h>

#define FN "output.txt"

int main(){

	FILE *fp;
	char c;

	fp = fopen(FN, "w");

	if(fp){
		for(c='0'; c<='9'; c++){
			fprintf(fp, "%c\n", c);
		}
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
	}

	return 0;
}