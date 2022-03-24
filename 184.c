/*Scrivere un sottoprogramma che riceve come parametri una stringa str ed un numero n sicuramente compreso tra 1 e 10 estremi inclusi. 
Assumendo che la stringa sia composta da cifre (caratteri!) comprese tra '0' e la cifra corrispondente al valore intero n-1 il 
sottoprogramma converte in intero, base dieci, il valore rappresentato dalla stringa in base n e restituisce il risultato.
Nel caso la stringa contenga un carattere non ammissibile, il sottoprogramma restituisce -1.

Esempi:
Per str = '100', n = 2, il sottoprogramma restituisce il valore 4 (= 1*2^2)
Per str = '210', n = 3, il sottoprogramma restituisce il valore 21 (= 2*3^2 + 1*3^1)

Scrivere un programma che acquisice una scringa di massimo 30 caratteri e un intero n sicuramente compreso tra 1 e 10 estremi inclusi.
Il programma richiama il sottoprogramma e visualizza il risultato.
*/

#include <stdio.h>
#define MAXS 30

int converti(char [], int);

int main(){

	int b, val;
	char str[MAXS+1];

	printf("inserisci stringa: ");
	scanf("%s", str);

	do{
		printf("inserire base: ");
		scanf("%d", &b);
	}while(b<1 || b>10);

	val = converti(str, b);

	printf("%d\n", val);

	return 0;
}

int converti(char str[], int n){
	
	int val, i, pot;
	
	for(i=0; str[i] !='\0'; i++);
	
	for(i--, val=0, pot=1; i>=0 && val!=-1; i--){
		if(str[i]>='0' && str[i]<'0'+n){
			val += pot*(str[i]-'0');
			pot*=n;
		}else{
			val = -1;
		}
	}
	
	return val;
}