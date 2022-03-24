/*
Scrivere un sottoprogramma che, ricevuto in ingresso un array monodimensionale di interi e qualsiasi parametro ritenuto 
strettamente necessario, individua la sottosequenza più lunga di valori
tutti uguali tra di loro e trasmette al chiamante il valore e la lunghezza.
Nel caso ci fosse più di una sottosequenza di pari lunghezza massima, il sottoprogramma restituisce la prima
Esempio:
Ingresso = 1 2 8 3 3 7 4 6 6 6 6 3 2 2 8 8 8 8 8 3 3
Uscita: valore = 8, lunghezza = 5

Scrivere un programma che chiede all'utente la dimensione di un array e lo popola.
Richiama il sottoprogramma e visualizza il risultato.
*/




#include <stdio.h>

void sottosequenza(int[], int, int*, int*);

int main(){

	int valore, lunghezza, i, dim;

	printf("dimensione array: ");
	scanf("%d", &dim);

	int a[dim];

	for(i=0; i<dim; i++){
		scanf("%d", &a[i]);
	}

	sottosequenza(a, dim, &valore, &lunghezza);

	printf("valore = %d, lunghezza = %d\n", valore, lunghezza);
	
	return 0;
}

void sottosequenza(int a[], int dim, int *valore, int *lunghezza){

	int i, v, l;

	v = a[0];
	l = 0;
	*lunghezza = 0;

	for(i=0; i<dim; i++){
		if(a[i]==v){
			l++;
		}else{
			if(*lunghezza<l){
				*lunghezza = l;
				*valore = v;
			}
			l = 1;
			v = a[i];
		}
	}
	if(*lunghezza<l){
		*lunghezza = l;
		*valore = v;
	}
}