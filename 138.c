/*
Scrivere un sottoprogramma ricorsivo che riceve come parametri due stringhe a e b; il sottoprogramma verifica se in b sono presenti 
tutti i caratteri presenti in a, nello stesso ordine, più eventualmente qualche altro carattere. In caso affermativo il 
sottoprogramma restituisce 1 altrimenti 0.

Esempio: 
Per a="acca" b="baracca" il sottoprogramma restituisce 1.
Per a="acca" b="racchetta" il sottoprogramma restituisce 1.
Per a="acca" b="amaca" il sottoprogramma restituisce 0.

Scrivere un programma che chiede all'utente due stringhe di al più 50 caratteri,
invoca il sottoprogramma definito e visualizza il risultato.

VARIANTE: Scrivere la versione iterativa del sottoprogramma appena realizzato.*/

#include <stdio.h>
#define MAXS 30

int check(char[], char[]);

int main(){

	char a[MAXS], b[MAXS];
	int risultato;

	scanf("%s", a);
	scanf("%s", b);

	risultato = check(a, b);

	printf("%d\n", risultato);
	
	return 0;
}

int check(char a[], char b[]){

	if(*a=='\0'){
		return 1;
	}

	if(*a!='\0' && *b=='\0'){
		return 0;
	}

	if(*a==*b){
		return check(a+1, b+1);
	}

	return check(a, b+1);

}