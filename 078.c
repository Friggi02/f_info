/*Si vuole realizzare un programma per la gestione di un archivio di CD musicali (al massimo 100). Ogni CD è caratterizzato da un titolo 
ed un autore (entrambe stringhe di al massimo 30 caratteri), un anno di pubblicazione, il numero di tracce, la durata complessiva (in 
termini di ore, minuti, secondi); inoltre si vuole memorizzare anche il prezzo del cd (un valore float). Definire un tipo di dato per 
rappresentare l'archivio di CD. In seguito scrivere un programma che chiede all'utente prima il numero di CD da inserire e poi i dati di 
ciascun CD (assumendo che l'utente inserisca correttamente i dati). Il programma visualizza i dati del cd di durata massima; se sono 
presenti più cd di stessa durata massima il programma visualizzerà i dati del primo di essi.

VARIANTE: il programma visualizza i dati di tutti i CD di durata massima, se ne sono stati trovati più di uno.
Il programma chiede in seguito il nome di un autore e visualizza i titoli di tutti i CD pubblicati da questo.
Infine il programma visualizza l'autore che ha pubblicato più CD (se più di con lo stesso numero massimo di CD, si visualizzi il primo).*/

#include <stdio.h>
#include <string.h>
#define MAX_S 30
#define MAX_CD 100

typedef struct{
	int ore, minuti, secondi;
} durata_t;

typedef struct{
	char titolo[MAX_S+1], autore[MAX_S+1];
	int anno, n_tracce;
	durata_t durata;
	float prezzo;
} cd_t;

typedef struct{
	cd_t cd[MAX_CD];
	int n_cd;
} archivio_t;



int main(){
	
	archivio_t arc;
	int i, j, i_max, durata_max, durata_curr, conto_autore, max_conto;
	char autore[MAX_S];

/*ACQUISISCO NUMERO DI CD*/
	printf("numero di CD: ");
	scanf("%d", &arc.n_cd);
	while(arc.n_cd<=0 || arc.n_cd>MAX_CD){
		printf("immettere un numero valido: ");
		scanf("%d", &arc.n_cd);
	}

/*ACQUISISCO CD*/
	for(i=0; i<arc.n_cd; i++){
		printf("\n**CD %d**\n", i);
		printf("titolo: ");
		scanf(" %[^\n]", arc.cd[i].titolo);
		printf("autore: ");
		scanf(" %[^\n]", arc.cd[i].autore);
		printf("anno di pubblicazione: ");
		scanf("%d", &arc.cd[i].anno);
		printf("numero di tracce: ");
		scanf("%d", &arc.cd[i].n_tracce);
		printf("ore: ");
		scanf("%d", &arc.cd[i].durata.ore);
		printf("minuti: ");
		scanf("%d", &arc.cd[i].durata.minuti);
		printf("secondi: ");
		scanf("%d",&arc.cd[i].durata.secondi);
		printf("prezzo: ");
		scanf("%f", &arc.cd[i].prezzo);
	}
	
/*CERCO E STAMPO IL CD DI DURATA MASSIMA*/
	durata_max = (arc.cd[0].durata.ore*3600)+(arc.cd[0].durata.minuti*60)+arc.cd[0].durata.secondi;
	for(i=1, i_max=0; i<arc.n_cd; i++){
		durata_curr =(arc.cd[i].durata.ore*3600)+(arc.cd[i].durata.minuti*60)+arc.cd[i].durata.secondi;
		if(durata_max<durata_curr){
			durata_max = durata_curr;
			i_max = i;
		}
	}
	printf("\ncd di durata maggiore:\n%s\n%s\n%d\n%d tracce\n%d ore %d minuti %d secondi\n%f€\n",
			arc.cd[i_max].titolo, arc.cd[i_max].autore, arc.cd[i_max].anno, arc.cd[i_max].n_tracce, arc.cd[i_max].durata.ore, arc.cd[i_max].durata.minuti, arc.cd[i_max].durata.secondi, arc.cd[i_max].prezzo);

/*CHIEDO UN AUTORE*/
	printf("\ninserisci autore: ");
	scanf(" %[^\n]", autore);

/*CERCO E STAMPO I CD DELLO STESSO AUTORE*/
	for(i=0; i<arc.n_cd; i++){
		printf("cd di %s:\n", autore);
		if(strcmp(autore, arc.cd[i].autore)==0){
				printf("\n%s\n%s\n%d\n%d tracce\n%d ore %d minuti %d secondi\n%f€\n",
						arc.cd[i].titolo, arc.cd[i].autore, arc.cd[i].anno, arc.cd[i].n_tracce, arc.cd[i].durata.ore, arc.cd[i].durata.minuti, arc.cd[i].durata.secondi, arc.cd[i].prezzo);
		}
	}

/*CERCO E STAMPO L'AUTORE CON PIU CD*/
	for(i=0, max_conto; i<arc.n_cd; i++){
		for(j=i, conto_autore=0; j<arc.n_cd; j++){
			if(strcmp(arc.cd[i].autore, arc.cd[j].autore)==0){
				conto_autore++;
			}
		}
		if(conto_autore>max_conto){
			max_conto = conto_autore;
			strcpy(autore, arc.cd[i].autore);
		}
	}
	printf("\nautore con piu cd: %s\n", autore);

	return 0;
}