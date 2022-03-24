/*Scrivere un programma in C che chiede all'utente una sequenza di 20 numeri interi salvandoli in un array.
Il programma salva in un secondo array tutti e soli i valori distinti della sequenza acquisita (ovvero omettere i duplicati).
Infine il programma visualizza il contenuto del secondo array e la sua lunghezza.*/

#include <stdio.h>
#define DIM 20

int main(){

	int a1[DIM], a2[DIM], i, k, j, trovato;

	for(i=0; i<DIM; i++){
		scanf("%d", &a1[i]);
	}

	for(i=0, k=0; i<DIM; i++){
		for(j=0, trovato=0; j<i && !trovato; j++){
			if(a1[i]==a1[j]){
				trovato = 1;		
			}
		}
		if(!trovato){
			a2[k] = a1[i];
			k++;
		}
	}

	printf("vettore senza duplicati:\n");


	for(i=0; i<k; i++){
		printf("%d ", a2[i]);
	}

	printf("numero di elementi: %d\n", k);

	return 0;
}