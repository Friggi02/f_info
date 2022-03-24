/*Scrivere un sottoprogramma che ricevuto in ingresso un valore intero
restituisce al chiamante il numero di cifre che compaiono più di una volta.

Per esempio, se il sottoprogramma riceve in ingresso il valore 3284821 il sottoprogramma
restituisce il valore 2, perché la cifra 8 e 2 compaiono entrambe più di una volta.

Scrivere un programma che chiede un numero intero all'utente, chiama il sottoprogramma e visualizza il risultato.*/

#include <stdio.h>
#define BASE 10
#define SOGLIA 2

int conta(int n);

int main(){

	int n;

	printf("inserire numero: ");
	scanf("%d", &n);

	printf("%d\n", conta(n));

	return 0;
}

int conta(int n){

	int arr[BASE], i, conto;

/*INIZIALIZZO L'ARRAY*/
	for(i=0; i<BASE; i++){
		arr[i] = 0;
	}

/*CONSIDERO IL CASO N NEGATIVO*/
	if(n<0){
		n = -n;
	}

/*SEPARO LE CIFRE DEL NUMERO E INCREMENTO LA POSIZIONE RELATIVA NELL'ARRAY*/
	do{
		i = n%BASE;
		n = n/BASE;
		arr[i]++;
	}while(n>0);

/*CONTROLLO LE RIPETIZIONI DI TUTTE LE CIFRE*/
	for(i=0, conto=0; i<BASE; i++){
		if(arr[i]>=SOGLIA){
			conto++;
		}
	}

	return conto;
}