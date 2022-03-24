# Debugger (GDB)
- Installa GDB.
Sostituisci `${nome_file}` con il nome del file **.c** .
Sostituisci `${nome_exec}` con il nome dell'**eseguibile**.

```sh
gcc -g ${nome_file}.c -o ${nome_exec}
gdb --args ./${nome_exec}
```

| Comando | Risultato |
| ------ | ------ |
| list | Mostra codice sorgente con numeri riga |
| b `#` | Breakpoint al numero riga `#`|
| run | Avvio fino a breakpoint (se presente/i)* |
| display `i` | Mostra valore `i` ad ogni successiva iterazione del programma |
| print `i` | Mostra valore `i` una sola volta |
| n | Esegue riga successiva |
| quit | Esci da GDB |
| bt | Visualizza cronologie chiamate nel programma |

*con `run` è possibile ricavare riga di segmentation fault.

