/*Scrivere un programma apre in lettura un file di testo il cui nome, di al massimo 30 caratteri è chiesto all'utente.
Il programma legge la sequenza di valori interi salvati nel file (la cui lunghezza non è nota a priori) e la visualizza.*/

#include <stdio.h>

#define MAXS 30

int main(){

	FILE *fp;
	char filename[MAXS+1];
	int n;

	printf("nome del file: ");
	scanf("%s", filename);

	fp = fopen(filename, "r");

	if(fp){
		fscanf(fp, "%d", &n);
		while(!feof(fp)){
			printf("%d ", n);
			fscanf(fp, "%d", &n);
		}
		printf("\n");
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
	}

	return 0;
}