# Bank-9

## Zadání
Pomocí podprogramů...
- Je dáno Σ={a}, N={S, A, B, C}. Pravidlo gramatiky má tvar „řetězec->řetězec“. Napiš funkci, která ověří, zda zadaný řetězec je
  - pravidlem gramatiky typu 3
  - pravidlem gramatiky typu 2
- Napiš funkci, která bude systematicky generovat prvních N vět jazyka zadaného gramatickými pravidly S->aA, A->bB, B->cA, B->c. Zapiš tyto věty na samostatné řádky výstupu.

## Output
```
====<<RULE TYPE>>===
Enter grammar rule: A->Ahoj
Enter nonterminals: A
Regular grammar
=====<<SENTANCE>>====
rules:
S->aA
A->bB
B->cA
B->c
Enter max depth to generate: 5
1: abc
2: abcbc
3: abcbcbc
4: abcbcbcbc
5: abcbcbcbcbc
```
