/*Definire un tipo di dato opportuno clist_t per realizzare una lista dinamica che gestisce caratteri (ogni elemento un carattere) che serve 
per gestire sequenze di caratteri. Si definisce sottosequenza una sequenza di caratteri compresa tra una parentesi tonda iniziale (e 
una finale). Le sottosequenze possono anche essere vuote (parentesi aperta e poi chiusa senza altri caratteri intermedi).

Scrivere un sottoprogramma riceve in ingresso una lista che costituisce una sequenza e la restituisce dopo aver
sostituito le sottosequenze con il carattere #.

La sequenza dei caratteri in ingresso è ben formata se: 
1. per ogni parentesi tonda che si apre, c'è una parentesi tonda che si chiude, 
2. non ci sono intersezioni tra coppie di parentesi. 

Per esempio, ab(acg)be()a(xx)f è una sequenza ben formata, ab(a(c)g)b e aba(c)g)b non lo sono.

Se il sottoprogramma riceve in ingresso la sequenza 
ab(acg)be()a(xx)f(a)
restituisce la sequenza
ab(#)be(#)a(#)f(#)				*/

#include <stdio.h>
#include <stdlib.h>

#define MAXS 30

typedef struct clist_{
	char carattere;
	struct clist_ *next;
}clist_t;

clist_t* inserisciInCoda(clist_t*, char);
void visualizza(clist_t*);
clist_t* distruggi(clist_t*);
clist_t* eliminaParentesi(clist_t*);

int main(){

	clist_t *h;
	char str[MAXS+1];
	int i;

	h = NULL;

	scanf("%s", str);

	for(i=0; str[i]!='\0'; i++){
		h = inserisciInCoda(h, str[i]);
	}

	h = eliminaParentesi(h);

	visualizza(h);
	printf("\n");

	distruggi(h);

	return 0;
}

clist_t* inserisciInCoda(clist_t *l, char c){

	clist_t *prec, *tmp;
	int i;

	tmp = malloc(sizeof(clist_t));

	if(tmp){
		tmp->next = NULL;
		tmp->carattere = c;
		
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

void visualizza(clist_t *l){

	for(; l; l=l->next){
		printf("%c", l->carattere);
	}
}

clist_t* distruggi(clist_t *l){
  
 	clist_t* tmp;
  
 	while(l!= NULL){
 	 	tmp = l;
 	 	l = l->next;
 	 	free(tmp);
 	}

 	return NULL;
}

clist_t* cancellaTesta(clist_t *l){

	clist_t *tmp;

	if(l){
		tmp = l;
		l = l->next;
		free(tmp);
	}

	return l;
}

clist_t* inserisciInTesta(clist_t *l, char c){

	clist_t *tmp;

	tmp = (clist_t*)malloc(sizeof(clist_t));

	if(tmp){
		tmp->carattere = c;
		tmp->next = l;
		l = tmp;
	}else{
		printf("errore di allocazione\n");
	}

	return l;
}

clist_t* eliminaParentesi(clist_t *l){

	clist_t *curr;

	curr = l;

	while(curr){
		if(curr->carattere=='('){
			while(curr->next->carattere!=')'){
				curr->next = cancellaTesta(curr->next);
			}
			curr->next = inserisciInTesta(curr->next, '#');
			curr = curr->next->next;
		}else{
			curr = curr->next;
		}
	}

	return l;
}