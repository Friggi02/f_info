/*
Scrivere una funzione analizzastringa (ed il relativo prototipo) che riceve come parametro una stringa. La funzione restituisce 1 se 
la stringa è lunga più di 5 caratteri e contiene almeno 2 cifre numeriche ed un carattere che non sia una cifra; in caso negativo la 
funzione restituisce 0.

Scrivere un programma che apre in lettura un file di testo testo.txt contenente una serie di lunghezza indefinita di parole 
ciascuna lunga al massimo 15 caratteri ed in scrittura un secondo file risultato.txt. Il programma legge ciascuna parola contenuta in 
testo.txt e la scrive in risultato.txt soltanto se l'invocazione della funzione analizzastringa su di essa porta ad un risultato 
positivo (la funzione restituisce 1).

Ad esempio, se il file contiene il seguente testo: Ciao45 baubau 2345678 esame2020 trallallero1 bimbumbam345 a234
Il programma salverà in risultato.txt il seguente testo:
Ciao45
esame2020
bimbumbam345	*/

#include <stdio.h>
#define FN_IN "input.txt"
#define FN_OUT "output.txt"
#define MAXS 15
#define LEN 5
#define CIFRE 2

int check(char[]);

int main(){
	
	FILE *fpi, *fpo;
	char str[MAXS+1];

	fpi = fopen(FN_IN, "r");
	if(fpi){
		fpo = fopen(FN_OUT, "w");
		if(fpo){
			fscanf(fpi, "%s", str);
			while(!feof(fpi)){
				if(check(str)){
					fprintf(fpo, "%s\n", str);
				}
				fscanf(fpi, "%s", str);
			}
			fclose(fpo);
		}else{
			printf("errore nell'apertura del file\n");
		}
		fclose(fpi);
	}else{
		printf("errore nell'apertura del file\n");
	}

	return 0;
}

int check(char str[]){

	int i, n_cifre;

	printf("%s\n", str);

	for(i=0, n_cifre=0; str[i]!='\0'; i++){
		if(str[i]>='0' && str[i]<='9'){
			n_cifre++;
		}
	}
	
	return ((i>LEN) && (n_cifre>=CIFRE) && (i>n_cifre));
}