
# Mélanger des cartes / Documentation FR

## Présentation

* Langage : C++
* Plateforme : Gamebuino META
* Description : fonction pour mélanger un jeu de 52 cartes
* Fonction principale : `DeckShuffle->run`

## Commandes

Pendant l'affichage des cartes :

* Bouton Gauche / Droite : afficher le reste des cartes (sur 3 pages)
* Bouton A : effectuer une opération de mélange des cartes

## Explications

A chaque opération de mélange :

* On répartie les cartes selon quatre sous jeux de cartes.
* On assemble ses quatre sous jeux tel que le jeu de cartes résultant soit la concaténation du sous jeu 3, 2, 4, puis 1.

Voici un aperçu de deux opérations de mélanges :

![2 mélanges](img/mix_cards.png)

## Code de la fonction principale

```
void DeckShuffle::run() {
  uint8_t subSet1 [13] = {255,255,255,255,255,255,255,255,255,255,255,255,255};
  uint8_t subSet2 [13] = {255,255,255,255,255,255,255,255,255,255,255,255,255};
  uint8_t subSet3 [13] = {255,255,255,255,255,255,255,255,255,255,255,255,255};
  uint8_t subSet4 [13] = {255,255,255,255,255,255,255,255,255,255,255,255,255};
  uint8_t it1 = 0;
  uint8_t it2 = 0;
  uint8_t it3 = 0;
  uint8_t it4 = 0;
  // Mix cards
  for(uint8_t i = 0 ; i < 52 ; i++) {
    const uint8_t card = deck->getCard(i);
    const uint8_t s = i % 4;
    switch(s) {
      case 0:
        subSet1[it1] = card;
        it1++;
        break;
      case 1:
        subSet2[it2] = card;
        it2++;
        break;
      case 2:
        subSet3[it3] = card;
        it3++;
        break;
      case 3:
        subSet4[it4] = card;
        it4++;
        break;
    }
  }
  // Re-order cards
  uint8_t n = 0;
  for(uint8_t s = 0 ; s < 4 ; s++) {
    uint8_t * subSet = subSet1;
    switch(s) {
      case 0:
        subSet = subSet3;
        break;
      case 1:
        subSet = subSet2;
        break;
      case 2:
        subSet = subSet4;
        break;
    }
    for(uint8_t c = 0 ; c < 13 ; c++) {
      deck->setCard(n, subSet[c]);
      n++;
    }
  }
  // Statistic
  nbShuffle++;
}
```

Note : la dernière ligne `nbShuffle++;` n'est utile que pour ce programme de démonstration.
