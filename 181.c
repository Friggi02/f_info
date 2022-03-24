/*
Definire un tipo di dato per una lista dinamica di parole, dove ciascuna parola è lunga al massimo 20 caratteri. Realizzare i sottoprogrammi standard per la gestione
di una lista di parole, in particolare per l'inserimento in coda di un nuovo elemento, la visualizzazione del contenuto della lista, il calcolo della lunghezza della lista e la sua distruzione.

Scrivere un programma che riceve come argomenti i nomi di due file di testo, ciascuno contenente una sequenza di lunghezza indefinita di parole di al massimo 20
caratteri. Il programma carica le due sequenze in due liste dinamiche s1 e s2. In seguito, il sottoprogramma verifica se s1 è sottosequenza di s2 o, viceversa se s2 
è sottosequenza di s1, e stampa a video i risultati dei test (1 o 0); si noti che se almeno una delle due liste è vuota l'esito è negativo. Prima di terminare il 
programma libera tutta la memoria allocata. Visualizzare opportuni messaggi nel caso di errore (es: argomenti mancanti, memoria non allocata correttamente, file 
non aperto, ...). Si consiglia di suddividere opportunamente il programma in sottoprogrammi.
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
int lunghezza(testo_t*);
int check(testo_t*, testo_t*);
int str_compare(char s1[], char s2[]);

int main(int argc, char *argv[]){

	testo_t *s1, *s2;
	int esito;

	s1 = NULL;
	s2 = NULL;

	if(argc==3){
		s1 = acquisisci(s1, argv[1]);
		s2 = acquisisci(s2, argv[2]);
	}else{
		printf("errore argomenti\n");
	}

	visualizza(s1);
	printf("\n");
	printf("len 1: %d\n", lunghezza(s1));
	visualizza(s2);
	printf("\n");
	printf("len 2: %d\n", lunghezza(s2));

	printf("\n");
	printf("%d\n", check(s1, s2));

	distruggi(s1);
	distruggi(s2);

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
  
 	while(l!= NULL){
 	 	tmp = l;
 	 	l = l->next;
 	 	free(tmp);
 	}

 	return NULL;
}

int lunghezza(testo_t *l){
 	int i;

 	for(i=0; l; i++, l=l->next);
 	
 	return i;
}

int check(testo_t *s1, testo_t *s2){

	int conto, len_s1, len_s2, trovato;
	testo_t *tmp1, *tmp2;

	len_s1 = lunghezza(s1);
	len_s2 = lunghezza(s2);

	if(len_s1=0 || len_s2==0){
		conto = 0;
	}else{
		if(len_s1>len_s2){
		
		}else{
			for(tmp1=s1; tmp1; tmp1=tmp1->next){
				for(tmp2=s2, trovato=0; tmp2 && !trovato; tmp2=tmp2->next){
					if(!str_compare(tmp1->parola, tmp2->parola)){
						trovato = 1;
					}
				}
			}
		}
	}

	return conto;
}

int str_compare(char s1[MAXS+1], char s2[MAXS+1]){

	int i, uguali;

	for(i=0; s1[i]!='\0' && s2[i]!='\0' && s1[i]==s2[i]; i++);
	uguali = (s1[i]=='\0' && s2[i]=='\0');

	return uguali;
}