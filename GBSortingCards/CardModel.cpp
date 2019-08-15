// author: chris-scientist
// created at: 27/07/2019

#include "CardModel.h"

uint8_t CardModel::getHeight(const uint8_t anIndexOfCard) {
  return anIndexOfCard % 13;
}

uint8_t CardModel::getColor(const uint8_t anIndexOfCard) {
  uint8_t colorOfCard = SPADE_CARD;
  if(anIndexOfCard < 13) {
    colorOfCard = HEART_CARD;
  } else if(anIndexOfCard < 26) {
    colorOfCard = DIAMOND_CARD;
  } else if(anIndexOfCard < 39) {
    colorOfCard = CLOVER_CARD;
  }
  return colorOfCard;
}
