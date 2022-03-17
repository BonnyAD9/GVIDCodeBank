# Bank-14

## Zadání
Doplň program (bude k dispozici kostra programu) pro řešení soustav lineárních rovnic pomocí Gaussovy / Gauss-Jordanovy eliminační metod. Napiš podprogram pro
- přímý chod Gaussovy metody
- zjištění počtu řešení po přímém chodu Gaussovy metody
- kontrolu, zda je matice koeficientů ve tvaru po provedení přímého chodu Gaussovy metody
- provedení zpětného chodu na i-tém řádku (předpokládá se, že na dalších řádcích již výpočet proběhl)
- kontrolu, zda je matice koeficientů po přímém chodu Gauss-Jordanovy metody
- provedení zpětného chodu Gauss-Jordanovy metody
- atd.

## Output
```
===<<GEM FORWARD>>==
Enter file with matrix: test1.txt
the matrix:
3 4
5.000000 9.000000 8.000000 6.000000
3.000000 5.000000 9.000000 4.000000
1.000000 59.000000 6.000000 7.000000
after forward:
3 4
5.000000 9.000000 8.000000 6.000000
0.000000 -2.000000 21.000000 2.000000
0.000000 0.000000 -6050.000000 -630.000000
==<<GEM SOLUTIONS>>==
system of equations has single solution
==<<GEM AFTER FORWARD>>==
Enter file with matrix: test1.txt
the matrix:
3 4
5.000000 9.000000 8.000000 6.000000
3.000000 5.000000 9.000000 4.000000
1.000000 59.000000 6.000000 7.000000
matrix isn't after forward GEM
==<<GEM BACKWARD>>==
solution to the first system of equations:
x0 = 0.865289
x1 = 0.093388
x2 = 0.104132
==<<GJ AFTER FORWARD>>==
Enter file with matrix: test2.txt
the matrix:
3 4
2.000000 0.000000 0.000000 5.000000
0.000000 6.000000 0.000000 4.000000
0.000000 0.000000 1.000000 2.000000
matrix is after forward GJEM
==<<GJEM BACKWARD>>==
x0 = 2.500000
x1 = 0.666667
x2 = 2.000000
======<<ATD.>>======
```