/*Scrivere un sottoprogramma ricorsivo che riceve come parametri due stringhe e verifica se sono uguali o meno.
In caso affermativo il sottoprogramma restituisce 1 altrimenti 0.

Scrivere un programma che chiede all'utente due stringhe di al massimo 30 caratteri,
invoca il sottoprogramma definito e visualizza il risultato.*/

#include <stdio.h>
#define MAXS 30

int str_cpm(char*, char*);

int main(){

	char s1[MAXS+1], s2[MAXS+1];
	int risultato;

	scanf("%s", s1);
	scanf("%s", s2);
	
	risultato = str_cpm(s1, s2);

	printf("%d\n", risultato);

	return 0;
}

int str_cpm(char *s1, char *s2){

	if(*s1=='\0' && *s2=='\0'){
		return 1;
	}

	if(*s1!=*s2){
		return 0;
	}

	return str_cpm(s1+1, s2+1);
}
