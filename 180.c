/*
Definire un nuovo tipo di dato per una lista concatenata che permetta di memorizzare un polinomio; ciascun nodo della lista memorizzerà un monomio in 
termini di due interi che rappresentano il grado e il coefficiente di un dato monomio.

Scrivere i seguenti sottoprogrammi:
1. inserisciInCoda riceve un polinomio e due interi rappresentanti il coefficiente e il grado del nuovo monomio da aggiungere. Il sottoprogramma restituisce il polinomio.
2. acquisisci acquisisce un polinomio fino all'inserimento dei valori 0 0 che non fanno parte del polinomio.
3. sistema riceve in ingresso un polinomio e lo restituisce eliminando i monomi di coefficiente nullo e unendo i monomi di pari grado.
4. visualizza stampa il polinomio sistemato che riceve in ingresso senza mostrare il coefficiente se pari a 1 e senza mostrare la x se di grado 0.
5. distruggi rilascia la memoria occupata dalla lista che riceve in ingresso

Scrivere un programma che chiede all'utente i dati di due polinomi. Il programma calcola la somma e il prodotto tra i due polinomi.
Il programma visualizza infine le quattro liste e, prima di terminare, rilascia tutta la memoria allocata.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct poli_{
	int coeff;
	int grado;
	struct poli_ *next;
}poli_t;

poli_t* inserisciInCoda(poli_t*, int, int);
poli_t* acquisisci();
poli_t* sistema(poli_t*);
void visualizza(poli_t*);
poli_t* sommaPoli(poli_t*, poli_t*);
poli_t* prodottoPoli(poli_t*, poli_t*);
void distruggi(poli_t*);

int main(){

	poli_t *h1, *h2, *somma, *prodotto;

	h1 = NULL;
	h2 = NULL;
	somma = NULL;
	prodotto = NULL;

	printf("\n***INSERISCI IL PRIMO POLINOMIO***");
	h1 = acquisisci();
	h1 = sistema(h1);
	printf("\n***INSERISCI IL SECONDO POLINOMIO***");
	h2 = acquisisci();
	h2 = sistema(h2);

	printf("\n***SOMMA***\n");
	somma = sommaPoli(h1, h2);
	visualizza(h1);
	printf(" + ");
	visualizza(h2);
	printf(" = ");
	visualizza(somma);
	printf("\n");

	printf("\n***PRODOTTO***\n");
	prodotto = prodottoPoli(h1, h2);
	visualizza(h1);
	printf(" * ");
	visualizza(h2);
	printf(" = ");
	visualizza(prodotto);
	printf("\n");

	distruggi(h1);
	distruggi(h2);
	distruggi(somma);
	distruggi(prodotto);

	return 0; 
}

poli_t* inserisciInCoda(poli_t *l, int coeff, int grado){

	poli_t *prec, *tmp;

	tmp = malloc(sizeof(poli_t));

	if(tmp){
		tmp->next = NULL;
		tmp->coeff = coeff;
		tmp->grado = grado;
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

poli_t* acquisisci(){

	poli_t *l;
	int grado, coeff;

	l = NULL;

	
	printf("\ninserisci coefficiente: ");
	scanf("%d", &coeff);
	printf("inserisci grado: ");
	scanf("%d", &grado);

	while(!(coeff==0 && grado==0)){
		l = inserisciInCoda(l, coeff, grado);
		printf("\ninserisci coefficiente: ");
		scanf("%d", &coeff);
		printf("inserisci grado: ");
		scanf("%d", &grado);
	}

	return l;
}

poli_t* sistema(poli_t *l){

	poli_t *tmp1, *tmp2, *risultato;
	int ok;

	tmp1 = NULL;
	tmp2 = NULL;
	risultato = NULL;

	for(tmp1=l; tmp1; tmp1=tmp1->next){
		if(tmp1->coeff!=0){
			for(tmp2=risultato, ok=1; tmp2 && ok; tmp2=tmp2->next){
				if(tmp1->grado==tmp2->grado){
					tmp2->coeff += tmp1->coeff;
					ok = 0;
				}
			}
			if(ok){
				risultato = inserisciInCoda(risultato, tmp1->coeff, tmp1->grado);
			}
		}
	}

	return risultato;
}

void visualizza(poli_t *l){

	printf("[");

	/*stampo il primo monomio senza il +*/
	if(l){
		if(l->coeff==-1){
			printf("(-");
		}else if(l->coeff!=1){
			printf("(%d", l->coeff);
		}else{
			printf("(");
		}
		if(l->grado==1){
			printf("x)");
		}else if(l->grado!=0){
			printf("x^%d)", l->grado);
		}
		else{
			printf(")");
		}
		l = l->next;
	}

	/*stampo il resto del polinomio*/
	while(l){
		if(l->coeff==-1){
			printf("+(-");
		}else if(l->coeff!=1){
			printf("+(%d", l->coeff);
		}else{
			printf("+(");
		}
		if(l->grado==1){
			printf("x)");
		}else if(l->grado!=0){
			printf("x^%d)", l->grado);
		}
		else{
			printf(")");
		}
		l = l->next;
	}
	printf("]");
}

void distruggi(poli_t *l){

 	poli_t* tmp;

 	while(l){
    	tmp = l;
    	l = l->next;
    	free(tmp);
 	}
}

poli_t* sommaPoli(poli_t *h1, poli_t *h2){

	poli_t *risultato;
	
	risultato = NULL;

	for(; h1; h1=h1->next){
		risultato = inserisciInCoda(risultato, h1->coeff, h1->grado);
	}

	for(; h2; h2=h2->next){
		risultato = inserisciInCoda(risultato, h2->coeff, h2->grado);
	}

	risultato = sistema(risultato);

	return risultato;
}

poli_t* prodottoPoli(poli_t *h1, poli_t *h2){

	poli_t *risultato, *tmp1, *tmp2;

	risultato = NULL;
	tmp1 = NULL;
	tmp2 = NULL;
	
	for(tmp1=h1; tmp1; tmp1=tmp1->next){
		for(tmp2=h2; tmp2; tmp2=tmp2->next){
			risultato = inserisciInCoda(risultato, tmp1->coeff*tmp2->coeff, tmp1->grado+tmp2->grado);
		}
	}
	
	risultato = sistema(risultato);

	return risultato;
}

