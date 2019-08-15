// author: chris-scientist
// created at: 27/07/2019

#ifndef SHUFFLING_DECK_VIEW
#define SHUFFLING_DECK_VIEW

#include <Gamebuino-Meta.h>

#include "SpritesManager.h"
#include "DeckModel.h"
#include "CardModel.h"

class DeckView {
  private:
    DeckModel * deck;
    uint8_t offset;
    void paintCard(const uint8_t aRow, const uint8_t aColumn, const uint8_t anIndexOfCard);
  public:
    DeckView(DeckModel * aDeck);
    void paint(const uint8_t aNbShuffle);
    void nextPage();
    void prevouisPage();
};

#endif
