/*Scrivere un programma che apre un file di testo il cui nome di al massimo 30 caratteri va chiesto all'utente e che contiene una 
sequenza di lunghezza indefinita (0 o più) di numeri interi. Per ciascun numero letto, il programma stabilisce se è il doppio del 
suo precedente; in tal caso stampa a video la coppia di numeri.

Esempio: se il contenuto del file è "1 2 5 2 4 8 5 4 5", il programma stampa a video:
1 2
2 4
4 8		*/

#include <stdio.h>
#define MAXS 30

int main (){

	char filename[MAXS];
	FILE *fp;
	int a, b;

	printf("nome file: ");
	scanf("%s", filename);

	fp = fopen(filename, "r");
	if(fp){
		fscanf(fp, "%d %d", &a, &b);
		while(!feof(fp)){
			if(b==2*a){
				printf("%d %d\n", a, b);
			}
			a = b;
			fscanf(fp, "%d", &b);
		}
		fclose(fp);
	}else{
		printf("errore nell'apertura del file\n");
	}

	return 0;
}