/*Scrivere un programma che chiede all'utente una stringa di al massimo 30 caratteri che rappresenta il nome di un file binario.
Il programma apre il file e verifica se è vuoto o meno stampando a video il responso.
Visualizzare un messaggio per eventuali errori di apertura del file.*/

#include <stdio.h>
#define MAXS 30

int main(){

	FILE *fp;
	char a;
	char fn[MAXS+1];

	printf("nume file: ");
	scanf("%s", fn);

	fp = fopen(fn, "rb");

	if(fp){
		fread(&a, sizeof(char), 1, fp);
		if(!feof(fp)){
			printf("file non vuoto\n");
		}else{
			printf("file vuoto\n");
		}
		fclose(fp);
	}else{
		printf("errore apertura file\n");
	}

	return 0;
}