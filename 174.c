/*
Scrivere un sottoprogramma minmaxstr che riceve in ingresso una stringa e trasmette al chiamante due caratteri, il minimo e il massimo
nell’ordinamento alfabetico tra quelli contenuti nella stringa. Per esempio, se la stringa in ingresso è “esempio”, il minimo ed il massimo
sono rispettivamente e ed s. Scrivere il sottoprogramma minmaxstr in modo tale che i caratteri possano essere sia maiuscoli, sia minuscoli,
e facendo in modo che il sottoprogramma trasmetta comunque quelli minuscoli. In tal caso, se la stringa in ingresso è “Architetto”,
il minimo ed il massimo sonorispettivamente a ed t.

Scrivere un programma che acquisisce da riga di comando una stringa e chiama il sottoprogramma minmaxstr.	*/

#include <stdio.h>
#include <stdlib.h>
#define MAXS 30

char tolow(char c);
void minmaxstr(char *str, char *min, char *max);

int main(int argc, char **argv){

	char min, max, *str;

	
	
	if(argc==2){
		argv++;
		str = *(argv++);
		minmaxstr(str, &min, &max);
		printf("%c %c\n", min, max);
	}else{
		printf("errore\n");
	}
	
	return 0;
}

char tolow(char c){
	if(c>='A' && c<='Z'){
		c = c-'A'+'a';
	}

	return c;
}

void minmaxstr(char *str, char *min, char *max){

	int i;
	char c;

	c = tolow(str[0]);
	*min = c;
	*max = c;

	for(i=0; str[i]!='\0'; i++){
		c = tolow(str[i]);
		if(*min>c){
			*min = c;
		}else if(*max<c){
			*max = c;
		}
	}
}

