// author: chris-scientist
// created at: 27/07/2019

#include "DeckModel.h"

DeckModel::DeckModel() {
  initialize();
}

void DeckModel::initialize() {
  for(uint8_t c = 0 ; c < DECK_SIZE ; c++) {
    cards[c] = c;
  }
}

uint8_t DeckModel::getCard(uint8_t anIndex) {
  if( ! (anIndex >= 0 && anIndex < DECK_SIZE) ) {
    return 255;
  }
  return cards[anIndex];
}

bool DeckModel::setCard(const uint8_t anIndex, const uint8_t aCard) {
  if( ! (anIndex >= 0 && anIndex < DECK_SIZE) ) {
    return false;
  }
  cards[anIndex] = aCard;
  return true;
}
