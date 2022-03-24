/*Scrivere un programma che chiede all'utente una stringa di al massimo 30 caratteri. Il programma identifica nella stringa tutte le 
sotto-sequenze di sole cifre in posizioni consecutive, e visualizza le lunghezze della sotto-sequenza più lunga e di quella più corta. 
Se per esempio la stringa di ingresso è "a1245b645c7de45", il programma visualizza i valori 4 e 1
(avendo individuato le sotto-sequenze "1245" e "7"). Nel caso la stringa non contenga alcuna cifra, il programma visualizza il messaggio "0 0"*/

#include <stdio.h>
#define DIM 30

int main(){

	char str[DIM+1];
	int i, j, max, min, conto;

	scanf("%s", str);

	max = 0;
	min = 0;
	conto = 0;

	for(i=0; str[i]!='\0'; i++){
		for(conto=0; str[i]>='0' && str[i]<='9'; i++, conto++);
		if(conto>0){
			if(conto>=max){
				max = conto;
			}
			if(min==0 || conto<min){
				min = conto;
			}
			conto = 0;
			i--;
		}
	}
	
	printf("%d %d\n", max, min);
	
	return 0;
}