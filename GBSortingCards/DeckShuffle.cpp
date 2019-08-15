// author: chris-scientist
// created at: 28/07/2019

#include "DeckShuffle.h"

DeckShuffle::DeckShuffle(DeckModel * aDeck) {
  deck = aDeck;
  nbShuffle = 0;
}

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

const uint8_t DeckShuffle::getNbShuffle() const {
  return nbShuffle;
}
