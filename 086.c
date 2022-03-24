/*Il cifrario di Cesare è uno dei più antichi algoritmi crittografici di cui si abbia traccia storica. È un cifrario a sostituzione 
monoalfabetica in cui ogni lettera del testo in chiaro è sostituita nel testo cifrato dalla lettera che si trova un certo numero di 
posizioni dopo nell'alfabeto. Cesare utilizzava uno spostamento di 3 posizioni:
Cifratura: A->D, B->E, ..., X->A, Y->B, Z->C
Decifratura: D->A, E->B, ..., 

Scrivere un sottoprogramma cifra() che riceve come parametro un carattere
minuscolo dell'alfabeto inglese e restituisce il carattere minuscolo cifrato.

Scrivere un sottoprogramma decifra() che riceve come parametro un carattere minuscolo dell'alfabeto
inglese già cifrato e restituisce il corrispondente carattere minuscolo non cifrato.

Scrivere un sottoprogramma verificalettera() che riceve come parametro un carattere e
restituisce 1 se tale carattere è una lettera dell'alfabeto minuscolo, altrimenti 0.

Scrivere un programma che acquisisce una stringa di testo di al massimo 20 caratteri, che si assume contenga soltanto lettere 
minuscole dell'alfabeto, cifre ed altri segni di interpunzione e non lettere maiuscole. Mediante l'ausilio dei sottoprogrammi sopra 
definiti, il programma cifra il messaggio salvandolo in un secondo array e lo stampa a video; in seguito, il programma decifra il 
messaggio cifrato, lo stampa a video e verifica che effettivamente è uguale al messaggio originale, visualizzando l'esito del confronto.*/

#include <stdio.h>
#define PASSO 3
#define MAXS 20

char cifra(char);
char decifra(char);
int verificalettera(char);

int main(){

	char input[MAXS+1], output[MAXS+1], controllo[MAXS+1];
	int ok, i;

/*ACQUISIZIONE E CONTROLLO*/
	do{
		printf("stringa da cifrare: ");
		scanf("%s", input);
		for(i=0, ok=1; input[i]!='\0' && ok; i++){
			ok = verificalettera(input[i]);
		}
	}while(!ok);

/*CIFRATURA*/
	for(i=0; input[i]!='\0'; i++){
		output[i] = cifra(input[i]);
	}
	output[i] = '\0';
	printf("stringa cifrata: %s\n", output);

/*DECIFRATURA*/
	for(i=0; output[i]!='\0'; i++){
		controllo[i] = decifra(output[i]);
	}
	controllo[i] = '\0';
	printf("stringa decifrata: %s\n", controllo);

/*CONTROLLO*/
	for(i=0; input[i]!='\0' && controllo[i]!='\0' && input[i]==controllo[i]; i++);
	ok = (input[i]=='\0' && controllo[i]=='\0');
	printf("esito: %d\n", ok);

	return 0;
}

char cifra(char c){

	c = (c-'a'+PASSO)%('z'-'a'+1)+'a';

	return c;
}

char decifra(char c){

	c = (c-'a'+('z'-'a'+1)-PASSO)%('z'-'a'+1)+'a';

	return c;
}

int verificalettera(char c){

	int output;

	if(c>='a' && c<='z'){
		output = 1;
	}else{
		output = 0;
	}

	return output;
}