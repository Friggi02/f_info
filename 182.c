/*Scrivere un sottoprogramma che riceve come parametri due interi n e b, con b sicuramente compreso tra 1 e 9 estremi inclusi. Il 
sottoprogramma visualizza tutti i numeri, in ordine crescente, che possono essere generati in base b su n cifre.

Per esempio se il sottoprogramma riceve in ingresso i valori n=3 e b=2, stampa a video "000, 001, 010, 011, 100, 101, 110, 111". 

Scrivere un programma che chiede all'utente due valori interi n e b ed invoca il sottoprogramma sopra definito.

NOTA: nel caso si realizzi un sottoprogramma ricorsivo è possibile passare anche ulteriori parametri ritenuti necessari.*/

#include<stdio.h>
#include<stdlib.h>

void _conta_ric(int, int, int, int[]);
void conta_ric(int, int);

int main(int argc, char* argv[]){
	
	int n, b;
	
	printf("inserire numero cifre: ");
	scanf("%d", &n);
	do{
		printf("inserire base: ");
		scanf("%d", &b);
	}while(b<1 || b>9);

	conta_ric(n, b);
	
	return 0;
}

void conta_ric(int n, int b) {
	
	int *a;
	
	a = malloc(sizeof(int)*n);
	
	if(a){
		_conta_ric(n, b, 0, a);
		free(a);
	}else{
		printf("Errore memoria\n");
	}
}

void _conta_ric(int n, int b, int pos, int a[]) {
	
	int i;
	
	if(pos == n) {
		for(i=0; i<n; i++){
			printf("%d", a[i]);
		}
		printf("\n");
	}else{
		for(i=0; i<b; i++){
			a[pos] = i;
			_conta_ric(n, b, pos+1, a);
		}
	}
}