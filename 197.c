/*Scrivere un programma che acquisisce i dati di un array di 25 valori interi. Una volta terminata l'acquisizione, il programma calcola e 
visualizza il massimo del prodotto di tre valori presenti nell'array. L'array, una volta acquisito, non deve essere modificato.*/

#include <stdio.h>

#define DIM 25

int main(){

	int arr[DIM], tmp, max, i, j, k;

	for(i=0; i<DIM; i++){
		scanf("%d", &arr[i]);
	}

	max = arr[0]*arr[1]*arr[2];

	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++){
			for(k=0; k<DIM && k!=i; k++){
				tmp = arr[i]*arr[j]*arr[k];
				if(tmp>max && i!=j && j!=k){
					printf("%d\n", max);
					max = tmp;
				}
			}
		}
	}

	printf("%d\n", max);

	return 0;
}


