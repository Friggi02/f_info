/*Scrivere un programma in C che chiede all'utente di inserire due sequenze di 10 numeri interi ciascuna. Il programma controlla che la 
seconda sequenza sia una permutazione della prima e stampa a video l'esito del test (1: permutazioni, 0: altrimenti).*/

#include <stdio.h>
#define DIM 10

int main(){

	int sequenzaA[DIM], sequenzaB[DIM], i, j, contaA, contaB, permutazioni;

	for(i=0; i<DIM; i++){
		scanf("%d", &sequenzaA[i]);
	}

	for(i=0; i<DIM; i++){
		scanf("%d", &sequenzaB[i]);
	}

	for(i=0, permutazioni=1; i<DIM && permutazioni; i++){
		contaA = 0;
		contaB = 0;
		for(j=0; j<DIM; j++){
			if(sequenzaA[i]==sequenzaA[j]){
				contaA++;
			}
		}
		for(j=0; j<DIM; j++){
			if(sequenzaA[i]==sequenzaB[j]){
				contaB++;
			}
		}
		if (contaA!=contaB){
			permutazioni = 0;
		}
	}

	printf("esito: %d\n", permutazioni);

	return 0;
}