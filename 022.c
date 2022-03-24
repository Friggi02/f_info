/*Scrivere un programma in C che acquisisce un numero maggiore di 1; nel caso il valore inserito sia sbagliato, il programma stampa un 
apposito messaggio di errore e richiede l'inserimento di un nuovo valore. Il programma stabilisce se il numero è primo o meno e 
visualizza un apposito messaggio con il risultato (1:"primo" o 0:"non primo").*/

#include <stdio.h>

int main(){

	int n, i, primo;

	do{
		printf("inserire numero: ");
		scanf("%d", &n);
	}while(n<2);

	i = 2;
	primo = 1;

	while(i*i<=n && primo){
		if(n%i==0){
			primo = 0;
		}
		i++;
	}

	printf("%d\n", primo);

	return 0;
}