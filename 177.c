/*Scrivere un sottoprogramma dimmianagrammi che riceve in ingresso una stringa contenente un vocabolo e visualizza il numero di vocaboli
presenti nel file di testo dizionario.txt che sono anagrammi della stringa in ingresso, restituendo il numero di tali vocaboli. I
vocaboli presenti nel dizionario sono di al più 25 caratteri, uno per riga. Nel caso in cui ci siano problemi di accesso al file, il sottoprogramma
restituisce -1.

Scrivere un sottoprogramma anagramma che restituisce 1 se le due stringhe ricevute in ingresso solo una l’anagramma dell’altra, 0 altrimenti.

Scrivere un programma che chiede all'utente una stringa di testo e richiami i sottoprogrammi definiti sopra.

Per esempio, se il programma riceve in ingresso la stringa mira il programma visualizza:

armi
mari
rami
rima

4 anagrammi trovati

*/

#include <stdio.h>
#include <string.h>

#define FILENAME "dizionario.txt"
#define DIM 25

int anagramma(char s1[], char s2[]);
int dimmianagrammi(char[]);

int main(){

	char str[DIM+1];
	int conteggio;

	printf("inserire stringa: ");
	scanf("%s", str);

	printf("\n");

	conteggio = dimmianagrammi(str);

	printf("\n%d anagrammi trovati\n", conteggio);

	return 0;
}

int anagramma(char s1[], char s2[]){

	int i, len1, len2, somma1, somma2, prodotto1, prodotto2;

	for(len1=0; s1[len1]!='\0'; len1++);
	for(len2=0; s2[len2]!='\0'; len2++);

	somma1 = 0;	
	somma2 = 0;
	prodotto1 = 1;
	prodotto2 = 1;

	if(len1==len2){
		for(i=0; i<len1; i++){
			somma1 += s1[i];
			prodotto1 *= s1[i];
		}
		for(i=0; i<len2; i++){
			somma2 += s2[i];
			prodotto2 *= s2[i];
		}
		if(somma1==somma2 && prodotto1==prodotto2 && strcmp(s1, s2)){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

int dimmianagrammi(char str[]){

	FILE* fp;
	int count;
	char read[DIM+1];

	count = 0;

	fp = fopen(FILENAME, "r");
	if(fp){
		fscanf(fp, "%s", read);
		while(!feof(fp)){
			if(anagramma(str, read)){
				count++;
				printf("%s\n", read);
			}
			fscanf(fp, "%s", read);			
		}
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
		count = -1;
	}

	return count;
}