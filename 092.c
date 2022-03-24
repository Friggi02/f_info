/*Scrivere un programma che riceve in ingresso un numero positivo pari n;
il programma continuerà a richiedere il numero n finché la condizione non sarà soddisfatta.
In seguito, il programma disegna a video un triangolo con base n utilizzando il carattere * come mostrato nel seguente esempio.
Sia n=10, il disegno da mostrare è

    **
   ****
  ******
 ********
**********													*/


#include <stdio.h>

int main(){

	int base, i, j, k;

	do{
		scanf("%d", &base);
	}while(base<=0);

	base = base/2;

	for(i=1; i<=base; i++){
		for(j=1; j<=base+1-i; j++){
			printf(" ");
		}
		for(k=1; k<=(2*i-1)+1; k++){
			printf("*");
		}
		printf ("\n");
	}

	return 0;
}