/*
Scrivere un sottoprogramma convertinumero che riceve come parametro una stringa str e due parametri interi num e valido 
passati per indirizzo in cui salvare i risultati. Se str è composta soltanto da cifre (char da '0' a '9'), il sottoprogramma converte la 
stringa in un numero, la salva in num ed assegna 1 al parametro valido. Altrimenti il sottoprogramma assegna 0 a valido e non 
modifica num. NOTA: è vietato l'utilizzo di funzioni di conversione quali atoi o sscanf.

Scrivere un programma che apre un file di testo testo.txt contenente una serie di lunghezza indefinita di parole ciascuna 
lunga al massimo 15 caratteri. Il programma legge ciascuna parola contenuta nel file e, mediante il sottoprogramma convertinumero, 
verifica se si tratta di una stringa composta solo da cifre e in caso affermativo la converte in un numero. Il programma somma tutti 
i numeri identificati e presenta a video il risultato finale.

Ad esempio, se il file contiene il seguente testo: Ciao domani 120 10 alfa23 esame 5 informatica 34tre -34
Il programma stamperà a video il seguente messaggio: 135	*/

#include <stdio.h>
#define MAXS 15
#define FILENAME "output.txt"

void converti_numero(char [], int*, int*);

int main (){

	FILE *fp;
	char str[MAXS+1];
	int num, valido, somma;

	fp = fopen(FILENAME, "r");
	if(fp){
		fscanf(fp, "%s", str);
		somma = 0;
		while(!feof(fp)){
			converti_numero(str, &num, &valido);
			if(valido){
				somma += num;
			}
			fscanf(fp, "%s", str);
		}
		printf("%d\n", somma);
		fclose(fp);
	}else{
		printf("errore nell'apertura del file\n");
	}
	
	return 0;
}

void converti_numero(char str[], int *num, int *valido){

	int tmp, i;

	for(i=0, *valido=1, tmp=0; str[i]!='\0' && *valido; i++){
		if(str[i]>='0' && str[i]<='9'){
			tmp = tmp*10+(str[i]-'0');
		}else{
			*valido = 0;
		}
	}
	if(*valido){
		*num = tmp;
	}
}
