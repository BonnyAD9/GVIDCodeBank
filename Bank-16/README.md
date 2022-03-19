# Bank-16

## Zadání
Pomocí podprogramů...
- Vytvoř funkci pro vyčíslení zadaného polynomu v daném bodě x pomocí Hornerova schématu.
- Vytvoř funkci pro nalezení kořene nelineární funkce (parametr) se zadanou přesností (parametr) na zadaném intervalu (parametry) pomocí
    - metody půlení intervalu
    - metody regula falsi
    - Newtonovy metody (bude zadána derivace vyšetřované funkce)
- Ověř funkčnost na polynomu <bude zadán> na intervalu <bude zadán>.

## Output
```
=====<<HORNER>>=====
Enter length of polynomial: 5
Enter coeficients: 1 2 3 4 -5
Enter number to use in the polynomial: 5
result of evaluated polynimial: 965.000000
==<<HALFING INTERVAL>>==
Enter interval: 0 5
solution: 0.683594
===<<RGULA FALSI>>==
solution: 0.683347
=====<<NEWTON>>=====
Enter derivation of the polynomial: 4 6 6 4
Enter starting number: 0
solution: 0.684572
```