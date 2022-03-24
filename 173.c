/*Scrivere un sottoprogramma che riceve in ingresso un array di valori interi v e qualsiasi altro parametro ritenuto necessario, ed altri due valori interi
da e a. Il sottoprogramma verifica se nell’array sono presenti tutti e soli i valori inclusi nell’intervallo [da,a], senza ripetizioni. In caso positivo il
sottoprogramma restituisce 1, 0 in caso contrario.

Scrivere un programma che popola un array di interi di dimensione 10 e chiede all'utente l'intervallo da analizzare.
Il programma invoca il sottoprogramma e stampa l'esito.*/

#include <stdio.h>
#define DIM 10

int analizza(int v[], int dim, int da, int a);

int main(){

	int arr[DIM], da, a, esito, i;

	printf("inerisci array di %d elementi: ", DIM);
	for(i=0; i<DIM; i++){
		scanf("%d", &arr[i]);
	}
	printf("inserisci intervallo: ");
	scanf("%d %d", &da, &a);

	esito = analizza(arr, DIM, da, a);

	printf("esito: %d\n", esito);

	return 0;
}


int analizza(int v[], int dim, int da, int a){

	int i, j, ok, conto;

	for(i=a, ok=1; i<=a && ok; i++){
		for(j=0, conto=0; j<dim && conto<=1; j++){
			if(v[j]==i){
				conto++;
			}
		}
		if(conto!=1){
			ok = 0;
		}
	}
	return ok;
}


/*VARIANTE*/
/*
int analizza(int v[], int dim, int da, int a){

	int i, j, ok, found;

	if(dim==a-da+1){
		for(i=a, ok=1; i<=a && ok; i++){
			for(j=0, found=0; j<dim && !found; j++){
				if(v[j]==i){
					found = 1;
				}
			}
			if(!found){
				ok = 0;
			}
		}
	}else{
		ok = 0;
	}
	return ok;
}
*/