/*Scrivere un programma in C che acquisisce due numeri interi positivi a e b
(se i numeri non sono validi li richiede), calcola MCD ed mcm, e li visualizza.*/

#include <stdio.h>

int main(){

	int a, b, mcd, mcm, prodotto;

	do{
		printf("inserire i due numeri: ");
		scanf("%d %d", &a, &b);
	}while(a<0 || b<0);

	prodotto = a*b;

	while(a!=b){
        if(a>b){
        	a = a-b;
        }else{
        	b = b-a;
        }
    }

    mcd = a;
    mcm = prodotto/mcd;   
     
    printf("mcd: %d\nmcm: %d\n", mcd, mcm);

	return 0;
}