/*Scrivere un programma in C che chiede all'utente 5 valori interi non negativi e ne disegna
l'istogramma a barre verticali orientate dall'alto al basso come mostrato nel seguente esempio. 

Se l'utente inserisce i valori: 1 4 5 2 1, il programma visualizzerà il seguente output:
1 4 5 2 1 
* * * * * 
  * * * 
  * * 
  * * 
    *                       */

#include <stdio.h>
#define DIM 5

int main(){
	
	int h[DIM], i , j, altezza;

/*ACQUISIZIONE*/	
	for(i=0; i<DIM; i++){
		do{
			scanf("%d", &h[i]);
		}while(h[i]<0);
	}

/*TROVO IL MASSIMO*/		
	for(i=1, altezza=h[0]; i<DIM; i++){
		if(altezza<h[i]){
			altezza = h[i];
		}
	}

/*STAMPO LA RIGA DI NUMERI*/	
	for(i=0; i<DIM; i++){
		printf("%d ", h[i]);
	}
	printf("\n");

/*STAMPO L'ISTOGRAMMA*/
	for(i=0; i<altezza; i++){
		for(j=0; j<DIM; j++){
			if(i<h[j]){
				printf("* ");
			}else{
				printf("  ");
			}
		}
		printf("\n");
	}
		
	return 0;
}