/*Scrivere un programma che chiede all'utente la dimensione m di due matrici quadrate di interi A e B (un valore intero compreso tra 1 e 10 e 
nel caso non sia valido va richiesto) e poi i dati per popolare le due matrici.
Per ogni valore n compreso tra 2 e m (estremi inclusi), il programma calcola e stampa le coordinate (i,j) dell'angolo in alto a sinistra di 
tutte le sottomatrici quadrate nxn di A e B che soddisfano entrambe le seguenti condizioni:
- hanno la stessa posizione (i,j) in entrambe le matrici A e B
- la sottomatrice definita su A e la sottomatrice definita su B sono uguali (contengono gli stessi elementi, posizione per posizione)

Esempio:
Date le matrici
A:
5 3 7 1 8
3 9 2 7 1
3 9 7 5 6
4 5 7 1 3
8 6 2 9 9

B:
0 3 7 0 1
0 9 2 7 0
3 9 7 5 1
4 5 7 1 0
1 0 0 9 1

L'output del programma sarà
N=2
(0, 1) (1, 1) (1, 2) (2, 0) (2, 1) (2, 2) 
N=3
(1, 1) 
N=4
Nessuna sottomatrice soddisfa le condizioni
N=5
Nessuna sottomatrice soddisfa le condizioni*/

#include <stdio.h>

int main(){

	int dim;

/*ACQUISISCO LA DIMENSIONE*/
	do{
		printf("dimensione: ");
		scanf("%d", &dim);
	}while(dim<=0 || dim>10);

/*DICHIARO VARIABILI*/
	int a[dim][dim], b[dim][dim], n, i, j, ok, k, l;

/*ACQUISISCO MATRICE A*/
	printf("\ninserisci matrice A:\n");
	for(i=0; i<dim;i++){
		for(j=0; j<dim; j++){
			scanf("%d", &a[i][j]);
		}
	}

/*ACQUISISCO MATRICE B*/
	printf("\ninserisci matrice B:\n");
	for(i=0; i<dim;i++){
		for(j=0; j<dim; j++){
			scanf("%d", &b[i][j]);
		}
	}

/*ELABORAZIONE*/
	for(n=2; n<=dim; n++){
		printf("\nN=%d\n", n);
		for(i=0; i<dim-n; i++){
			for(j=0; j<dim-n; j++){
				for(k=0, ok=1; k<n && ok; k++){
					for(l=0; l<n; l++){
						if(a[i+k][j+l]!=b[i+k][j+l]){
							ok = 0;
						}
					}
				}
				if(ok){
					printf("(%d %d) ", i, j);
				}
			}
		}
		if(!ok){
			printf("Nessuna sottomatrice soddisfa le condizioni");
		}
	}

	
	return 0;
}