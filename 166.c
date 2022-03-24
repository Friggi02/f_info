/*
Si vuole realizzare un programma che verifica se una griglia di un Sudoku, anche parzialmente riempita, sia valida o meno. In breve una griglia di un 
Sudoku è una matrice 9x9 di interi e ciascuna posizione può contenere un valore da 1 a 9 o esser vuota se la griglia non è stata 
ancora completata. Una griglia, anche parzialmente, è valida se si verificano tutte le seguenti condizioni:
* in ciascuna riga della matrice non si presenta alcuna ripetizione dei numeri validi (da 1 a 9)
* in ciascuna colonna della matrice non si presenta alcuna ripetizione dei numeri validi (da 1 a 9)
* dividendo la matrice 9x9 in 9 sottomatrici 3x3 non sovrapposte, ciascuna sottomatrice non contiene alcuna ripetizione dei numeri validi (da 1 a 9).
Realizzare il programma come segue:
- definire una costante VUOTO contenente il valore 0.
- definire un sottoprogramma "stampa_sudoku" che riceva come argomento una matrice definita con 9 colonne e la stampi a video. Si utilizzi uno spazio per indicare le celle vuote;

opzionale: 
disegnare le righe orizzontali e verticali che contornano l'intera griglia e le 9 sottogriglie come da esempio:
+-------+-------+-------+
|   9   |       | 4     |
| 8   5 |     4 | 1     |
|     4 | 6 8 1 | 5 3 9 |
+-------+-------+-------+
|     8 |   4 9 | 7   3 |
|   7   |     6 |   4 8 |
| 4 1   | 8 3   | 6     |
+-------+-------+-------+
| 3 5   | 4     | 2 9 1 |
| 9   2 | 1   3 |   7 6 |
| 1     |   6   |   5 4 |
+-------+-------+-------+

definire un sottoprogramma "leggi" che riceve come argomento il nome di un file di testo e una matrice di interi dichiarata con 9 
colonne. Il sottoprogramma apre il file di testo, contenente 9x9 valori interi, e popola la matrice con i dati letti da file. Il 
sottoprogramma restituisce 1 se l'operazione è andata a buon fine altrimenti 0. Si noti che si potrebbe verificare un errore di 
apertura del file o il numero di valori letti potrebbe essere erroneamente minore di 81 o un dato valore potrebbe essere al di 
fuori dell'intervallo [1,9] o diversa da VUOTO. Il sottoprogramma prima di ritornare stampa a video la causa dell'eventuale errore riscontrato.

definire un sottoprogramma "verifica_sudoku" che riceva come argomento una matrice di interi dichiarata con 9 colonne e verifichi 
che il sudoku associato sia valido. Il sottoprogramma restituisce 1 in caso affermativo; in alternativa stampa a video un messaggio per 
ciascun errore riscontrato (cioè indici di riga o colonna o quadrante che violano le regole) e restituisce 0. 

Scrivere un programma chiede all'utente il nome del file (una stringa di al massimo 50 caratteri). Mediante l'ausilio dei 
sottoprogrammi sopra definiti, il programma legge la matrice dal file, la stampa a video e verifica se la griglia è valida, stampando 
a video il responso. Gestire opportunamente gli eventuali errori.
*/

#include <stdio.h>
#include <stdlib.h>
#define VUOTO 0
#define MAXS 50

int leggi(int[9][9]);
void visualizza(int[9][9]);
int verifica_sudoku(int[9][9]);

int main(){

	int a[9][9];

	if(leggi(a)){
		if(verifica_sudoku(a)){
			visualizza(a);
		}
	}
	
	return 0;
}

int leggi(int a[9][9]){

	int i, j, ok, n, conto;

	FILE *fp;
	char filename[MAXS+1];

	printf("nome del file: ");
	scanf("%s", filename);

	fp = fopen(filename, "r");

	if(fp){
		fscanf(fp, "%d", &n);
		ok = 1;
		i=0;
		j=0;
		while(!feof(fp) && ok && (i<9 && j<9)){
			if(n<0 || n>9){
				printf("errore: valori non validi\n");
				ok = 0;
			}else{
				a[i][j] = n;
				conto++;
				j++;
				if(j==9){
					j=0;
					i++;
				}			
			}
			fscanf(fp, "%d", &n);				
		}
		fclose(fp);
		if(conto!=81){
			ok = 0;
			printf("errore: numero di valori\n");
		}
	}else{
		ok = 0;
		printf("errore: apertura del file\n");
	}

	return ok;
}

void visualizza(int a[9][9]){

	int i, j;

	for(i=0; i<9; i++){
		if(i%3==0){
			printf("+-------+-------+-------+\n");
		}
		for(j=0; j<9; j++){
			if(j%3==0){
				printf("| ");
			}
			if(a[i][j]==VUOTO){
				printf("  ");
			}else{
				printf("%d ", a[i][j]);
			}
		}
		printf("|\n");
	}
	printf("+-------+-------+-------+\n");
}

int verifica_sudoku(int m[9][9]){ 
	
	int ok, i, j, h, k, l, c; 
	
	for (i=0, ok=1; i<9 && ok; i++){ 
		for(j=0; j<9 && ok; j++){ 
			for(h=0; h<9 && ok; h++){ 
				if(j!= h && m[i][j]==m[i][h] && m[i][j]!=VUOTO){ 
					printf("Errore: ripetizione di %d (%d, %d) in (%d, %d)\n",m[i][j], i, j, i, h); 
					ok=0; 
				} 
			} 
		} 
	} 
	 
	for (i=0; i<9 && ok; i++){ 
		for(j=0; j<9 && ok; j++){ 
			for(h=0; h<9 && ok; h++){ 
				if(j!= h && m[j][i]==m[h][i] && m[j][i]!=VUOTO){ 
					printf("Errore: ripetizione di %d (%d, %d) in (%d, %d)\n", m[j][i], i, j, h, i); 
					ok=0; 
				} 
			} 
		} 
	} 
	 
	for(i=0; i<9 && ok; i+=3){ 
		for(j=0; j<9 && ok; j+=3){
			for(h=i; h<3+i && ok; h++){ 
				for(k=j; k<3+j && ok; k++){ 
					for(l=i; l<3 && ok; l++){ 
						for(c=j; c<3 && ok; c++){ 
							if(l!=h && h!=c && m[h][k]==m[l][c] && m[h][k]!=VUOTO){ 
								printf("Errore: ripetizione di %d (%d, %d) in (%d, %d)\n",m[h][k], h, k, l, c); 
								ok=0; 
							} 
						} 
					} 
				} 
			} 
		} 
	} 
	 
	return ok; 
}