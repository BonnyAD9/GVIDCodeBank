# Bank-12

## Zadání
Pomocí podprogramů vyřeš... Názvy souborů a dalších parametrů musí hlavní program
získat od uživatele (ze vstupu nebo z parametrů příkazového řádku).
- Vytvoř podprogram, který zpracuje vstupní soubor tak, že každý výskyt znaku # nahradí zadaným textovým řetězcem a výsledek zapíše do výstupního souboru.
- Vytvoř podprogram, který zkombinuje dva vstupní soubory tak, že bude do výstupního souboru zapisovat střídavě vždy jeden řádek z prvního a pak ze druhého souboru.
- Vytvoř podprogram, který zjistí počet slov na každém řádku vstupního souboru a tyto počty zapíše na odpovídající řádky výstupního souboru.
- Vstupní soubor obsahuje textově zapsaná celá čísla větší než nula. Na začátku jsou data seřazená vzestupně na konci je oblast přeplnění. Seřazenou oblast a oblast přeplnění odděluje řádek s hodnotou 0. Vytvoř funkci, která v tomto souboru efektivně vyhledá zadanou hodnotu a bude brát v úvahu jak seřazenou oblast, tak oblast přeplnění.

## Oputput

### in.txt
```
Koupil jsem si svoji oblíbenou
tyčinku #. Když jsem rozbaloval
svoji oblíbenou tyčinku # tak
mi spadla do kanálu a teď je
vše v pr#.
```

### in2.txt
```
1
2
5
12
19
46
107
0
56
15
6
69
48
48
21
198
```

### Replace

#### Console
```
PS > .\bank-12 in in.txt replace '#' by deli into out.txt
```

#### out.txt
```
Koupil jsem si svoji oblíbenou
tyčinku deli. Když jsem rozbaloval
svoji oblíbenou tyčinku deli tak
mi spadla do kanálu a teď je
vše v prdeli.
```

### Combine

#### Console
```
PS > .\bank-12 combine in.txt and in2.txt into out.txt
```

#### out.txt
```
Koupil jsem si svoji oblíbenou
1
tyčinku #. Když jsem rozbaloval
2
svoji oblíbenou tyčinku # tak
5
mi spadla do kanálu a teď je
12
vše v pr#.
19
46
107
0
56
15
6
69
48
48
21
198
```

### Count words

#### Console
```
PS > .\bank-12 count-words in in.txt into out.txt
```

#### out.txt
```
5
5
5
7
3
```

### Find

#### Console
```
PS > .\bank-12 find 69 in in2.txt
value '69' is on the position 12
```