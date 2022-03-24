/*Scrivere un programma che chiede all'utente 10 valori interi da 
salvare in un array. In seguito, il programma apre in scrittura un 
file binario "ciao.bin" e vi scrive il contenuto dell'array.*/

#include <stdio.h>
#define FN "output.bin"
#define DIM 10

int main(){
	
	FILE *fp;

	int a[DIM], i;

	for(i=0; i<DIM; i++){
		scanf("%d", &a[i]);
	}

	fp = fopen(FN, "wb");
	if(fp){
		fwrite(a, sizeof(int), DIM, fp);
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
	}

	return 0;
}