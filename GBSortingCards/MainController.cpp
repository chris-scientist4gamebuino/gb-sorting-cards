// author: chris-scientist
// created at: 27/07/2019

#include "MainController.h"

MainController::MainController(DeckModel * aDeck, DeckView * aDeckView, DeckShuffle * aShuffleAlgo) {
  deck = aDeck;
  deckView = aDeckView;
  deckShuffle = aShuffleAlgo;
  dbgOffset = 0;
}

void MainController::run() {
  //debug();
  
  if(gb.buttons.pressed(BUTTON_LEFT)) {
    deckView->prevouisPage();
  } else if(gb.buttons.pressed(BUTTON_RIGHT)) {
    deckView->nextPage();
  } else if(gb.buttons.pressed(BUTTON_A)) {
    deckShuffle->run();
  }
  
  deckView->paint(deckShuffle->getNbShuffle());
}

void MainController::debug() {
  if(gb.buttons.pressed(BUTTON_LEFT) || gb.buttons.pressed(BUTTON_RIGHT)) {
    dbgOffset = (dbgOffset > 0 ? 0 : 40);
  }

  gb.display.clear();
  uint8_t n = dbgOffset;
  for(uint8_t r = 0 ; r < 10 ; r++) {
    for(uint8_t c = 0 ; c < 4 ; c++) {
      if(n < 52) {
        gb.display.print(deck->getCard(n));
        gb.display.print(" ");
        /*gb.display.print(CardModel::getHeight(deck->getCard(n)));
        gb.display.print(",");
        gb.display.print(CardModel::getColor(deck->getCard(n)));
        /*uint8_t card = deck->getCard(n);
        gb.display.print(card % 13);
        gb.display.print(",");
        uint8_t colorCard = 3;
        if(card < 13) {
          colorCard = 0;
        } else if(card < 26) {
          colorCard = 1;
        } else if(card < 39) {
          colorCard = 2;
        }
        gb.display.print(colorCard);*/
        gb.display.print(" ");
        n++;
      }
    }
    gb.display.println("");
  }
}
