# Bank-1

## Zadání
Pomocí podprogramů
- načti m×n prvků do 2D pole ze standardního vstupu, ze souboru
- vypiš výsledné pole na standardní výstup, do souboru
- zjisti počet sudých prvků v každém sloupci a zapiš jej do posledního řádku v tomto sloupci
- zjisti součet všech prvků na obvodu matice a pak všech prvků kromě obvodových
- zjisti součet prvků ve čtvrtinách matice, když každý rozměr rozdělíš celočíselným dělením 2
- zjisti, zda je matice vertikálně, či horizontálně symetrická
- vytvoř transponovanou matici
- vytvoř matici otočenou o 90, 180, 270 stupňů (zadej počet otočení o 90 stupňů parametrem)

## Output
```
=====<<BANK-1>>=====
======<<READ>>======
======<<WRITE>>=====
3 4
 1  2  3  4
 5  6  7  8
 9 10 11 12
===<<EVEN COUNT>>===
4 4
 1  2  3  4
 5  6  7  8
 9 10 11 12
 0  3  0  3
===<<BORDER SUM>>===
border: 65
center: 13
===<<QUARTER SUM>>==
 3  7
30 38
=====<<SYMETRY>>====
none
====<<TRANSPOSE>>===
4 3
 1  5  9
 2  6 10
 3  7 11
 4  8 12
=====<<ROTATE>>=====
rotate 0:
3 4
 1  2  3  4
 5  6  7  8
 9 10 11 12
rotate 1:
4 3
 9  5  1
10  6  2
11  7  3
12  8  4
rotate 2:
3 4
12 11 10  9
 8  7  6  5
 4  3  2  1
rotate 3:
4 3
 4  8 12
 3  7 11
 2  6 10
 1  5  9
 ```
