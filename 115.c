/*Scrivere un programma che mostra a video il triangolo di Tartaglia di dimensione chiesta all'utente (massimo 10). Il programma deve eseguire 
un controllo di validità sulla dimensione chiesta all'utente e nel caso di valore non valido richiederla. Esempio: il triangolo di Tartaglia di 
dimensione 5 (valore inserito dall'utente) è:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/

#include<stdio.h>
#define MAX 10

int main(){

	int n,i,j,a[MAX][MAX];

/*ACQUISIZIONE*/		
	do {
		printf("inserire dimensione: ");
		scanf("%d", &n);
	} while ((n>=MAX) || (n<1));
	
/*INIZIALIZZAZIONE*/
	a[0][0]=1;
	for(j=1;j<n;j++)
	   a[0][j]=0;
			
/*ELABORAZIONE*/
	for(i=1;i<n;i++) {
	  a[i][0]=1;
	  for(j=1;j<n;j++)
	      a[i][j]=a[i-1][j-1]+a[i-1][j];
	}

/*VISUALIZZAZIONE*/
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}

	return 0;
}