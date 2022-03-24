/*Scrivere un programma in C chiede all'utente un numero intero e ne visualizza il suo valore assoluto.*/

#include <stdio.h>

int main(){

	int n, a;

	printf("inserire numero: ");
	scanf("%d", &n);

	if(n<0){
		a = -n;
	}else{
		a = n;
	}

	printf("%d\n", a);

	return 0;
}