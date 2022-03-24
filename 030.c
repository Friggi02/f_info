/*Scrivere un programma in C che acquisisce due numeri interi n ed m. Il programma calcola e visualizza il valore della potenza n^m. 
Gestire opportunamente il caso in cui m è negativo (il risultato sarà 1/(n^(|m|) ). Prestare attenzione al caso in cui l'utente 
inserisca due valori tali per cui n==0 e m<=0, per cui si verificherebbe una divisione per 0; in tal caso il programma stampa 
un messaggio di errore e richiede i valori.*/

#include <stdio.h>

int main(){

	int n, m, abs_m;
	float risultato;

	printf("inserire base ed esponente: ");
	scanf("%d %d", &n, &m);

	while(n==0 && m<=0){
		printf("errore\n");
		printf("inserire base ed esponente: ");
		scanf("%d %d", &n, &m);
	}

	risultato = 1;

	if(m<0){
		abs_m = -m;
	}else{
		abs_m = m;
	}

	while(abs_m>0){
		risultato = risultato*n;
		abs_m--;
	}

	if(m<0){
		risultato = 1/risultato;
	}

	printf("%f\n", risultato);

	return 0;
}