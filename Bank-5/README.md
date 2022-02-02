# Bank-5

## Zadání
Pomocí podprogramů...
- Načítej ze vstupu hodnoty zapsané v šestnáctkové soustavě a oddělené bílými znaky a vracej jejich vyčíslenou hodnotu. V případě chyby vrať zápornou hodnotu a ukonči program. Vyčíslené hodnoty zapisuj na výstup, každou na jeden řádek.
- Vytvoř podprogram, který zapíše zadanou hodnotu na výstup ve zvolené číselné soustavě. Základ číselné soustavy a hodnota budou parametry podprogramu a zjisti je od uživatele. Počítej se základy od 2 do 36.
- Na vstupu jsou dvě celá čísla oddělená písmenem E, např. 124E-10. Načti je jako celá čísla a vrať desetinné číslo, které představují (předveď, že víš, co ten zápis představuje). V případě chyby vrať hodnotu NAN (Not A Number = 0.0/0.0). Nesmíš je načítat jako desetinné číslo. Získanou hodnotu vytiskni s přesností na 3 desetinná místa v semilogaritmickém tvaru.

## Output
```
===<<HEX VALUES>>===
Enter hex numbers to evaluate: abcd 123 F007
43981
291
61447
====<<NUM BASE>>====
Enter number: 43981
Enter base: 16
abcd
===<<SCIENTIFIC>>===
Enter number in scientific notation: 123E-10
1.230E-008
```
