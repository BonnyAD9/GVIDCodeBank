# Bank-13

## Zadání
Pomocí podprogramů vyřeš... Názvy souborů a dalších parametrů musí hlavní program
získat od uživatele (ze vstupu nebo z parametrů příkazového řádku).
- V textových souborech jsou textově uloženy dvě databázové tabulky. V první tabulce (souboru) jsou uloženy záznamy s atributy ID, jméno (10 znaků). Ve druhé tabulce (souboru) jsou uloženy záznamy s atributy ID_uživatele, e-mail (20 znaků). V první tabulce má ID charakter primárního klíče a ID_uživatele je cizí klíč odkazující do první tabulky. Napiš podprogram, který vypíše na řádky všechny emailové adresy uživatelů se zadaným jménem (parametr podprogramu). Na každém řádku výstupu budou tyto údaje ID, jméno, e-mail.
- V tabulce (souboru) jsou záznamy o sopkách s atributy název (20 znaků), výška (v metrech), zda je aktivní (ano/ne). Vytvoř podprogram pro výpis všech záznamů o nad/podprůměrně (parametr) vysokých ne/aktivních (parametr) sopkách.

## Output

### users.txt
```
f16a Petr
586d Hana
cf5a Tonda
```

### emails.txt
```
f16a petr.bajza@gmail.com
586d hana.best@gmail.com
f16a jumbo@outlook.cz
```

### Console
```
PS > .\bank-13 user Petr users.txt emails.txt
petr.bajza@gmail.com
jumbo@outlook.cz
user Petr with id f16a has 2 email adresses
PS > .\bank-13 user Hana users.txt emails.txt
hana.best@gmail.com
user Hana with id f16a has 1 email adress
PS > .\bank-13 user Tonda users.txt emails.txt
user Tonda with id f16a has no email adress
```