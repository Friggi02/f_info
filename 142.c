/*Scrivere un programma che apre in scrittura un file di testo il cui nome, di al massimo 30 caratteri, è chiesto all'utente.
In seguito, il programma chiede all'utente quanti valori interi vuole acquisire da tastiera,
e poi procede con l'acquisizione da tastiera della serie di numeri ed il loro salvataggio nel file.*/

#include <stdio.h>

#define MAXS 30

int main(){

	FILE *fp;
	char filename[MAXS+1];
	int dim, i, n;

	printf("nome del file: ");
	scanf("%s", filename);

	fp = fopen(filename, "w");

	if(fp){
		printf("numero di valori da inserire: ");
		scanf("%d", &dim);
		for(i=0; i<dim; i++){
			scanf("%d", &n);
			fprintf(fp, "%d ", n);
		}
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
	}

	return 0;
}