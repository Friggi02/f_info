/*Realizzare un programma in C per la gestione di una serie di rilevazioni di temperature sui piani di un edificio. Ciascun 
rilevazione specifica il numero del piano, l'ora della misura (una stringa di al massimo 8 caratteri) e la temperatura letta (un numero 
intero). Definire un tipo di dato strutturato per rappresentare ciascuna rilevazione.
In seguito, scrivere un programma per la gestione delle rilevazioni. Il programma dovrà chiedere all'utente di specificare il numero di 
rilevazioni da inserire (massimo 100 e nel caso l'utente non inserisca un valore valido il programma lo richiede) e poi inserire 
le rilevazioni (si assume che i dati siano inseriti correttamente in base all'ora). In seguito il programma dovrà chiedere all'utente il 
numero di un piano. Il programma visualizzerà gli intervalli di tempo per cui la temperatura di quel piano è stata inferiore ai 22 
gradi. Si noti che è necessario stampare solo l'ora relativa alla prima e all'ultima rilevazione di ciascun intervallo.
ESEMPIO:
Numero di rilevazioni: 8
Rilevazioni:
1 10:30:00 23
2 10:35:00 21
2 11:00:00 20
1 11:20:00 23
2 11:34:00 21
2 12:30:00 24
1 12:40:00 23
2 14:30:00 21
Piano da analizzare: 2
Risultato:
10:35:00 -> 11:34:00 
14:30:00 -> 14:30:00          */

#include <stdio.h>
#define DIM_STR_ORA 8
#define N_RIL_MAX 100
#define CONTROLLO 23

typedef struct{
	int piano, temperatura;
	char ora[DIM_STR_ORA+1];
}rilevamento_t;

int main(){

	rilevamento_t ril[N_RIL_MAX];
	int i, num_ril, prec, piano;

/*ACQUISISCO NUMERO RILEVAZIONI*/
	printf("numero di rilevazioni: ");
	scanf("%d", &num_ril);
	while(num_ril<=0 || num_ril>N_RIL_MAX){
		printf("immettere un numero valido: ");
		scanf("%d", &num_ril);
	}

/*ACQUISISCO RILEVAZIONI*/
	for(i=0; i<num_ril; i++){
		printf("\n**RILEVAZIONE %d**\n", i);
		printf("piano: ");
		scanf("%d", &ril[i].piano);
		printf("ora: ");
		scanf("%s", ril[i].ora);
		printf("temperatura: ");
		scanf("%d", &ril[i].temperatura);
	}

/*ACQUISISCO PIANO DA ANILIZZARE*/
	printf("piano da analizzare: ");
	scanf("%d", &piano);

/*ELABORAZIONE E VISUALIZZAZIONE*/
	printf("risultato:\n");
	prec = -1;
	for(i=0; i<num_ril; i++){
		if(ril[i].piano==piano){
			if(prec==-1 && ril[i].temperatura<CONTROLLO){
				prec = i;
				printf("%s ->", ril[i].ora);
			}else if(prec!=-1 && ril[i].temperatura<CONTROLLO){
				prec = i;
			}else if(prec!=-1 && ril[i].temperatura>=CONTROLLO){
				printf("%s\n", ril[prec].ora);
				prec = -1;
			}
		}
	}
	if(prec!=-1){
		printf("%s\n", ril[prec].ora);
	}
	
	return 0;
}