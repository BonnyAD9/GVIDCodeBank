# Bank-18

## Zadání
Pomocí podprogramů...
- Vytvoř funkci, která z polí naměřených hodnot x a y vypočte aproximaci pomocí
    - konstantní funkce
    - lineární funkce (bude k dispozici funkce pro řešení soustavy 2 rovnic o 2 neznámých)
- Načti ze vstupu čtvercovou matici. Ověř, zda je matice souměrná podle
    - hlavní/vedlejší diagonály
    - vodorovné/svislé osy
- V polích x a y délky N jsou naměřené hodnoty. Je dána lineární funkce s koeficienty a, b. Vytvoř v C funkci, která vrátí součet čtverců vertikálních vzdáleností naměřených hodnot od dané lineární funkce.

## Output
```
====<<CONSTANT>>====
Enter number of entries: 5
Enter values of x and than values of y:
1 2 3 4 5
2 3 4 5 8
f(x)=4.400000
=====<<LINEAR>>=====
f(x)=1.400000x+0.200000
===<<SYMETRICITY>>==
Enter square matrix size: 4
Enter the matrix data:
0 1 2 3
1 4 5 2
2 5 4 1
3 2 1 0
\: yes
/: yes
-: no
|: no
==<<SQUARE DISTANCE SUM>>==
sum: 13.000000
```