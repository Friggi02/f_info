/*Scrivere un programma in C per calcolare la media, il massimo e il minimo di una sequenza di voti, valori interi in trentesimi, 
inseriti dall'utente. L'inserimento dei voti prosegue fino a quando l'utente non immette un valore non valido, cioè minore di 18 o 
maggiore di 30 (valore di "fine inserimento", che non fa parte della sequenza). Quando viene immesso il valore di fine inserimento, 
vengono visualizzati media, massimo, minimo e il numero di voti inseriti. Qualora il primo valore inserito fosse quello di fine 
inserimento, dovrà essere visualizzato un messaggio di errore.*/

#include <stdio.h>

int main(){

	int n, max, min, media, i, somma;

	printf("inserire il voto: ");
	scanf("%d", &n);

	i = 0;
	max = n;
	min = n;
	somma = 0;

	if(n>=18 && n<=30){	
		do{
			i++;
			if(n>max){
				max = n;
			}
			if(n<min){
				min = n;
			}
			somma = somma+n;
			printf("inserire il voto: ");
			scanf("%d", &n);
		}while(n>=18 && n<=30);
		media = somma/i;
		printf("max: %d\nmin: %d\nmedia: %d\nnumero voti: %d\n", max, min, media, i);
	}else{
			printf("errore\n");
		}

	return 0;
}