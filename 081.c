/*Scrivere un sottoprogramma che riceve in ingresso due valori in virgola mobile, calcola e restituisce il maggiore tra i due. 

Scrivere un programma che chiede all'utente tre numeri in virgola mobile e stabilisce,
mediante il sottoprogramma definito prima, quale dei tre è più grande visualizzandolo a video.*/

#include <stdio.h>
float maggiore(float, float);

int main(){

	float num1, num2, num3, massimo;

	scanf("%f %f %f", &num1, &num2, &num3);
	
	massimo = maggiore(maggiore(num1, num2), num3);

	printf("%f\n", massimo);

	return 0;
}

float maggiore(float a, float b){

	float m;
	
	if(a>b){
		m = a;
	}else{
		m = b;
	}
	
	return m;
}
