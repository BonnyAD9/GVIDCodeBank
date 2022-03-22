# Bank-20

## Zadání
Pomocí podprogramů zpracuj tři soubory (zadá uživatel) po znacích.
- Dva vstupní soubory obsahují seřazené posloupnosti znaků. Sluč je do třetího výstupního souboru tak, aby v něm byly všechny znaky také seřazeny.
- Dva vstupní soubory obsahují znaky. Sluč je do třetího výstupního souboru tak, aby v něm byly znaky seřazeny po dvojicích.
- Vstupní soubor obsahuje posloupnost znaků. Rozděl je po N-ticích do dvou výstupních souborů (N je parametr).

## Output

### Combine
```
PS > ./bank-20 combine sorted1.txt sorted2.txt out1.txt
success
```
#### sorted1.txt
```
akopruwz
```

#### sorted2.txt
```
bceilmqstuy
```

#### out1.txt
```
abceiklmopqrstuuwyz
```

### Tuple
```
PS > ./bank-20 tuple random1.txt random2.txt out2.txt
success
```

#### random1.txt
```
bfalizgvalshjvdg
```

#### random2.txt
```
vbaipub,yhxbvi
```

#### out2.txt
```
bvbfaailipuzbg,vayhlsxbhjvivdig
```

### Split
```
PS > ./bank-20 split random1.txt out3.txt out4.txt 3
success
```

#### random1.txt
```
bfalizgvalshjvdg
```

#### out3.txt
```
bfagvajvd
```

#### out4.txt
```
lizlshg
```