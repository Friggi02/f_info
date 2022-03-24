/*Scrivere un programma in C che chiede all'utente una stringa di massimo 50 caratteri che rappresenta il percorso completo di un 
file. Il programma salva in una nuova stringa il solo nome del file specificato nel percorso e lo visualizza.

Esempio: dal path "/home/antonio/ciao.c" il programma stampa a video "ciao.c"			*/

#include <stdio.h>
#define MAXS 50

int main(){

	char s[MAXS+1], s1[MAXS+1];
	int i, len_s, len_s1;

/*ACQUISIZIONE*/
	scanf("%s", s);

/*CALCOLO LUNGHEZZA*/
	for(len_s=0; s[len_s]!='\0'; len_s++);

/*COPIO CARATTERE PER CARATTERE DAL FONDO FINO AL PRIMO SLASH*/
	for(i=len_s, len_s1=0; i>0 && s[i]!='/'; i--){
		s1[len_s-i] = s[i];
		len_s1++;
	}
	s1[len_s1] = '\0';

/*RADDRIZZO LA STRINGA*/
	for(i=0; i<len_s1; i++){
		s[len_s1-i-1] = s1[i];
	}
	s[len_s] = '\0';

/*VISUALIZZAZIONE*/
	printf("%s\n", s);	

	return 0;
}