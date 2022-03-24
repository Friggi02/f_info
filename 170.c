/*Scrivere un programma che riceve come argomenti da riga di comando il nome di un file di testo
contenente una sequenza di lunghezza indefinita di numeri interi ed un valore intero n.
Il programma legge dal file di testo i valori e stampa a video in ordine inverso solo i valori
inferiori ad n. Gestire opportunamente tutti i casi di errore. Se necessario si supponga di avere
a disposizione la struttura dati e i sottoprogrammi per la gestione delle liste dinimiche.*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.c"


int main(int argc, char *argv[]){

	int n, curr;
	FILE *fp;
	nodo_t *h = NULL;

	if(argc==3){
		n = atoi(argv[2]);
		fp = fopen(argv[1], "r");
		if(fp){
			fscanf(fp, "%d", &curr);
			while(!feof(fp)){
				if(curr<n){
					h = inserisciInTesta(h, curr);
				}
				fscanf(fp, "%d", &curr);
			}
			fclose(fp);
			visualizza(h);
			distruggi(h);
		}else{
			printf("errore apertura file\n");
		}
	}else{
		printf("errore argomenti\n");
	}

	return 0;
}