/*Una stringa costituisce un pangramma se ogni lettera dell’alfabeto compare almeno una volta. Si scriva un sottoprogramma che ricevuta in
ingresso una stringa restituisce 1 se la stringa è un pangramma, 0 altrimenti. La stringa può contenere caratteri maiuscoli, minuscoli e spazi; non
importa se il carattere compare come maiuscola o minuscola. Si considerino stringhe di senso compiuto in inglese, in modo tale da non aver il
problema delle lettere j, k, w, x, e y, che quindi devono comparire anch’esse.

Esempio:
Ingresso: A quick brown fox jumps over the lazy dog
Valore restituito: 1
Ingresso: There is no easy way out of a problem
Valore restituito: 0

Scrivere un programma che acquisisce una stringa compresa di spazi, richiama il sottoprogramma e visualizza il risultato. */

#include <stdio.h>
#define DIM ('z'-'a'+1)
#define MAXS 50

int pangramma(char*);

int main(){	

	char str[MAXS+1];

	scanf("%[^\n]", str);

	printf("%d\n", pangramma(str));

	return 0;
}

int pangramma(char *str){

	int lettera[DIM], i, tutte;

	for(i=0; i<DIM; i++){
		lettera[i] = 0;
	}

	for(; *str!='\0'; str++){
		if(*str>='a' && *str<='z'){
			lettera[*str-'a'] = 1;
		}else if(*str>='A' && *str<='Z'){
			lettera[*str-'A'] = 1;
		}
	}

	for(i=0, tutte=1; i<DIM && tutte; i++){
		if(!lettera[i]){
			tutte = 0;
		}
	}

	return tutte;
}

