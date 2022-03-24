/*Scrivere un programma che apre in lettura un file "ciao.txt". Il 
programma legge la sequenza di caratteri salvati nel file (la cui 
lunghezza non è nota a priori) e la visualizza.*/

#include <stdio.h>

#define FN "output.txt"

int main(){

	FILE *fp;
	char c;

	fp = fopen(FN, "r");

	if(fp){
		fscanf(fp, "%c", &c);
		while(!feof(fp)){
			printf("%c", c);
			fscanf(fp, "%c", &c);
		}
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
	}

	return 0;
}