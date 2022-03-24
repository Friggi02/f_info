/*Scrivere un programma in C che acquisisce due stringhe di al più 30
caratteri e le concatena in un terzo array e visualizza il risultato.*/

#include <stdio.h>
#define MAXS 30

int main(){
	
	char s1[MAXS+1], s2[MAXS+1], s3[MAXS*2+1];
	int i, l1;

	scanf("%s %s", s1, s2);

	for(i=0; s1[i]!='\0'; i++){
		s3[i] = s1[i];
	}

	for(l1=i, i=0; s2[i]!='\0'; i++){
		s3[l1+i] = s2[i];
	}

	s3[l1+i] = '\0';

	printf("%s\n", s3);	

	return 0;
}