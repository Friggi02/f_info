/*Scrivere un programma in C che acquisisce tre numeri in virgola mobile e verifica se la terna può rappresentare le dimensioni dei 
lati di un triangolo: devono essere valori positivi; inoltre la somma di due numeri deve essere maggiore del terzo. Se il controllo 
è stato superato con successo, il programma stabilisce che tipo di triangolo è isoscele, equilatero o scaleno e stampa un apposito 
messaggio a video. Altrimenti, il programma deve stampare un apposito messaggio di errore.*/

#include <stdio.h>

int main(){

	float a, b, c;

	printf("inserire i tre lati: ");
	scanf("%f %f %f", &a, &b, &c);

	if(a>0 && b>0 && c>0){
		if(a<b+c && b<a+c && c<a+b){
			if(a==b && b==c && c==a){
				printf("triangolo equilatero\n");
			}else if(a!=b && b!=c && a!=c){
				printf("triangolo scaleno\n");
			}else{
				printf("triangolo isoscele\n");
			}
		}else{
			printf("i valori non sono validi\n");
		}
	}else{
		printf("i numeri negativi o nulli non sono validi\n");
	}

	return 0;
}