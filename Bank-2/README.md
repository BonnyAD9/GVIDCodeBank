# Bank-2

## Zadání
Pomocí podprogramů
- načti ze vstupu stupeň a koeficienty polynomu, dále načti hodnotu x a vypočítej Hornerovým schématem hodnotu polynomu v daném bodě
- čti ze vstupu řadu číselných hodnot předem neznámé délky (až do konce vstupu - EOF) a vypiš posledních N hodnot, součet posledních N hodnot, vypiš posledních N hodnot v opačném pořadí
- čti vstup neznámé délky po znacích a vrať pole reprezentující histogram, poté z něj vypiš absolutní četnosti malých znaků anglické abecedy (počty znaků na vstupu)
- Vytvoř funkci realizující textovou nabídku, která bude vracet znaky A, B, K, X s významem A – Volba A, B – Volba B, K – Konec, X – Neznámá volba (bude to vracet při neočekávané volbě). Použij ji pro komunikaci s uživatelem dokud nezvolí ukončení programu.
  - Definuj pole dvojic (znak, řetězec). Definuj takové pole obsahující textovounabídku pro uživatele s významem A – Volba A, B – Volba B, K – Konec, X – Neznámá volba. Vytvoř funkci, která podle takto zadaného pole zobrazí textovou nabídku pro uživatele a vrátí písmeno zvolené volby (musí fungovat i s pozměněným polem s nabídkou). Použij ji pro komunikaci s uživatelem dokud nezvolí ukončení programu.

## Output
```
======<<MENU>>======
0. Exit
1. Polynomial
2. Last N
3. Histogram
Enter your choice: 1
===<<POLYNOMIAL>>===
Enter degree of polynomial: 2
Enter coefficients: 1 2 -3
Enter number: 2
result: 5.000000
======<<MENU>>======
0. Exit
1. Polynomial
2. Last N
3. Histogram
Enter your choice: 2
=====<<LAST N>>=====
Enter N: 5
Enter numbers: 1 2 3 4 5 6 7 8 9
Last 5 numbers: 5.000000 6.000000 7.000000 8.000000 9.000000
Sum of last 5 numbers: 35.000000
Last 5 numbers reversed: 9.000000 8.000000 7.000000 6.000000 5.000000
======<<MENU>>======
0. Exit
1. Polynomial
2. Last N
3. Histogram
Enter your choice: 3
====<<HISTOGRAM>>===
Enter charaters: aůlkfjgoůiarj uioah poiuha puh íá zčišuh íá  fa 654gad 3gf1
Small english letters counts:
a: 6
b: 0
c: 0
d: 1
e: 0
f: 3
g: 3
h: 4
i: 4
j: 2
k: 1
l: 1
m: 0
n: 0
o: 3
p: 2
q: 0
r: 1
s: 0
t: 0
u: 4
v: 0
w: 0
x: 0
y: 0
z: 1
======<<MENU>>======
0. Exit
1. Polynomial
2. Last N
3. Histogram
Enter your choice: lol
Invalid choice
======<<MENU>>======
0. Exit
1. Polynomial
2. Last N
3. Histogram
Enter your choice: 0
Quitting
```
