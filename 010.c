/*Scrivere un programma in C che chiede all'utente un carattere. Il programma verifica se il carattere sia una lettera dell'alfabeto.
In caso positivo, se la lettera è minuscola, il programma la converte nella corrispondente maiuscola,
altrimenti la converte nella corrispondente minuscola, visualizzando infine il risultato.
In caso il carattere non sia una lettera il programma visualizza un apposito messaggio di errore.*/


#include <stdio.h>

int main(){

	char in, out;

	printf("inserire carattere: ");
	scanf("%c", &in);

	if (in>='a' && in<='z'){
		out = in + ('A'-'a');
		printf("%c\n", out);
	}else if (in>='A' && in<='Z'){
		out = in - ('A'-'a');
		printf("%c\n", out);
	}else{
		printf("errore\n");
	}

	return 0;
}