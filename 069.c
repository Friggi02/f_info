/*Scrivere un programma in C che chiede all'utente di inserire una stringa di massimo 100 caratteri. Il programma deve cercare tutte le 
sottostringhe palindrome contenute all'interno della stringa di lunghezza l che varia da 2 a n (dove n è la lunghezza della stringa 
stessa). Per ogni diversa lunghezza l, stampare le stringhe palindrome trovate ed il loro numero.*/

#include <stdio.h>
#define MAXS 100

 int main()
{
	char str[MAXS+1];
	int i, j, k, conto, ispal, len;

/*ACQUISIZIONE*/
	printf("inserire la stringa: ");
	scanf("%s", str);

/*CALCOLO LUNGHEZZA*/
	for(len=0; str[len]!='\0'; len++);

/*ELABORAZIONE*/
	for(i=2; i<=len; i++){
		printf("\nsottostringhe di lunghezza %d:\n", i);
		for(j=0, conto=0; j<=len-i; j++){
			for(k=0, ispal=1; k<i/2 && ispal; k++){
				if(str[j+k]!=str[j+i-1-k]){
					ispal=0;
				}
			}
			if(ispal){
				conto++;
				for(k=0; k<i; k++){
					printf("%c", str[j+k]);
				}
				printf("\n");
			}
		}
		printf("conteggio: %d\n", conto);
	}		
		
	return 0;
}