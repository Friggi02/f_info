/*Scrivere un programma che riceve da riga di comando due valori interi e ne stampi la somma.

Esempio:
eseguo con: ./out 3 7
il programma stamperà: 10		*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int num1, num2;

	if(argc==3){
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		printf("%d\n", num1+num2);
	}else{
		printf("errore argomenti\n");
	}

	return 0;
}