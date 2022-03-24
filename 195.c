/*Scrivere un sottoprogramma rep che riceve in ingresso una stringa s e un intero n (senz'altro non negativo). Il sottoprogramma restituisce una nuova stringa ottenuta
concatenando n copie di s. Ad esempio, se il sottoprogramma riceve in ingresso "esempio" e 3 restituisce la nuova "esempioesempioesempio", se riceve "esempio" e 0
restituisce una stringa vuota. Non è consentito l'uso dei sottoprogrammi di libreria quali strcat(), strcpy() e simili.

Scrivere il programma che acquisisce da riga di comando la stringa s e l'intero n, invoca il sottoprogramma sopra definito e visualizza il risultato.*/

#include <stdio.h>
#include <stdlib.h>
#define MAXS 30

char *rep(char[], int);

int main(int argc, char* argv[]){

	char *str;


	if(argc==3){
		str = rep(argv[1], atoi(argv[2]));
		if(str){
			printf("%s\n", str);
			free(str);
		}
	}else{
		printf("errore argomenti\n");
	}
	
	return 0;
}


char *rep(char s[], int n){

	char *sr;
	int len, i, j;

	for(len=0; s[len]!='\0'; len++);

	sr = malloc(sizeof(char)*len*n+1);

	if(sr){
		for(i=0; i<n; i++){
			for(j=0; s[j]!='\0'; j++){
				sr[i*len+j]=s[j];
			}
		}
		sr[i*len] = '\0';
	}else{
		printf("errore di allocazione\n");
	}

	return sr;
}
