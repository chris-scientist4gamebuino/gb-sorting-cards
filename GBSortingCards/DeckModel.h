// author: chris-scientist
// created at: 28/07/2019

#ifndef SHUFFLING_DECK
#define SHUFFLING_DECK

#include <Gamebuino-Meta.h>

class DeckModel {
  public:
    static const uint8_t DECK_SIZE = 52;
    DeckModel();
    void initialize();
    uint8_t getCard(uint8_t anIndex);
    bool setCard(const uint8_t anIndex, const uint8_t aCard);
  private:
    uint8_t cards[DECK_SIZE] = {
      0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,
      0,0
    };
};

#endif
