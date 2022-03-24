/*Scrivere un programma in C che calcola il prodotto tra due polinomi di grado massimo 8. Il programma chiede prima il grado (e nel caso 
di valore non valido lo richiede) ed i coefficienti di ciascuno dei due polinomi (i coefficienti sono valori interi). In seguito esegue 
il prodotto polinomiale e visualizza i coefficienti del polinomio risultato.*/

#include <stdio.h>
#define DIM 8

int main(){

	int grad_maxA, poliA[DIM+1], grad_maxB, poliB[DIM+1], grad_maxC, poliC[DIM*2+1], i, j;

/*ACQUISIZIONE POLINOMIO A*/
	printf("	polinomio A\n");
	printf("immettere grado massimo: ");
	scanf("%d", &grad_maxA);
	while(grad_maxA<0 || grad_maxA>DIM){
		printf("errore\n");
		scanf("%d", &grad_maxA);
	}
	for(i=0; i<=grad_maxA; i++){
		printf("coefficiente per incognita grado %d: ", i);
		scanf("%d", &poliA[i]);
	}


/*ACQUISIZIONE POLINOMIO B*/
	printf("	polinomio B\n");
	printf("immettere grado massimo: ");
	scanf("%d", &grad_maxB);
	while(grad_maxB<0 || grad_maxB>DIM){
		printf("errore\n");
		scanf("%d", &grad_maxB);
	}
	for(i=0; i<=grad_maxB; i++){
		printf("coefficiente per incognita grado %d: ", i);
		scanf("%d", &poliB[i]);
	}


/*ELABORAZIONE*/
	grad_maxC = grad_maxA+grad_maxB;
	for(i=0; i<=grad_maxC; i++){
		poliC[i] = 0;
	}
	for(i=0; i<=grad_maxA; i++){
		for(j=0; j<=grad_maxB; j++){
			poliC[i+j] += poliA[i]*poliB[j]; 
		}
	}


/*VISUALIZZAZIONE*/
	printf("\n\tA*B=\n");
	for(i=0; i<=grad_maxC; i++){
		printf("coefficiente per incognita grado %d: %d\n", i, poliC[i]);
	}

	return 0;
}