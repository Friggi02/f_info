/*Scrivere un programma C che apre un file di testo il cui nome è passato come argomento da riga di comando e contenente parole ciascuna di al massimo 15 
caratteri, separate da spazi. Il programma trova tutte le parole più lunghe di 4 caratteri e ripetute due volte di seguito nel testo e le stampa a video.
Gestire opportunamente tutti gli eventuali errori.

Ad esempio, se il file "testo.txt" contiene il testo:
bisogna studiare passo passo e adagio adagio per ottenere un voto alto alto
Il programma visualizzerà in output:
passo adagio alto

Come test, forniamo i file testo1.txt, testo2.txt, testo3.txt, i cui output corrispondenti sono qui elencati:
testo1.txt -> passo adagio
testo2.txt -> quando occupato
testo3.txt -> quattro cinque sette
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXS 20

typedef struct testo_{
	char parola[MAXS+1];
	struct testo_ *next;
}testo_t;

testo_t* inserisciInCoda(testo_t*, char[]);
void visualizza(testo_t*);
testo_t* acquisisci(testo_t*, char[]);
testo_t* distruggi(testo_t*);
int str_compare(char s1[], char s2[]);
int contaOccorrenze(testo_t*, char[]);

int main(int argc, char *argv[]){

	testo_t *h;
	int n, len;

	h = NULL;

	if(argc==2){
		h = acquisisci(h, argv[1]);
		visualizza(h);
		printf("\n");
		for(; h; h=h->next){
			n = contaOccorrenze(h, h->parola);
			for(len=0; h->parola[len]!='\0'; len++);
			if(n>=2 && len>4){
				printf("%s ", h->parola);
			}
		}
		printf("\n");
		distruggi(h);
	}else{
		printf("errore argomenti\n");
	}

	return 0;
}


testo_t* inserisciInCoda(testo_t *l, char str[]){

	testo_t *prec, *tmp;
	int i;

	tmp = malloc(sizeof(testo_t));

	if(tmp){
		tmp->next = NULL;
		for(i=0; str[i]!='\0'; i++){
			tmp->parola[i] = str[i];
		}
		if(l==NULL){
			l = tmp;
		}else{
			for(prec=l; prec->next; prec=prec->next);
			prec->next = tmp;
		}
	}else{
		printf("memoria esaurita\n");
	}

	return l;
}

void visualizza(testo_t *l){

	for(; l; l=l->next){
		printf("%s ", l->parola);
	}
}

testo_t* acquisisci(testo_t *l, char filename[]){

	FILE* fp;
	char curr[MAXS+1];

	fp = fopen(filename, "r");
		if(fp){
			fscanf(fp, "%s", curr);
			while(!feof(fp)){
				l = inserisciInCoda(l, curr);
				fscanf(fp, "%s", curr);
			}
			fclose(fp);
		}else{
			printf("errore apertura file\n");
		}

	return l;
}

testo_t* distruggi(testo_t *l){
  
 	testo_t* tmp;
  
 	while(l!=NULL){
 	 	tmp = l;
 	 	l = l->next;
 	 	free(tmp);
 	}

 	return NULL;
}

int str_compare(char s1[MAXS+1], char s2[MAXS+1]){

	int i, uguali;

	for(i=0; s1[i]!='\0' && s2[i]!='\0' && s1[i]==s2[i]; i++);
	uguali = (s1[i]=='\0' && s2[i]=='\0');

	return uguali;
}

int contaOccorrenze(testo_t *l, char str[]){

	int count;

	for(count=0; l; l=l->next){
		if(str_compare(l->parola, str)){
			count++;
		}
	}

	return count;
}