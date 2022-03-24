/*Scrivere un programma che chiede all'utente il nome di due file di testo (due stringhe di al massimo 30 caratteri ciascuna).
Il programma apre i due file e verifica se il loro contenuto è identico; in caso affermativo il programma stampa a video 1 
altrimenti 0. Segnalare a video eventuali casi di errore.*/

#include <stdio.h>
#include <stdlib.h>
#define MAXS 30

int main(){

	char fn1[MAXS+1], fn2[MAXS+1], c1, c2;
	int uguali;

	FILE *fp1, *fp2;

	printf("nome primo file: ");
	scanf("%s", fn1);
	printf("nome secondo file: ");
	scanf("%s", fn2); 

	fp1 = fopen(fn1, "r");
	if(fp1){
		fp2 = fopen(fn2, "r");
		if(fp2){
			uguali = 1;
			fscanf(fp1, "%c", &c1);
			fscanf(fp2, "%c", &c2);
			while(!feof(fp1) && !feof(fp2) && uguali){
				if(c1!=c2){
					uguali = 0;
				}
				fscanf(fp1, "%c", &c1);
				fscanf(fp2, "%c", &c2);
			}
			if(!feof(fp1) || !feof(fp2)){
				uguali = 0;
			}
			printf("%d\n", uguali);
			fclose(fp2);
		}else{
			printf("errore di apertura del file\n");
		}
		fclose(fp1);
	}else{
		printf("errore di apertura del file\n");
	}

	return 0;
}