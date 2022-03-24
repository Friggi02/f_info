/*Scrivere un programma in C che acquisisce una stringa di al massimo 30 caratteri ed un numero n.
Il programma estrae il suffisso della stringa di lunghezza n salvandolo in un nuovo array e visualizza il risultato.
Se n è maggiore della lunghezza della stringa, il suffisso sarà rappresentato dalla stringa stessa.*/

#include <stdio.h>
#define MAXS 30

 int main()
{
	char s[MAXS+1], s1[MAXS+1];
	int i, n, len_s, len_s1;

/*ACQUISIZIONE*/
	scanf("%s", s);
	scanf("%d", &n);

/*CALCOLO LUNGHEZZA*/
	for(len_s=0; s[len_s]!='\0'; len_s++);

/*ELABORAZIONE*/
	if(n>=len_s){
		printf("%s\n", s);
	}else{
		for(i=len_s, len_s1=0; len_s-i!=n+1; i--){
			s1[len_s-i] = s[i];
			len_s1++;
		}
		s1[len_s1] = '\0';	
		for(i=0; i<len_s1; i++){
			s[len_s1-i-1] = s1[i];
		}
		s[len_s] = '\0';
		printf("%s\n", s);
	}

	return 0;
}