/*Scrivere un programma in C che acquisito un numero intero visualizza il messaggio "positivo", "negativo" o "nullo" in base al valore.*/

#include <stdio.h>

int main(){

	int n;

	printf("inserire numero: ");
	scanf("%d", &n);

	if(n>=0){
		if(n>0){
			printf("positivo\n");
		}else{
			printf("nullo\n");
		}
	}else{
		printf("negativo\n");
	}

return 0;
}
