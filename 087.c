/*Definire un tipo di dato struct per rappresentare una frazione in termini di numeratore e denominatore (due numeri interi). 

Scrivere un sottoprogramma che chiede all'utente una frazione valida (denominatore diverso da zero) e la restituisce al chiamate;
nel caso la condizione non sia soddisfatta il sottoprogramma richiede di nuovo all'utente di inserire dei valori validi. 

Scrivere un sottoprogramma che riceve come parametro una frazione e la semplifica spostando l'eventuale segno meno al numeratore. 

Scrivere un sottoprogramma che riceve come parametri due frazioni, ne esegue la somma, semplifica
il risultato (mediante la funzione precedentemente definita) e restituisce il risultato.

Scrivere un sottoprogramma che riceve come parametri due frazioni, ne esegue la moltiplicazione,
semplifica il risultato (mediante la funzione precedentemente definita) e restituisce il risultato. 

Scrivere un sottoprogramma che riceve come parametro una frazione e la stampa a video.

Scrivere un programma che mediante l'ausilio dei sottoprogrammi sopra definiti,
chiede all'utente due frazioni le somma e le moltiplica e visualizza i due risultati.*/

#include <stdio.h>

typedef struct{
	int n, d;
} frac_t;

frac_t acquisisci();
frac_t semplifica(frac_t);
frac_t somma(frac_t, frac_t);
frac_t moltiplica(frac_t, frac_t);
void stampa(frac_t);

int main(){

	frac_t a, b, s, m;

	a = acquisisci();
	b = acquisisci();

	s = somma(a, b);
	m = moltiplica(a, b);

	stampa(s);
	stampa(m);

	return 0;
}

frac_t acquisisci(){

	frac_t f;

	do{
		scanf("%d %d", &f.n, &f.d);
	}while(f.d==0);

	return f;
}

frac_t semplifica(frac_t f){

	int meno, mcd;

	if(f.n<0){
		meno = 1;
		f.n = -f.n;
	}else{
		meno = 0;
	}

	if(f.d<0){
		meno = !meno;
		f.d = -f.d;
	}
	
	if(f.n<f.d){
		mcd = f.n;
	}else{
		mcd = f.d;
	}
	while(f.n%mcd || f.d%mcd){
		mcd--;
		f.n /= mcd;
		f.d /= mcd;
		if(meno){
			f.n = -f.n;
		}
	}

	return f;
}

frac_t somma(frac_t a, frac_t b){

	frac_t s;

	s.n = a.n*b.d+b.n*a.d;
	s.d = a.d*b.d;
	s = semplifica(s);

	return s;
}

frac_t moltiplica(frac_t a, frac_t b){

	frac_t m;

	m.n = a.n*b.n;
	m.d = a.d*b.d;

	return semplifica(m);
}

void stampa(frac_t f){

	printf("%d/%d\n", f.n, f.d);
}