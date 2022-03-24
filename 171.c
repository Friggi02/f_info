#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

typedef struct nodo_compatto_{
  int n, volte;
  struct nodo_compatto_ *next;
} nodo_compatto_t;

int lunghezza_ric(nodo_t *h);
int esisteElemento_ric(nodo_t *h, int n);
nodo_t* inserisciInCoda_ric(nodo_t *h, int n);
nodo_t* rimuovi_ric(nodo_t *h, int n);
nodo_t* inserisciInOrdine_ric(nodo_t *h, int n);
void scriviFile(char *filename, nodo_t *l);
nodo_t* leggiFile(char *filename, nodo_t *l);
nodo_t* listaMedie(nodo_t *l1);
nodo_t* invertiCoppie(nodo_t *l1);
void dividiPosNeg(nodo_t *l1, nodo_t **lp, nodo_t **ln);
nodo_t* alternaElementi(nodo_t *l1, nodo_t *l2);
nodo_compatto_t* compattaLista(nodo_t *h);

int main(){

	return 0;
}



/*Scrivere un sottoprogramma che riceve una testa di una lista dinamica di interi e ne restituisce la lunghezza. Versione ricorsiva.*/
int lunghezza_ric(nodo_t *h){

	if(h==NULL){
		return 0;
	}

	return 1+lunghezza_ric(h->next);
}

/*Scrivere un sottoprogramma che riceve una testa di una lista dinamica di interi ed un intero. Il sottoprogramma restituisce 1 se
il numero è presente nella lista altrimenti 0. Versione ricorsiva.*/
int esisteElemento_ric(nodo_t *h, int n){

	if(!h || h->num==n){
		return h != NULL;
	}

	return esisteElemento_ric(h->next, n);
}

/*Scrivere un sottoprogramma che riceve una testa di una lista dinamica di interi ed un intero. Il sottoprogramma inserisce in coda
il numero ricevuto come parametro e restituisce la testa della lista. Versione ricorsiva.*/
nodo_t* inserisciInCoda_ric(nodo_t *h, int n){

	if(!h){
		return inserisciInTesta(h, n);
	}

	h->next = inserisciInCoda_ric(h->next, n);
	return h;
}

/*Scrivere un sottoprogramma che riceve una testa di una lista dinamica di interi ed un intero. Il sottoprogramma rimuove dalla
lista la prima occorrenza di un numero specificato come parametro, se presente. Versione ricorsiva.*/
nodo_t* rimuovi_ric(nodo_t *h, int n){

	nodo_t *tmp;

	if(!h){
		return NULL;
	}
	if(h->num==n){
		tmp = h;
		h = h->next;
		free(tmp);
		return h;
	}
	h->next = rimuovi_ric(h->next, n);

	return h;
}

/*Scrivere un sottoprogramma che riceve come parametri una lista dinamica di interi ordinata in ordine crescente ed un valore intero. 
Il sottoprogramma inserisce il nuovo elemento nella lista preservando l'ordine crescente e restituisce la testa della lista al 
chiamante. Versione ricorsiva.*/
nodo_t* inserisciInOrdine_ric(nodo_t *h, int n){

	if(!h || n<=h->num){
		return inserisciInTesta(h, n);
	}else{


	h = inserisciInOrdine_ric(h->next, n);
	}

	return h;
}

/*Scrivere un sottoprogramma che riceve come parametri una lista di interi ed una stringa che rappresenta il nome di un file. Il 
sottoprogramma apre in scrittura il file binario il cui nome è stato ricevuto come parametro e vi salva il contenuto della lista.*/
void scriviFile(char *filename, nodo_t *l){

	FILE* fp;

	fp=fopen(filename, "wb");
	if(fp){
		while(l){
			fwrite(&(l->num), sizeof(int), 1, fp);
			l = l->next;
		}
		fclose(fp);
	}else{
		printf("errore apertura file\n");
	}
}

/*Scrivere un sottoprogramma che riceve come parametro una stringa che rappresenta il nome di un file che contiene una sequenza di 
lunghezza indefinita di numeri interi. Il sottoprogramma apre in lettura il file binario e crea una nuova lista dinamica popolandola 
con il contenuto del file. Il sottoprogramma restituisce infine la testa della nuova lista creata.*/
nodo_t* leggiFile(char *filename, nodo_t *l){

	FILE* fp;
	int num;
	nodo_t *h;

	h = NULL;

	fp=fopen(filename, "rb");
	if(fp){
		fread(&num, sizeof(int), 1, fp);
		while(!feof(fp)){
			l = inserisciInCoda(h, num);
			fread(&num, sizeof(int), 1, fp);
		}
		fclose(fp);
	}else{
		printf("errore apertura file\n");
	}

	return h;
}

/*Utilizzando la definizione di tipo lista e i sottoprogrammi visti a lezione, scrivere un sottoprogramma listaMedie() che riceve in 
ingresso una lista l1 di numeri interi. Il sottoprogramma costruisce una nuova lista l2 in cui ogni elemento è calcolato come la media 
tra un valore di l1 ed il suo successivo. L'ultimo elemento della lista, per cui non esiste un elemento successivo, viene ricopiato 
nella nuova lista. Infine il sottoprogramma restituisce la nuova lista.
Esempio: se l1 = 8 5 16 7 allora la nuova lista sarà: 6 10 11 7*/
nodo_t* listaMedie(nodo_t *l1){

	nodo_t *l2, *curr, *prec;

	l2 = NULL;

	if(l1){
		prec = l1;
		curr = l1->next;
		while(curr){
			l2 = inserisciInCoda(l2, (prec->num+curr->num)/2);
			prec = curr;
			curr = curr->next;
		}
		l2 = inserisciInCoda(l2, prec->num); //potrebbe esserci next al posto di num
	}

	return l2;
}

