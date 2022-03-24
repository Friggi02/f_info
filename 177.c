/*Scrivere un sottoprogramma dimmianagrammi che riceve in ingresso una stringa contenente un vocabolo e visualizza il numero di vocaboli
presenti nel file di testo dizionario.txt che sono anagrammi della stringa in ingresso, restituendo il numero di tali vocaboli. I
vocaboli presenti nel dizionario sono di al più 25 caratteri, uno per riga. Nel caso in cui ci siano problemi di accesso al file, il sottoprogramma
restituisce -1.

Per esempio, se il sottoprogramma riceve in ingresso la stringa mira il sottoprogramma visualizza
armi
mari
rami
rima
il programma restituisce 4.

Si ipotizzi di avere a disposizione il sottoprogramma anagramma che restituisce 1 se le due stringhe ricevute in ingresso solo una l’anagramma dell’altra, 0 altrimenti.
int anagramma(char s1[], char s2[]);

Adattare il sottoprogramma dimmianagrammi e/o il sottoprogramma anagramma in modo tale che possa funzionare anche nel momento in cui il programma riceve
in ingresso un valore intero e il file dizionario.txt contiene una sequenza di numeri (uno per riga)
che potrebbero essere l’anagramma del numero ricevuto in ingresso (il numero 9307 è l’anagramma del numero 3790 ...). Nel caso in cui si
modifica il sottoprogramma anagramma, indicare il nuovo prototipo e descrivere cosa fa funzionalmente il sottoprogramma (cosa fa, non come lo fa).
*/

#define FILENAME "dizionario.txt"
#define DIM 25

int anagramma(char s1[], char s2[]);
int dimmianagrammi(char[]);

int dimmianagrammi(char str[]){

	FILE* fp;
	int count;
	char read[DIM+1]

	fp = fopen(FILENAME, "r");
	if(fp){
		fscanf(fp, "%s", read);
		while(!feof(fp)){
			count += anagramma(str, read);
			fscanf(fp, "%s", read);			
		}
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
		count = -1;
	}

	return count;
}


/*VARIANTE CON NUMERI INTERI AL POSTO DELLE LETTERE*/

#define FILENAME "dizionario.txt"

int anagramma_int(int, int);
int anagramma(char s1[], char s2[]);
int dimmianagrammi(char[]);

int anagramma_int(int, int){
	//converte n1 in stringa
	//converte n2 in stringa
	return anagramma(str1, str2);
}


int dimmianagrammi(char str[]){

	FILE* fp;
	int count;
	char read[DIM+1]

	fp = fopen(FILENAME, "r");
	if(fp){
		fscanf(fp, "%d", read);
		while(!feof(fp)){
			count += anagramma(str, read);
			fscanf(fp, "%d", read);			
		}
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
		count = -1;
	}

	return count;
}