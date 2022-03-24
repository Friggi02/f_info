/*Un intero n>=0 si dice “numero narcisistico di ordine x” se la somma delle potenze x-esime delle sue cifre è uguale al numero stesso n.

Esempi di numeri narcisistici sono:
• 153 == 1^3 + 5^3 + 3^3 – narcisista ordine 3
• 1634 == 1^4 + 6^4 + 3^4 + 4^4 – narcisista ordine 4

Scrivere un sottoprogramma trovanarcisisti che, ricevuto in ingresso due array di interi numero e tipo di egual dimensione, un intero
x e qualsiasi altro parametro ritenuto necessario, analizza ciascun valore contenuto in numero e se è narcisistico di ordine x mette un 1 nel
corrispondente elemente dell’array tipo, 0 altrimenti.

Scrivere un programma che chiede all'udetente un ordine e popola un array di dimensione 5. Il programma richiama il sottoprogramma e visualizza il risultato.*/

#include <stdio.h>
#include <math.h>
#define DIM 5

int narcisista(int, int);
void trovanarcisisti(int[], int[], int, int);

int main(){	

	int ordine, arr[DIM], tipo[DIM], n, i;

	printf("inserisci ordine: ");
	scanf("%d", &ordine);
	for(i=0; i<DIM; i++){
		scanf("%d", &arr[i]);
	}

	trovanarcisisti(arr, tipo, ordine, DIM);

	for(i=0; i<DIM; i++){
		printf("%d ", tipo[i]);
	}
	printf("\n");

	return 0;
}

int narcisista(int n, int ordine){

	int somma;

	somma = n;

	while(n>0){
		somma -= pow(n%10, ordine);
		n /= 10;
	}

	return somma==0;
}

void trovanarcisisti(int arr[], int tipo[], int ordine, int dim){

	int i;

	for(i=0; i<dim; i++){
		tipo[i] = narcisista(arr[i], ordine);
	}
}