/*Scrivere un programma in C che chiede all'utente due stringhe s e t di al massimo 30 caratteri. Il programma conta
quante volte la stringa t compare come sottostringa all'interno della stringa s e stampa a video il risultato.*/

#include <stdio.h>
#define MAXS 30

 int main()
{

	char s[MAXS + 1], t[MAXS + 1]; 
	int len_s, len_t, i, j, ripetizioni;
	
	printf ("Inserisci stringa principale: ");
	scanf("%s", s);
	for(len_s=0; s[len_s]!='\0'; len_s++);
	
	printf ("Inserisci sotto-stringa: ");
	scanf("%s", t);
	for(len_t=0; t[len_t]!='\0'; len_t++);

	for(i=0, ripetizioni=0; i<=len_s-len_t; i++){			
		for(j=0; j<len_t && s[i+j]==t[j]; j++);
		if(j==len_t){
			ripetizioni++;
		}
	}
	printf("%d\n", ripetizioni);

	return 0;
}