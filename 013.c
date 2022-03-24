/*Scrivere un programma in C che acquisisce 3 interi. Il programma verifica se costituiscono una terna pitagorica;
in caso affermativo il programma stampa a video "1" altrimenti "0".

NOTA: l'utente può inserire i tre numeri in qualsiasi ordine; es. "3 4 5" e "5 3 4" sono entrambe terne pitagoriche.*/

#include <stdio.h>

int main(){

	int a, b, c, ipotenusa, cat_1, cat_2;

	printf("inserire i tre numeri: ");
	scanf("%d %d %d", &a, &b, &c);

	if(a>b && a>c){
		ipotenusa = a;
		cat_1 = b;
		cat_2 = c;
	}else if(b>a && b>c){
		ipotenusa = b;
		cat_1 = a;
		cat_2 = c;
	}else{
		ipotenusa = c;
		cat_1 = b;
		cat_2 = a;
	}
	
	if(ipotenusa*ipotenusa==cat_1*cat_1+cat_2*cat_2){
		printf("1\n");
	}else{
		printf("0\n");
	}

	return 0;
}