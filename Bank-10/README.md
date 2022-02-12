# Bank-10

## Zadání
Pomocí podprogramů...
- Napiš funkce, které zpracují dvě 16 bitová celá dvojková čísla reprezentovaná v textových řetězcích znaky '0' a '1'. Cílem je demonstrovat, znalost toho, jak fungují logické a bitové operace, proto funkce nad textovými řetězci provedou
    - bitový součin
    - bitový součet
    - bitový exkluzivní součet (XOR)
    - bitový posun o N bitů (kladné N vpravo, záporné vlevo), vypadlé bity zahoď, nové nahrazuj nulami
    - bitovou rotaci o N bitů (kladné N vpravo, záporné vlevo)
    - aritmetický součet (přenos do vyššího řádu zahoď)
- Vstupní hodnoty pro předchozí funkce načítej ze standardního vstupu nebo příkazového řádku a do funkcí je předávej pomocí parametrů.

## Output
```
======<<BITS>>======
(16 character mark     :)      v
Enter number a: 0110101101001101
Enter number b: 0101101010011101
Enter amount to shift and rotate: -2
=======<<AND>>======
0100101000001101
=======<<OR>>=======
0111101111011101
=======<<XOR>>======
0011000111010000
======<<SHIFT>>=====
a >> -2 = 1010110100110100
b >> -2 = 0110101001110100
=====<<ROTATE>>=====
a |> -2 = 1010110100110101
b |> -2 = 0110101001110101
=======<<SUM>>======
1100010111101010
```