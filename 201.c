/*Con formato si intende una stringa che contiene soltanto tre possibili caratteri:
V che indica una vocale, C che indica una consonante e D che indica una cifra.

Scrivere un sottoprogramma check che ricevute due stringhe, stin e formato. Restituisce 1 se il contenuto della stringa
stin rispetta il format, altrimenti 0. I caratteri alfabetici della stringa stin sono esclusivamente minuscoli.

Per esempio, se il sottoprogramma riceve in ingresso:
stin: "check23"
formato: "CCVCCDD"
il sottoprogramma restituisce 1.

Scrivere un programma che acquisisce da riga di comando due stringhe e avvalendosi del sottoprogramma check
visualizza ok se la prima stringa rispetta il formato indicato dalla seconda stringa, ko in caso contrario.*/

#include <stdio.h>

int isnumero(char);
int isvocale(char);
int isconsonante(char);
int check(char[], char[]);

int main(int argc, char *argv[]){

	if(argc==3){
		if(check(argv[1], argv[2])){
			printf("ok\n");
		}else{
			printf("ko\n");
		}
	}else{
		printf("errore\n");
	}

	return 0;
}

int isnumero(char c){

	return c>='0' && c<='9';
}

int isvocale(char c){

	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int isconsonante(char c){

	return c>='a' && c<='z' && !isvocale(c);
}

int check(char stin[], char formato[]){

	int i, ok;

	for(i=0, ok=1; stin[i]!='\0' && formato[i]!='\0' && ok; i++){
		if(!((formato[i]=='V' && isvocale(stin[i])) || (formato[i]=='C' && isconsonante(stin[i])) || (formato[i]=='D' && isnumero(stin[i])))){
			ok = 0;
		}
	}

	return ok && stin[i]=='\0' && formato[i]=='\0';
}