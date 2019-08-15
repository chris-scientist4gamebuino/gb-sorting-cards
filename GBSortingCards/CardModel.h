// author: chris-scientist
// created at: 27/07/2019

#ifndef SHUFFLING_CARD_MODEL
#define SHUFFLING_CARD_MODEL

#include <Gamebuino-Meta.h>

class CardModel {
  public:
    static const uint8_t ACE_CARD = 12;
    static const uint8_t KING_CARD = 11;
    static const uint8_t QUEEN_CARD = 10;
    static const uint8_t JACK_CARD = 9;
    static const uint8_t C10_CARD = 8;
    static const uint8_t C9_CARD = 7;
    static const uint8_t C8_CARD = 6;
    static const uint8_t C7_CARD = 5;
    static const uint8_t C6_CARD = 4;
    static const uint8_t C5_CARD = 3;
    static const uint8_t C4_CARD = 2;
    static const uint8_t C3_CARD = 1;
    static const uint8_t C2_CARD = 0;

    static const uint8_t HEART_CARD = 0;
    static const uint8_t DIAMOND_CARD = 1;
    static const uint8_t CLOVER_CARD = 2;
    static const uint8_t SPADE_CARD = 3;
    
    static uint8_t getHeight(const uint8_t anIndexOfCard);
    static uint8_t getColor(const uint8_t anIndexOfCard);
  private:
};

#endif
