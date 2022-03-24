/*Scrivere un programma in C che chiede all'utente una sequenza di 10 numeri interi. Il programma controlla che non vi siano duplicati 
all'interno della sequenza data e visualizza l'esito del test (1 se non ci sono duplicati, 0 altrimenti).*/

#include <stdio.h>
#define DIM 10

int main(){

	int arr[DIM], i, j, nodupl;

	for(i=0; i<DIM; i++){
		scanf("%d", &arr[i]);
	}

	for(i=0, nodupl=1; i<DIM && nodupl; i++){
		for(j=0; j<i && nodupl; j++){
			if(arr[i]==arr[j]){
				nodupl = 0;
			}
		}	
	}

	printf("esito: %d\n", nodupl);

	return 0;
}