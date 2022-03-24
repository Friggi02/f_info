/*Un dato sistema informatico richiede che ciascun username sia una stringa composta da almeno N caratteri, di cui almeno NL lettere 
dell'alfabeto maiuscolo o minuscolo e non contenga alcun carattere speciale appartenente ad una stringa di controllo SYMB (per esempio "%:;-+"). 

Scrivere un sottoprogramma che riceve come parametri una stringa rappresentante un username, gli interi N ed NL e la stringa SYMB; il 
sottoprogramma restituisce 1 se la stringa rappresenta un username valida, altrimenti 0.
Esempio: con N=8, NL=5 e SYMB="%:;-+", "Domani.898" è un username valida, mentre "domani:898" e "do.898" non lo sono.

Scrivere un programma che chiede all'utente una stringa di al massimo 20 caratteri ed invoca il sottoprogramma sopra definito specificando
i seguenti valori per i parametri: N=8, NL=5 e SYMB="%:;-+". Il sottoprogramma visualizza il risultato restituito dal sottoprogramma.*/

#include <stdio.h>
#define N 8
#define NL 5
#define SYMB "%:;-+"
#define SDIM 20


int isusername(char[], int, int, char[]);

int main(){

	char username[SDIM+1];
	int check;

	scanf("%s", username);

	check = isusername(username, N, NL, SYMB);

	printf("%d\n", check);
	
	return 0;
}

int isusername(char usr[], int n, int nl, char symb[]){

	int i, num_lettere, ok, j;

	for(i=0, num_lettere=0, ok=1; usr[i]!='\0' && ok; i++){
		if((usr[i]>='a' && usr[i]<='z') || (usr[i]>='A' && usr[i]<='Z')){
			num_lettere++;
		}
		for(j=0; symb[j]!='\0' && ok; j++){
			if(symb[j]==usr[i]){
				ok = 0;
			}
		}
	}

	return i>=n && num_lettere>=nl && ok;
}