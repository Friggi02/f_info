/*Si vuole realizzare un programma che permetta di effettuare alcune operazioni geometriche su rettangoli.
Dichiarare un tipo di dato per rappresentare un rettangolo. Un rettangolo è descritto dal vertice inferiore sinistro e da quella del vertice 
superiore destro (due punti).Un punto è definito in termini di coordinate x e y (due interi) su uno 
spazio cartesiano bidimensionale. Scrivere un programma che esegua le seguenti elaborazioni in sequenza:

1 - Acquisisce da tastiera i dati di due rettangoli, verificandone la correttezza delle coordinate (la prima coordinata è effettivamente in 
basso a sinistra rispetto alla seconda) e se non valide le richiede.

2 - Calcola e visualizza l'area di ciascun rettangolo.

3 - Verifica se i due rettangoli sono intersecati e visualizza l'esito del test.

4 - Se sono intersecati, costruisce in una nuova variabile il rettangolo intersezione (prestare attenzione a tutte le casistiche legate alla 
posizione di un rettangolo rispetto all'altro) e ne visualizza le coordinate a schermo.

5 - Se sono intersecati, calcola e visualizza l'intersezione sull'unione, ovvero la frazione (quindi un valore in virgola mobile) tra l'area 
dell'intersezione tra i due rettangoli e l'area totale della forma geometrica generata dai due rettangoli sovrapposti.*/

#include <stdio.h>
#include <math.h>

typedef struct{
	int x1, y1, x2, y2;
} rettangolo_t;

void acquisisci(rettangolo_t*);
int calcola_area(rettangolo_t*);
int controlla_intersezione(rettangolo_t*, rettangolo_t*);
void calcola_intersezione(rettangolo_t*, rettangolo_t*, rettangolo_t*);

int main(){

	rettangolo_t r1, r2, ri;
	int area, sovrapposti;

	printf("\n***RETTANGOLO 1***");
	acquisisci(&r1);
	printf("\n***RETTANGOLO 2***");
	acquisisci(&r2);

	printf("\n");
	area = calcola_area(&r1);
	printf("area rettangolo 1: %d\n", area);
	area = calcola_area(&r2);
	printf("area rettangolo 2: %d\n", area);

	sovrapposti = controlla_intersezione(&r1, &r2);
	printf("\nsovrapposti: %d\n", sovrapposti);

	if(sovrapposti){
		calcola_intersezione(&r1, &r2, &ri);
		printf("\n***RETTANGOLO INTERSEZIONE***\n");
		printf("coordinate angolo inferiore sinistro: %d %d\n", ri.x1, ri.y1);
		printf("coordinate angolo superiore destro: %d %d\n", ri.x2, ri.y2);
		printf("area: %d\n", calcola_area(&ri));
	}
	
	return 0;
}

void acquisisci(rettangolo_t *rettangolo){

	do{
		printf("\n");
		printf("coordinate angolo inferiore sinistro: ");
		scanf("%d %d", &rettangolo->x1, &rettangolo->y1);
		printf("coordinate angolo superiore destro: ");
		scanf("%d %d", &rettangolo->x2, &rettangolo->y2);
	}while(rettangolo->x2<rettangolo->x1 || rettangolo->y2<rettangolo->y1);
}

int calcola_area(rettangolo_t *rettangolo){

	return ((rettangolo->x2-rettangolo->x1)*(rettangolo->y2-rettangolo->y1));
}

int controlla_intersezione(rettangolo_t *r1, rettangolo_t *r2){

	return !((r2->x1>=r1->x2) || (r2->x2<=r1->x1) || (r2->y1>=r1->y2) || (r2->y2<=r1->y1));
}

void calcola_intersezione(rettangolo_t *r1, rettangolo_t *r2, rettangolo_t *ri){

	ri->x1 = fmax(r1->x1, r2->x1);
	ri->y1 = fmax(r1->y1, r2->y1);
	ri->x2 = fmin(r1->x2, r2->x2);
	ri->y2 = fmin(r1->y2, r2->y2);
}