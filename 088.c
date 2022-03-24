/*Scrivere un programma in C che chiede all'utente una stringa di al massimo 30 caratteri. Il programma individua la sequenza più lunga 
di caratteri consecutivi tutti uguali e ne visualizza la lunghezza ed il carattere che si ripete. Nel caso ci siano più di una sequenza
a pari lunghezza massima, il programma visualizza i dati (dimensione e valore ripetuto) dell'ultima sequenza individuata.*/

#include <stdio.h>
#define MAXS 30

int main(){

	char str[MAXS+1], maxchar;
	int i, currlen, maxlen;

	scanf("%s", str);

	maxchar = str[0];
	maxlen = 0;
	currlen = 1;

	for(i=0; str[i]!='\0'; i++){
		if(str[i]==str[i+1]){
			currlen++;
		}else{
			if(currlen>=maxlen){
				maxlen = currlen;
				maxchar = str[i];
			}
			currlen = 1;
		}
	}

	printf("il carattere %c compare %d volte\n", maxchar, maxlen);
	
	return 0;
}