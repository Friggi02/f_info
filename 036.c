/*Si definisce triangolare un numero costituito dalla somma dei primi N numeri interi positivi per un certo N.

Esempio: dato N=4, il numero triangolare Q è 10 (Q=1+2+3+4).

Scrivere un programma in C che acquisisce un numero intero positivo Q (si assuma che l'utente inserisca un valore valido) e stabilisce 
se tale numero è triangolare o meno.*/

#include <stdio.h>

int main(){

	int n, triangolare, i, somma;

	printf("inserire numero: ");
	scanf("%d", &n);

	for(i=0, somma=0, triangolare=0; somma<=n && !triangolare; i++){
		if(somma==n){
			triangolare = 1;
		}
		somma += i;
	}

	
	if(triangolare){
		printf("è triangolare\n");
	}else{
		printf("non è triangolare\n");
	}

	return 0;
}