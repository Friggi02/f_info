/*Scrivere un programma apre in lettura un file binario "ciao.bin" che contiene 10 valori interi. Il programma legge i valori e 
verifica che siano stati letti tutti correttamente. In caso affermativo li visualizza altrimenti segnala l'errore.*/

#include <stdio.h>
#define FN "input.bin"
#define DIM 10

int main(){
	
	FILE *fp;

	int a[DIM], i, quanti;

	fp = fopen(FN, "rb");
	if(fp){
		quanti = fread(a, sizeof(int), DIM, fp);
		if(quanti==DIM){
			for(i=0; i<DIM; i++){
				printf("%d\n", a[i]);
			}
		}else{
			printf("errore\n");
		}
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
	}

	return 0;
}