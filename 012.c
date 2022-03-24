/*Scrivere un programma in C che acquisisce due numeri interi e stampa a video il maggiore dei due.*/

#include <stdio.h>

int main(){

	int x, y;

	printf("inserire i due numeri: ");
	scanf("%d %d", &x, &y);

	if(x>=y){
		if(x==y){
			printf("i due numeri sono uguali\n");
		}else{
			printf("il maggiore è %d\n", x);
		}
	}else{
		printf("il maggiore è %d\n", y);
	}

	return 0;
}