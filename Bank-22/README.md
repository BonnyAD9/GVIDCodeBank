# Bank-22

## Zadání
Doplň program (bude k dispozici kostra programu) pro práci s binárním vyhledávacím stromem obsahujícím celočíselné klíče. Napiš podprogram pro
- nalezení minimálního / maximálního prvku ve stromu
- výpis klíčů seřazených vzestupně / sestupně
- přidání nového klíče do stromu
- nalezení zadaného klíče
- výpis všech klíčů menších / větších než zadaný klíč
- zrušení celého stromu
- zrušení listu
- výpočet váhy stromu (počtu prvků ve stromu)
- výpočet výšky stromu (největší vzdálenost kořen – list)

## Output
```
=======<<MIN>>======
Enter values of the tree: 64 354 35435 403 13 8485434 631 34354 3545 4 3 1 5 3 85 4 3
duplicate: 3
duplicate: 4
duplicate: 3
min: 1
=======<<MAX>>======
max: 8485434
=====<<INORDER>>====
1 3 4 5 13 64 85 354 403 631 3545 34354 35435 8485434
====<<INREVERSE>>===
8485434 35435 34354 3545 631 403 354 85 64 13 5 4 3 1
=======<<ADD>>======
Enter key to add: 10
1 3 4 5 10 13 64 85 354 403 631 3545 34354 35435 8485434
======<<FIND>>======
Enter key to find: 10
position fo the key in the tree: LLRR
=====<<SMALLER>>====
1 3 4 5
=====<<LARGER>>=====
13 64 85 354 403 631 3545 34354 35435 8485434
=====<<REMOVE>>=====
Enter key to remove: 10
1 3 4 5 13 64 85 354 403 631 3545 34354 35435 8485434
=====<<WEIGHT>>=====
count: 14
=====<<HEIGHT>>=====
depth: 7
=====<<DELETE>>=====
```