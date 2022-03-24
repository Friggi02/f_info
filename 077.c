/*Si vuole realizzare un programma "interattivo" che permette di gestire un percorso su uno spazio bidimensionale composto da una 
lista di località. Dichiarare un tipo di dato per rappresentare una località su una cartina in termini di coordinate x e y (due interi) ed un nome
(una stringa di al max 30 caratteri). Scrivere un programma in grado di gestire un massimo di 50 località. All'avvio il programma visualizza 
un menù con le seguenti funzionalità e chiede all'utente di selezionarne una. Implementare le funzionalità specificate come segue:

1. L'inserimento in coda può avvenire solo se c'è ancora spazio disponibile nella struttura dati, altrimenti viene visualizzato un 
messaggio di errore. In caso positivo il programma chiede all'utente i dati di una località e la aggiunge in fondo al percorso già memorizzato.

2. Anche l'inserimento in mezzo può avvenire solo se c'è ancora spazio disponibile nella struttura dati, altrimenti viene 
visualizzato un messaggio di errore. In caso positivo il programma chiede all'utente prima l'indice in cui inserire la nuova località e 
poi i dati della nuova località; il programma sposta in avanti tutte le località presenti dall'indice specificato in modo tale da creare 
spazio per i nuovi dati. Nel caso l'utente inserisca un indice non valido il programma visualizza un messaggio di errore e non procede 
con la richiesta dei dati e l'inserimento.

3. Il programma chiede all'utente l'indice della località da cancellare. Se l'indice è valido rimuove i dati relativi altrimenti 
visualizza un messaggio di errore.

4. Il programma stampa a video il percorso inserito dall'utente

5. Il programma calcola la distanza del percorso. La distanza tra due località consecutive nell'elenco è calcolata mediante il teorema 
di Pitagora. Per il calcolo della radice quadrata utilizzare la funzione sqrt() presente nella libreria math.h. Si noti che per 
compilare il programma quando si una la libreria matematica bisogna aggiungere alla fine del comando di compilazione l'argomento "-lm". 
Quindi si compilerà come "gcc distanze.c -o distante -lm"

6. Il programma identifica e visualizza la coppia di località (anche non consecutive nel percorso) la cui distanza è massima. Il 
calcolo è eseguibile solo se ci sono almeno due località inserite. Se ci fossero più coppie a pari distanza massima, il programma ne 
stampa una sola (VARIANTE: stampare tutte le coppie). Se l'utente inserisce un valore sbagliato, il programma visualizza 
un messaggio di errore e poi nuovamente il menù

7. Ricerca di una località dato il nome. La funzionalità chiede all'utente il nome di una località (una stringa di al massimo 30 
caratteri) e stampa a video i dati di tutte le località con quel dato nome. Si ricordi che per confrontare le stringhe si può usare la funzione 
strcmp() contenuta in string.h che riceve come parametri due stringhe e restituisce 0 se sono uguali.

8. Calcola cornice del percorso. La funzionalità calcola la cornice rettangolare sulla cartina che racchiude tutto il percorso e ne 
visualizza le coordinate dei due vertici in basso a sinistra ed in alto a destra. Visualizzare un apposito messaggio di errore nel caso il percorso sia vuoto.
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXS 30
#define MAXA 50
#define INSERISCI 1
#define AGGIUNGI 2
#define CANCELLA 3
#define VISUALIZZA 4
#define LUNGHEZZA 5
#define COPPIAMAX 6
#define CERCA 7
#define CORNICE 8
#define USCITA 9

/*DEFINISCO UNA VARIABILE CHE DESCRIVE IL PUNTO*/
typedef struct{
	int x, y;
	char nome[MAXS+1];
}localita_t;

/*DEFINISCO UNA VARIABILE CON L'ARRAY LOCALITA E LA SUA DIMENSIONE EFFETTIVA*/
typedef struct{
	localita_t loc[MAXA];
	int dim;
}percorso_t;