/*Utilizzando la definizione di tipo lista e i sottoprogrammi visti a lezione, scrivere un sottoprogramma che riceve una lista dinamica di 
numeri l1 e da questa costruisce una nuova lista l2 come segue: gli elementi di l1 vengono presi a coppie e viene inserito prima il 
secondo elemento della coppia e poi il primo. Nel caso la lista l1 contenga un numero dispari di elementi, l'ultimo elemento viene 
semplicemente copiato alla fine di l2. Esempio:
l1 = 1 2 3 4 5 6 7
l2 = 2 1 4 3 6 5 7    */
nodo_t* invertiCoppie(nodo_t *l1){

	nodo_t *prec, *curr, *l2;
	l2 = NULL;

	if(l1){
		prec = l1;
		curr = l1->next;
		while(curr){
			l2 = inserisciInCoda(l2, curr->num);
			l2 = inserisciInCoda(l2, prec->num);
			prec = curr->next;
			if(prec){
				curr = prec->next;
			}else{
				curr = NULL;
			}
		}
		if(!curr && prec){
			l2 = inserisciInCoda(l2, prec->num);
		}
	}

	return l2;
}

/*Utilizzando la definizione di tipo lista e i sottoprogrammi visti a lezione, scrivere un sottoprogramma che riceve come parametro una 
lista l1 contenente una serie di numeri interi e due puntatori a lista lp e ln passati per indirizzo e che non puntano ad alcun 
indirizzo valido. Il sottoprogramma costruisce due nuove liste, assegnandole a lp e ln, la prima contenente i soli elementi positivi 
di l1 e la seconda i restanti elementi neutri o negativi. La funzione restituisce entrambe le liste al chiamante.*/
void dividiPosNeg(nodo_t *l1, nodo_t **lp, nodo_t **ln){

	*lp = NULL;
	*ln = NULL;

	while(l1){
		if(l1->num <= 0)
			*ln = inserisciInCoda(*ln, l1->num);
		else
			*lp = inserisciInCoda(*lp, l1->num);
		l1 = l1->next;
	}
}

/*Utilizzando la definizione di tipo lista e i sottoprogrammi visti a lezione, scrivere un sottoprogramma che ricevute in ingresso due 
liste, ne restituisce una nuova creata alternando gli elementi delle due liste, e poi mettendo in coda tutti quelli della lista più 
lunga. Ad esempio, se le liste in ingresso sono fatte come segue,
1 3 5 7 9 11 
2 4 6 8
la lista creata sarà fatta come segue
1 2 3 4 5 6 7 8 9 11	*/
nodo_t* alternaElementi(nodo_t *l1, nodo_t *l2){

	nodo_t *h;
	int i;
	h = NULL;

	if(l1 && l2){
		h = l1;
		l1 = l1->next;
		for(i=1; l1 && l2; i++){
			if(i%2){
				h = inserisciInCoda(h, l2->num);
				l2 = l2->next;
			}else{
				h = inserisciInCoda(h, l1->num);
				l1 = l1->next;
			}
		}

		if(!l1 && l2){
			while(l2){
				h = inserisciInCoda(h, l2->num);
				l2 = l2->next;
			}
		}else if(l1 && !l2){
			while(l1){
				h = inserisciInCoda(h, l1->num);
				l1 = l1->next;
			}
		}
	}else if(l1){
		h = l1;
	}else if(l2){
		h = l1;
	}

	return h;
}

/*Definire un nuovo tipo di dato per lista dinamica chiamata nodo_compatto_t e contenente, oltre al puntatore next, due campi 
chiamati n e volte; il primo campo indica l'effettivo valore memorizzato nel nodo mentre il secondo quante volte compare quel 
valore. Scrivere un sottoprogramma che riceve come parametro una classica lista dinamica di interi e costruisce la corrispondente
lista compatta. Se per esempio la lista in ingresso è: 4 2 3 2 2 4, la lista compatta sarà: (4,2) (2, 3) (3, 1). Infatti il valore
4 compare due volte nella lista di partenza, il valore 2 tre volte e il valore 3 una volta.*/
/*typedef in cima*/
nodo_compatto_t* compattaLista(nodo_t *h){

	nodo_compatto_t *l2, *tmp, *curr, *prec;
	int found;

	l2 = NULL;

	for(; h; h=h->next){
		for(curr=l2, found=0; curr && !found; curr=curr->next){
			if(curr->n==h->num){
				(curr->volte)++;
				found = 1;
			}
		}
		if(!found){	
			tmp = malloc(sizeof(nodo_compatto_t));
			if(tmp){
				tmp->n = h->num;
				tmp->volte = 1;
				tmp->next = NULL;
				if(l2){
					for(prec=l2; prec->next; prec=prec->next);
					prec->next = tmp;
				}else{
					l2 = tmp;
				}
			}else{
				printf("errore di allocazione\n");
				//dovrei distruggere la lista l2
			}
		}
	}

	return l2;
}
