# Bank-11

## Zadání
Pomocí podprogramů...
- Vytvoř dynamický datový typ zásobník. Datovou složkou bude jeden znak. Vytvoř funkce Push a Pop.
    - Otestuj pomocí nich, zda ve vstupním textu jsou správné počty správně uzavřených a vnořených závorek. Uvažuj kulaté (), hranaté [] a složené závorky {}. Například tohle „{([])}“ je správně, tohle „{[(])}“ je špatně.
- Vytvoř dynamický datový typ fronta. Datovou složkou bude jeden znak. Vytvoř operace Vlož a Vyber.
    - Použij je pro vypsání posledních N znaků vstupu předem neznámé délky.

## Output
```
======<<STACK>>=====
Enter braces to check: [ahoj{jak}je](?)
braces matched succesfully
======<<QUEUE>>=====
Enter number of last characters to print: 4
Enter the characters: lolahoj
ahoj
```