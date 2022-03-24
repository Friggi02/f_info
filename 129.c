/*
Il metodo di Euclide per il calcolo del MCD tra due numeri m e n dice che 
MCD(m,n)=m se m=n
MCD(m,n)=MCD(m-n,n) se m>n
MCD(m,n)=MCD(m,n-m) se m<n

Scrivere un sottoprogramma ricorsivo che calcola e restituisce il MCD di due numeri
interi positivi ricevuti come parametro mediante il metodo di Euclide.

Scrivere un programma che chiede due valori interi positivi (che si 
assume vengano inseriti correttamente), ne calcola il MCD mediate il 
sottoprogramma sopra realizzato e visualizza il risultato.
*/

#include <stdio.h>

int mcd(int, int);

int main(){

	int a, b, risultato;

	scanf("%d %d", &a, &b);

	risultato = mcd(a, b);

	printf("%d\n", risultato);

	return 0;
}

int mcd(int a, int b){

	if(a==b){
		return a;
	}else if(a>b){
		return mcd(a-b, b);
	}else{
		return mcd(a, b-a);
	}
}
