/*
-Definire un tipo di dato intervallo_t per descrivere un intervallo su un asse temporale in termini di inizio e fine (due numeri interi). 
-Scrivere un sottoprogramma che chiede i dati di un intervallo. Se l'utente specifica un valore di inizio maggiore del valore di fine, 
 il sottoprogramma inverte i due valori per salvarli correttamente in una variabile di tipo intervallo_t che restituisce al chiamante.
-Scrivere un sottoprogramma che riceve come parametri due intervalli ed un parametro formale intero, detto "sovrapposti", passato per 
 indirizzo. Il sottoprogramma verifica se i due intervalli sono sovrapposti ed in caso affermativo assegna 1 a sovrapposti e calcola 
 e restituisce l'intervallo sovrapposto; in alternativa assegna 0 a sovrapposti e restituisce l'intervallo di estremi 0, 0.
-Scrivere un sottoprogramma che riceve come parametro un intervallo e restituisce la sua lunghezza
-Scrivere un sottoprogramma che riceve come parametro un intervallo e lo stampa a video.
-Scrivere un programma che mediante l'ausilio dei tre sottoprogramma definiti acquisisce due intervalli e valuta se sono sovrapposti; in 
 caso affermativo visualizza l'intervallo sovrapposto e la sua lunghezza. In alternativa mostra un messaggio "non sovrapposti".
Esempio: se l'utente inserisce gli intervalli -2 5 e 1 10, l'intersezione sarà 1 5 ed avrà lunghezza 4.
*/

#include <stdio.h>

typedef struct{
	int inizio, fine;
} intervallo_t;

void swap(int*, int*);
intervallo_t acquisisci();
intervallo_t intersezione(intervallo_t, intervallo_t, int*);
int lunghezza(intervallo_t);
void visualizza(intervallo_t);

int main(){

	intervallo_t i1, i2, in;
	int lung, sov;

	i1 = acquisisci();
	i2 = acquisisci();

	in = intersezione(i1, i2, &sov);

	if(sov){
		lung = lunghezza(in);
		printf("intersezione: ");
		visualizza(in);
		printf("\nlunghezza: %d\n", lung);
	}else{
		printf("non sono sovrapposti\n");
	}

	return 0;
}

void swap(int *a, int *b){

	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

intervallo_t acquisisci(){

	intervallo_t i;

	scanf("%d %d", &i.inizio, &i.fine);

	if(i.fine<i.inizio){
		swap(&i.fine, &i.inizio);
	}

	return i;
}

intervallo_t intersezione(intervallo_t i1, intervallo_t i2, int *sovrapposti){

	intervallo_t risultato;

	if(!(i1.fine<=i2.inizio || i1.inizio>=i2.fine)){
		if(i1.inizio>i2.inizio){
			risultato.inizio = i1.inizio;
		}else{
			risultato.inizio = i2.inizio;
		}
		if(i1.fine<i2.fine){
			risultato.fine = i1.fine;
		}else{
			risultato.fine = i2.fine;
		}
		*sovrapposti = 1;
	}else{
		*sovrapposti = 0;
		risultato.inizio = 0;
		risultato.fine = 0;
	}

	return risultato;
}

int lunghezza(intervallo_t i){

	return i.fine-i.inizio;
}

void visualizza(intervallo_t i){

	printf("%d %d", i.inizio, i.fine);
}

