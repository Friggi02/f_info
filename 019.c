/*Scrivere un programma in C che chiede all’utente i tre coefficienti di un'equazione di secondo grado (ax^2+bx+c=0), tre numeri in 
virgola mobile. Il programma verifica prima che l'equazione sia effettivamente di secondo grado (ovvero a != 0). In caso 
affermativo, il programma deve calcolarne il determinante e informare l'utente se le soluzioni sono reali e distinte (det>0), 
coincidenti (det=0) o complesse coniugate (det<0). Nel caso a=0, il programma stampa un messaggio di errore.*/

#include <stdio.h>

int main(){

	float a, b, c, det;

	printf("inserire i tre nuemeri: ");
	scanf("%f %f %f", &a, &b, &c);

	if(a!=0){
		det = b*b-4*a*c;
		if(det>0){
			printf("soluzioni reali e distinte\n");
		}else if(det==0){
			printf("soluzioni reali e coincidenti\n");
		}else{
			printf("soluzioni complesse coniugate\n");
		}
	}else{
		printf("errore\n");
	}

	return 0;
}