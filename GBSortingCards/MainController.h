// author: chris-scientist
// created at: 27/07/2019

#ifndef SHUFFLING_MAIN_CONTROLLER
#define SHUFFLING_MAIN_CONTROLLER

#include <Gamebuino-Meta.h>

#include "DeckModel.h"
#include "DeckView.h"
#include "CardModel.h"
#include "DeckShuffle.h"

class MainController {
  private:
    DeckModel * deck;
    DeckView * deckView;
    DeckShuffle * deckShuffle;
    void debug();
    uint8_t dbgOffset;
  public:
    MainController(DeckModel * aDeck, DeckView * aDeckView, DeckShuffle * aShuffleAlgo);
    void run();
};

#endif
