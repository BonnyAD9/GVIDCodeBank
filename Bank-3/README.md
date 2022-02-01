# Bank-3
## Zadání
Vytvoř podprogramy pro zpracování textového řetězce zadaného jako parametr
- načti řetězec ze vstupu (maximálně N znaků)
- vrať počet číslic v řetězci
- vrať indexy první a poslední nalezené číslice v řetězci (přes parametry)
- nahraď v řetězci každý výskyt znaku x znakem y (x a y jsou parametry funkce)
- skryj v řetězci každé číslo přepsáním pomocí znaku #
- vrať počet slov v řetězci
- nahraď v řetězci malá písmena za velká, nebo velká za malá
- proveď reverzi řetězce jednou pomocí rekurze a jednou pomocí cyklu s co nejmenším počtem iterací
## Output
```
======<<READ>>======
Enter string length: 10
Enter string: as5dDasd6Ajlk
as5dDasd6A
===<<DIGIT COUNT>>==
digit count: 2
first digit index: 2
last digit index: 8
=====<<REPLACE>>====
Enter old and new character: d1
as51Das16A
==<<HIDE NUMBERS>>==
as##Das##A
===<<WORD COUNT>>===
word count: 1
===<<LOWER UPPER>>==
lower: as##das##a
upper: AS##DAS##A
=====<<REVERSE>>====
loop: A##SAD##SA
recursion: AS##DAS##A
```
