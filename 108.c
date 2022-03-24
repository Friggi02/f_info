/*Scrivere un sottoprogramma che chiede all'utente una stringa e conta quante vocali sono contenute, restituendo il risultato.
Scrivere un programma che chiede all'utente una stringa di al massimo 30 caratteri che può
contenere anche degli spazi, invoca su di essa la funzione sopra definita e visualizza il risultato.*/

#include <stdio.h>
#define DIM 30

int acquisisci_conta(char*);

int main(){

	char str[DIM+1];
	int conteggio;

	scanf("%[^\n]", str);

	conteggio = acquisisci_conta(str);

	printf("%d\n", conteggio);

	return 0;
}

int acquisisci_conta(char *str){

	int conto;

	for(conto=0; *str!='\0'; str++){
		switch(*str){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				conto++;
		}
	}

	return conto;
}
