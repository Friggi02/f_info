/* Scrivere un programma che acquisisce una stringa di al massimo 20 caratteri composta da sole parentesi tonde '(' e ')'. Il 
programma verifica se la stringa è "ben parentesizzata" in base alla definizione studiata nelle lezioni di matematica a scuola. Il 
programma stampa un apposito messaggio a video con il responso o un messaggio di errore nel caso la stringa contenga un carattere 
diverso dalle parentesi tonde. Si ricordi che una stringa è ben parentesizzata se:
    * la stringa è vuota
    * ad ogni parentesi aperta ne corrisponde una chiusa, e tra di esse la sottostringa è anch'essa ben parentesizzata
    * la stringa è una concatenazione (cioè una successione) di due sottostringhe ben parentesizzate

Esempi di stringhe ben parentesizzate sono:
()
()()()
(())()

Esempi di stringhe NON ben parentesizzate sono:
()( - una parentesi aperta di troppo
(()() - una parentesi aperta di troppo
)() - una parentesi chiusa di troppo
)( - una parentesi chiusa di troppo (e poi una parentesi aperta di troppo)

*/

#include <stdio.h>
#define DIM 20

int main(){

    char str[DIM+1];
    int i, contatore, ok;

/*ACQUISISCO LA STRINGA*/
    scanf(" %s", str);

/*ELABORAZIONE*/
    for(i=0, ok=1, contatore=0; str[i]!='\0' && ok ; i++){
        if(str[i]=='('){
            contatore++;
        }else if(str[i]==')' && contatore>0){
            contatore--;
        }else{
            ok = 0;
        }
    }
    if(contatore!=0){
        ok = 0;
    }

/*VISUALIZZAZIONE*/
    if(ok){
        printf("la stringa è parentesizzata correttamente\n");
    }else{
        printf("la stringa non è parentesizzata correttamente\n");
    }

    return 0;
}