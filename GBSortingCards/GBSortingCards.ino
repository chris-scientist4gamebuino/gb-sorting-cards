// author: chris-scientist
// created at: 27/07/2019

#include <Gamebuino-Meta.h>
#include "MainController.h"
#include "DeckModel.h"
#include "DeckView.h"
#include "DeckShuffle.h"

MainController * mainController;
DeckModel * deckModel;

void setup() {
  gb.begin();
  deckModel = new DeckModel();
  mainController = new MainController(
    deckModel, 
    new DeckView(deckModel), 
    new DeckShuffle(deckModel)
  );
}

void loop() {
  gb.waitForUpdate();
  mainController->run();
}
