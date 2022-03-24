/*Scrivere un programma che trova e visualizza tutti i vocaboli di un dizionario (file di testo ASCII dizionario.txt) in cui tutte le vocali presenti compaiono in 
ordine lessicografico crescente. Non è necessario che compaiano tutte le vocali e la stessa vocale può comparire più volte. Nel file, ogni vocabolo compare su una 
riga nuova, ed ogni vocabolo è al più lungo 35 caratteri (e ovviamente contiene almeno una vocale). I caratteri sono tutti minuscoli e non accentati. Per esempio, 
i vocaboli alta, arte vengono visualizzati, il vocabolo idea no.*/

#include <stdio.h>

#define FILENAME "dizionario.txt"
#define MAXS 35

int vocale(char);

int main(){

	FILE *fp;
	char vocabolo[MAXS+1], vocale_prec;
	int i, ok;

	fp = fopen(FILENAME, "r");

	if(fp){
		fscanf(fp, "%s", vocabolo);
		while(!feof(fp)){
			for(i=0, ok=1, vocale_prec='a'; vocabolo[i]!='\0' && ok; i++){
				if(vocale(vocabolo[i])){
					if(vocale_prec>vocabolo[i]){
						ok = 0;
					}else{	
						vocale_prec = vocabolo[i];
					}
				}
			}
			if(ok){
				printf("%s\n", vocabolo);
			}
			fscanf(fp, "%s", vocabolo);
		}
		fclose(fp);
	}else{
		printf("errore apertura file\n");
	}
	
	return 0;
}

int vocale(char c){
	
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
