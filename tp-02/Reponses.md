# TP2 - Les classes en C++

## Exercice 1 - Les classes et instances

1. 17 et 17 sont affichés (La même valeur puisque la variable est statique)
2. La valeur est indéfinie (le programme ne compile pas avec -Wall -Werror)

## Exercice 2 - Les copies

1. On est obligé d'appeler le constructeur explicitement car sinon il y a ambiguité dans la grammaire (déclaration de fonction)
2. Ca ne compile plus car il maintenant il n'y a plus de constructeur par défaut
3. J'aurai pensé qu'il serait exécuté deux fois, mais il n'a en fait été exécuté qu'une fois