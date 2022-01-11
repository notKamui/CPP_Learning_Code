# TP1 - Introduction au C++

## Exercice 1 - Compilation et exécution

1. Un langage compilé est beaucoup plus efficace qu'un langage interprété car il est directement traduit en langage machine optimisé pour le système sur lequel il a été compilé. Cependant, un programme dans un langage compilé doit être compilé pour chaque système sur lequel on veut le faire tourner, contrairement à un langage interprété (ou semi interprété) où c'est seulement l'interpréteur qui doit être compilé pour chaque système. Un langage compilé demande aussi une recompilation complète du programme quand une dépendance change ou est mise à jour. Un langage compilé implique souvent un contrôle plus fin de la mémoire et de la gestion du système (C'est aussi un inconvénient car dangereux entre de mauvaises mains).

2. Une erreur de compilation se produit... à la compilation !; et n'a aucune chance de survenir durant l'execution du programme, contrairement aux erreurs d'exécution. Une erreur de compilation survient lorsque l'on ne respecte pas la syntaxe ou la grammaire du langage, voir sa sémantique. Les erreurs d'exécution sont tout le reste (problème de mémoire, division par zero, parsing incorrect, etc). Ces dernières peuvent (souvent) être gérées avec des exceptions ; la seule facon de les rencontrer sont...de les rencontrer, c'est dur à éviter sauf si on sait prévoire avec de l'expérience.

3. UB signifie que l'on exécute du code dont le résultat ou l'effet n'est pas défini par le standard C++ (ex: `short x = 0x10000` -> on ne sait pas ce que ça vaut quand on assigne une valeur supérieure à la taille de la variable) ; et ca compile parfaitement, mais on peut alors parfois tomber sur des erreurs de segmentation.

## Exercice 2 - Primitives et initialisation

1.

- `const short s1` : un const doit être immédiatement initialisé
- `bool b3{i1}` : on ne sait pas convertir un entier en booléen
- `char c8{"a"}` : car on ne sait pas convertir une chaîne de caractères en un seul caractère
- `double& d12` : car on doit initialiser une référence
- `int& i16 = b2` : b2 est bien converti en `int` temporaire, mais pas `int&`

Avec -Wall -W -Werror :

- `short s0` : s0 n'est jamais utilisé
- `bool b4` : b4 n'est jamais utilisé
- `bool b7` : b7 n'est jamais utlilisé
- ...
- `int& i15 = i1` : i1 est un `const int`, et on le converti en référence ; ca marche mais c'est dangereux puisque c'est souvent pas ce qu'on veut (non mutable vers mutable).

2. s0 et ul7 ont des valeurs indéfinies (us6 = -10 -> OOB -> UB)

## Exercice 3 - Les fonctions et leurs paramètres

1.

```cpp
#include <iostream>

int add(const int a, const int b) {
  return a + b;
}

void add_to(int& a, const int b) {
  a += b;
}

int main() {
  const int x{10};
  int y = add(x, x);
  add_to(y, 22);
  std::cout << y << std::endl;
  return 0;
}
```

2. L'intéret de passer par référence est que cela évite de copier le contenu de la variable (très couteux quand c'est une liste par exemple) ; cependant, parfois on veut éviter quand même que cette variable soit modifiée, enquel cas on préfèrera une référence constante.

3.

```cpp
// Return the number of occurrences of 'a' found in string 's'.
int count_a_occurrences(const std::string& s);

// Update function of a rendering program.
// - dt (delta time) is read by the function to know the time elapsed since the last frame.
// - errors is a string filled by the function to indicate what errors have occured.
void update_loop(const float dt, std::string& errors_out);

// Return whether all numbers in 'values' are positive.
// If there are negative values in it, fill the array 'negative_indices_out' with the indices
// of these values and set its size in 'negative_count_out'.
// ex: auto res = are_all_positive({ 1, -2, 3, -4 }, negative_indices, negative_count);
//    -> res is false, since not all values are positive
//    -> negative_indices contains { 1, 3 } because values[1] = -2 and values[3] = -4
//    -> negative_count is 2
bool are_all_positives(const std::vector<int>& values, int& negative_indices_out[], size_t& negative_count_out);

// Concatenate 'str1' and 'str2' and return the result.
// The input parameters are not modified by the function.
std::string concatenate(const std::string& str1, const std::string& str2);
```

## Exercice 4 - `std::string` et `std::vector`

Voir strvect.cpp
