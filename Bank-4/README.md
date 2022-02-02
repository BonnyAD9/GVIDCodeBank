# Bank-4

## Zadání
Pomocí podprogramů zpracuj soubor se strukturovanými daty, kde na každém řádku je záznam o sopkách – název (20 znaků), výška (v metrech), zda je aktivní (ano/ne). Počet uložených záznamů není předem znám. Názvy souborů musí zadávat uživatel (dotazem nebo přes parametry příkazového řádku).
- Vytvoř funkci vracející průměrnou výšku všech ne/aktivních sopek (vybere se parametrem).
- Vypiš názvy všech sopek vyšších než hodnota zadaná parametrem. U každého názvu vypiš, zda je sopka aktivní, či ne.
- Zapiš do výstupního souboru všechny záznamy pouze o ne/aktivních sopkách (zadej parametrem). Vytvoř jeden soubor se záznamy o aktivních a druhý se záznamy o neaktivních sopkách. Výstupní soubory musí zachovávat formát vstupního souboru.

## Output
```
PS > .\Bank-4.exe data.txt avg
average height: 7.650000
PS > .\Bank-4.exe data.txt -y avg
average height: 5.300000
PS > .\Bank-4.exe data.txt -n avg
average height: 10.000000
PS > .\Bank-4.exe data.txt higher 5.3
nazev 1              10.000000 no
PS > .\Bank-4.exe data.txt -y higher 5.3
PS > .\Bank-4.exe data.txt -n higher 5.3
nazev 1              10.000000 no
PS > .\Bank-4.exe data.txt list all.txt active.txt inactive.txt
```
### data.txt
```
nazev 1              10 no
druhy nazev          5.3 yes
```
### all.txt
```
nazev 1              10.000000 no
druhy nazev          5.300000 yes

```
### active.txt
```
druhy nazev          5.300000 yes

```
### inactive.txt
```
nazev 1              10.000000 no

```
