/*In un array bidimensionale di valori interi, si definisce dominante ogni elemento dell’array che è strettamente maggiore di tutti gli elementi dell’array
bidimensionale che si trova in basso a destra rispetto all’elemento stesso (si veda la figura), non considerando però tutti gli elementi presenti nell’ultima
colonna e nell’ultima riga. Si realizzi un sottoprogramma che ricevuto in ingresso un array bidimensionale e qualsiasi altro parametro ritenuto
strettamente necessario stampi tutti i dominanti presenti e restituisca al chiamante il loro numero. Nel contesto di utilizzo del sottoprogramma,
sono presenti le seguenti direttive/istruzioni riportate di seguito.


#define NR ...
#define NC ...
...
int main (int argc, char *argv[])
{
...
int info [NR][NC];
}

Scrivere un programma che acquisisce una matrice di dimensioni a piacere, esegue il sottoprogramma e stampa il numero dei dominanti.

Esempio:
5 9 2 4 1 7 2 4
3 5 6 2 5 6 1 2
1 3 4 7 8 8 3 0
1 3 5 6 7 8 2 1

Il programma restituisce:
dominanti: 9 7 6 8 3
nella matrice ci sono 5 dominanti

*/


#include <stdio.h>
#define NR 4
#define NC 8

int analizza(int m[][NC], int nr, int nc);

int main (){

	int mat[NR][NC], i, j, risultato;

	for(i=0; i<NR; i++){
		for(j=0; j<NC; j++){
			scanf("%d", &mat[i][j]);
		}
	}


	printf("\ndominanti: ");
	risultato = analizza(mat, NR, NC);

	printf("\nnella matrice ci sono %d dominanti\n", risultato);

	return 0;
}

int analizza(int m[][NC], int nr, int nc){

	int i, j, h, k, ndom, domina;
	
	for(i=0, ndom=0; i<nr-1; i++){
		for(j=0; j<nc-1; j++){
			for(h=i+1, domina=1; h<nr && domina; h++){
				for(k=j+1; k<nc && domina; k++){
					if(m[i][j]<=m[h] [k]){
						domina = 0;
					}
				}
			}
			if(domina){
				ndom++;
				printf("%d ", m[i][j]);	
			}
		}
	}
	return ndom;
}