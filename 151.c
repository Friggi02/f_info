/*Scrivere un programma che apre un file di testo il cui nome è TEST.txt contenente un sequenza di lunghezza indefinita (0 o più) di 
numeri interi. Il programma calcola e stampa a video il valore massimo e quante volte tale valore si è presentato nel file.*/

#include <stdio.h>
#define FILENAME "output.txt"

int main (){

	int conto, max, n;
	FILE *fp;

	fp = fopen(FILENAME, "r");
	if(fp){
		fscanf(fp, "%d", &n);
		if(!feof(fp)){
			max = n;
			conto = 1;
			fscanf(fp, "%d", &n);
			while(!feof(fp)){	
				if(n>max){
					max = n;
					conto = 1;
				}else if(n==max){
					conto++;
				}
				fscanf(fp, "%d", &n);
			}
			fclose(fp);
		}
		printf("valore massimo: %d\noccorrenze: %d\n", max, conto);
	}else{
		printf("errore nell'apertura del file\n");
	}
	
	return 0;
}