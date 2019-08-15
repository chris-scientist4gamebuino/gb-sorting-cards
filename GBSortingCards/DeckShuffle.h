// author: chris-scientist
// created at: 28/07/2019

#ifndef SHUFFLING_DECK_SHUFFLE
#define SHUFFLING_DECK_SHUFFLE

#include <Gamebuino-Meta.h>

#include "DeckModel.h"

class DeckShuffle {
  private:
    uint8_t nbShuffle;
    DeckModel * deck;
  public:
    DeckShuffle(DeckModel * aDeck);
    void run();
    const uint8_t getNbShuffle() const;
};

#endif
