/*Scrivere un programma che apre in scrittura un file binario "ciao.bin".
Il programma chiede all'utente quanti valori vuole acquisire da tastiera,
e poi procede con l'acquisizione da tastiera della serie di numeri ed il loro salvataggio nel file.*/

#include <stdio.h>
#define FN "output.bin"

int main(){
	
	FILE *fp;

	int quanti, n, i;

	fp = fopen(FN, "wb");
	if(fp){
		scanf("%d", &quanti);
		for(i=0; i<quanti; i++){
			scanf("%d", &n);
			fwrite(&n, sizeof(int), 1, fp);					//passo il puntatore alla cosa che voglio strivere, quanto occupa, quanti elementi voglio stampare, dove lo voglio stampare
		}
		fclose(fp);
	}else{
		printf("errore di apertura del file\n");
	}

	return 0;
}