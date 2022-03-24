/*Scrivere un programma in C che chiede all'utente una stringa di al massimo 10 caratteri che rappresenta un numero intero positivo in 
base 8 (cioè composta soltanto dai caratteri dallo '0' al '7'). Il programma calcola e visualizza il valore intero rappresentante lo 
stesso numero in base 10. Nel caso la stringa contenga un carattere non valido, il programma visualizza il valore -1.

Esempio 1: Se l'utente inserisce la stringa "24", il programma visualizza il valore intero 20 (infatti (2x8^1)+(4x8^0)=(16)+(4)=20). 

Esempio 2: Se l'utente inserisce la stringa "95", il programma visualizza il valore intero -1 (infatti '9' non è un carattere tra 
'0' e '7'). Stessa cosa se il programma legge la stringa "h5".*/

#include <stdio.h>

#define MAXS 10
#define BASE 8
#define ERRORE -1

int main(){

	char str[MAXS+1];
	int i, appoggio, dec, ctrl, pot;

/*ACQUISIZIONE*/
	scanf("%s", str);

/*CALCOLO LUNGHEZZA*/
	for(i=0; str[i]!='\0'; i++);

/*ELABORAZIONE*/
	for(i--, pot=1, dec=0; i>=0 && dec!=ERRORE; i--, pot*=BASE){
		if(str[i]>='0' && str[i]<BASE+'0'){
			appoggio = str[i]-'0';
			dec += appoggio*pot;			
		}else{
			dec = ERRORE;
		}
	}
	
/*VISUALIZZAZIONE*/	
	printf("%d\n", dec);
	
	return 0;
}