int main(){

	localita_t coppia_a, coppia_b;
	percorso_t l;
	char str[MAXS+1];
	int scelta, i, j, quadrato, x_min, x_max, y_min, y_max;
	float lunghezza, max, appoggio;

	l.dim = 0;

	do{
		printf("\n***MENU***\n%d. Inserire in coda una nuova localita\n%d. Inserire in una specificata posizione una nuova localita\n%d. Cancellare una localita nella lista\n%d. Visualizzare intero percorso\n%d. Visualizzare la lunghezza complessiva itinerario\n%d. Visualizza la coppia di localita, anche non consecutive nel percorso, la cui distanza è maggiore di qualsiasi altra coppia\n%d. Cerca localita\n%d. Calcola cornice punta-coda\n%d. Uscita\nopzione selezionata: ",
				INSERISCI, AGGIUNGI, CANCELLA, VISUALIZZA, LUNGHEZZA, COPPIAMAX, CERCA, CORNICE, USCITA);
		scanf("%d", &scelta);

		if(scelta==INSERISCI){
			if(l.dim<MAXA){
				printf("inserisci i dati: ");
				scanf("%d %d %s", &l.loc[l.dim].x, &l.loc[l.dim].y, l.loc[l.dim].nome);
				l.dim++;
			}
		}else if(scelta==AGGIUNGI){
			if(l.dim<MAXA){
				printf("inserisci indice: ");
				scanf("%d", &i);
				if(i>=0 && i<l.dim){
					for(j=l.dim-1; j>=i; j--){
						l.loc[j+1] = l.loc[j];
					}
					printf("inserisci i dati: ");
					scanf("%d %d %s", &l.loc[i].x, &l.loc[i].y, l.loc[i].nome);
					l.dim++;
				}else{
					printf("indice errato\n");
				}
			}else{
				printf("memoria piena\n");
			}
		}else if(scelta==CANCELLA){
			printf("inserisci indice: ");
			scanf("%d", &i);
			if(i>=0 && i<l.dim){
				for(; i<l.dim; i++){
					l.loc[i] = l.loc[i+1];
				}
				l.dim--;
			}else{
				printf("indice errato\n");
			}
		}else if(scelta==VISUALIZZA){
			printf("percorso:\n");
			for(i=0; i<l.dim; i++){
				printf("%d. %d %d %s\n", i, l.loc[i].x, l.loc[i].y, l.loc[i].nome);
			}
		}else if(scelta==LUNGHEZZA){
			for(i=0, lunghezza=0; i<l.dim-1; i++){
				quadrato = (l.loc[i].x-l.loc[i+1].x)*(l.loc[i].x-l.loc[i+1].x)+(l.loc[i].y-l.loc[i+1].y)*(l.loc[i].y-l.loc[i+1].y);
				lunghezza += sqrt(quadrato);
			}
			printf("lunghezza: %f\n", lunghezza);
		}else if(scelta==COPPIAMAX){
			for(i=0, max=0; i<l.dim-1; i++){
				quadrato = (l.loc[i].x-l.loc[i+1].x)*(l.loc[i].x-l.loc[i+1].x)+(l.loc[i].y-l.loc[i+1].y)*(l.loc[i].y-l.loc[i+1].y);
				appoggio = sqrt(quadrato);
				if(max<appoggio){
					max = appoggio;
					coppia_a = l.loc[i];
					coppia_b = l.loc[i+1];
				}
			}
			printf("il tratto piu lungo e di %f:\n%d %d %s\n%d %d %s", max, coppia_a.x, coppia_a.y, coppia_a.nome, coppia_b.x, coppia_b.y, coppia_b.nome);
		}else if(scelta==CERCA){
			printf("localita da cercare: ");
			scanf("%s", str);
			for(i=0; i<l.dim; i++){
				if(!strcmp(str, l.loc[i].nome)){
					printf("%d. %d %d %s\n", i, l.loc[i].x, l.loc[i].y, l.loc[i].nome);
				}
			}

		}else if(scelta==CORNICE){
			if(l.dim==0){
				printf("percorso vuoto\n");
			}else{
				x_min = l.loc[0].x;
				y_min = l.loc[0].y;
				x_max = l.loc[0].x;
				y_max = l.loc[0].y;
				for(i=0; i<l.dim; i++){
					if(l.loc[i].x<x_min){
						x_min = l.loc[i].x;
					}
					if(l.loc[i].x>x_max){
						x_max = l.loc[i].x;
					}
					if(l.loc[i].y<y_min){
						y_min = l.loc[i].y;
					}
					if(l.loc[i].y>y_max){
						y_max = l.loc[i].y;
					}
				}
				printf("estremo inferiore sinistro: %d %d\n", x_min, y_min);
				printf("estremo superiore destro: %d %d\n", x_max, y_max);
			}			
		}else if(scelta!=USCITA){
			printf("scelta non valida\n");
		}
	}while(scelta!=USCITA);
		
	return 0;
}