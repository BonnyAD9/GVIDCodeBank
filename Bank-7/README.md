# Bank-7

## Zadání
Pomocí podprogramů vytvoř program
- Je dána množina znaků Σ (zadá uživatel). Napiš funkci, která ověří, zda se na vstupu/v textovém řetězci nachází pouze věta jazyka Σ* (případně Σ+) a vrátí pozici prvního místa, které již do zadaného jazyka nepatří. Pozice vstupu počítej od hodnoty 1 a v případě, že celý vstup patří do tohoto jazyka, vrať nulu.
- Vytvoř logickou funkci, která zjistí, zda v zadaném textovém řetězci/na vstupu odpovídá počet levých a pravých hranatých závorek []. Funkce musí zároveň ověřit, zda jsou závorky správně zanořeny. Například toto je správně „[a]b[ ][c[]d]e“, ale toto „a[b]c]d[e[f]g]“ správně není. Význam ostatních znaků neřeš.
- Vytvoř logickou funkci jako v minulé úloze, ale nevíc ber v úvahu i jiné typy závorek: kulaté (), složené {}, úhlové <>.

## Output
```
====<<CHAR SET>>====
Enter a char set: asůdohia
Enter a string: asdfhsaduilf
index of first character not in the set: 4
=====<<BRACES>>=====
Enter string to match square braces: a[ lk[ asdasd]Đ[]]
braces match
==<<MULTI BRACES>>==
Enter string to match braces: {dsadsa]
failed to match braces
```
