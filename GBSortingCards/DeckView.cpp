// author: chris-scientist
// created at: 28/07/2019

#include "DeckView.h"

DeckView::DeckView(DeckModel * aDeck) {
  deck = aDeck;
}

void DeckView::nextPage() {
  switch(offset) {
    case 0:
      offset = 18;
      break;
    case 18:
      offset = 36;
      break;
    default:
      offset = 0;
  }
}

void DeckView::prevouisPage() {
  switch(offset) {
    case 36:
      offset = 18;
      break;
    case 18:
      offset = 0;
      break;
    default:
      offset = 36;
  }
}

void DeckView::paint(const uint8_t aNbShuffle) {
  gb.display.clear(GREEN);

  uint8_t page = 1;
  if(offset == 18) {
    page = 2;
  } else if(offset == 36) {
    page = 3;
  }
  
  gb.display.setColor(WHITE);
  gb.display.print("  ");
  gb.display.print(page); // Number of page
  gb.display.print("/3 : ");
  gb.display.print(aNbShuffle); // Number of shuffling
  
  uint8_t n = offset;
  for(uint8_t r = 0 ; r < 3 ; r++) {
    for(uint8_t c = 0 ; c < 6 ; c++) {
      if(n < 52) {
        paintCard(r, c, deck->getCard(n));
        n++;
      }
    }
  }
}

void DeckView::paintCard(const uint8_t aRow, const uint8_t aColumn, const uint8_t anIndexOfCard) {
  const uint8_t totalMarginLeft = ( aColumn * ( SpritesManager::WIDTH_CARD + 2 ) ) + 8;
  const uint8_t totalMarginTop = ( aRow * ( SpritesManager::HEIGHT_CARD + 3 ) ) + 12;
  const uint8_t colorCard = CardModel::getColor(anIndexOfCard);
  const uint8_t heightCard = CardModel::getHeight(anIndexOfCard);

  // Paint card
  bool isRed = true;
  switch(colorCard) {
    case CardModel::HEART_CARD:
      gb.display.drawImage(totalMarginLeft, totalMarginTop, SpritesManager::getHeart());
      break;
    case CardModel::DIAMOND_CARD:
      gb.display.drawImage(totalMarginLeft, totalMarginTop, SpritesManager::getDiamond());
      break;
    case CardModel::CLOVER_CARD:
      isRed = false;
      gb.display.drawImage(totalMarginLeft, totalMarginTop, SpritesManager::getClover());
      break;
    case CardModel::SPADE_CARD:
      isRed = false;
      gb.display.drawImage(totalMarginLeft, totalMarginTop, SpritesManager::getSpade());
      break;
  }

  // Paint height of card
  gb.display.setColor(isRed ? RED : BLACK);
  const uint8_t x = totalMarginLeft + 6;
  const uint8_t y = totalMarginTop + 7;
  switch(heightCard) {
    case CardModel::ACE_CARD:
      gb.display.drawPixel(x, y);
      gb.display.drawPixel(x, y+2);
      gb.display.drawLine(x-1, y+1, x-1, y+4);
      gb.display.drawLine(x+1, y+1, x+1, y+4);
      break;
    case CardModel::KING_CARD:
      gb.display.drawLine(x-1, y, x-1, y+4);
      gb.display.drawPixel(x, y+2);
      gb.display.drawLine(x+1, y, x+1, y+1);
      gb.display.drawLine(x+1, y+3, x+1, y+4);
      break;
    case CardModel::QUEEN_CARD:
      gb.display.drawRect(x-1, y, 3, 4);
      gb.display.drawPixel(x, y+4);
      break;
    case CardModel::JACK_CARD:
      gb.display.drawLine(x+1, y, x+1, y+4);
      gb.display.drawLine(x-1, y+4, x, y+4);
      gb.display.drawPixel(x-1, y+3);
      break;
    case CardModel::C10_CARD:
      gb.display.drawRect(x-1, y, 3, 5);
      gb.display.drawLine(x-3, y+1, x-3, y+4);
      break;
    case CardModel::C9_CARD:
      gb.display.drawRect(x-1, y, 3, 3);
      gb.display.drawLine(x+1, y+3, x+1, y+4);
      gb.display.drawLine(x-1, y+4, x, y+4);
      break;
    case CardModel::C8_CARD:
      gb.display.drawRect(x-1, y, 3, 3);
      gb.display.drawRect(x-1, y+2, 3, 3);
      break;
    case CardModel::C7_CARD:
      gb.display.drawLine(x-1, y, x+1, y);
      gb.display.drawLine(x+1, y+1, x+1, y+4);
      break;
    case CardModel::C6_CARD:
      gb.display.drawLine(x-1, y, x+1, y);
      gb.display.drawPixel(x-1, y+1);
      gb.display.drawRect(x-1, y+2, 3, 3);
      break;
    case CardModel::C5_CARD:
      gb.display.drawLine(x-1, y, x+1, y);
      gb.display.drawPixel(x-1, y+1);
      gb.display.drawLine(x-1, y+2, x+1, y+2);
      gb.display.drawPixel(x+1, y+3);
      gb.display.drawLine(x-1, y+4, x+1, y+4);
      break;
    case CardModel::C4_CARD:
      gb.display.drawLine(x-1, y, x-1, y+2);
      gb.display.drawPixel(x, y+2);
      gb.display.drawLine(x+1, y+1, x+1, y+4);
      break;
    case CardModel::C3_CARD:
      gb.display.drawLine(x+1, y, x+1, y+4);
      gb.display.drawLine(x-1, y, x, y);
      gb.display.drawLine(x-1, y+2, x, y+2);
      gb.display.drawLine(x-1, y+4, x, y+4);
      break;
    case CardModel::C2_CARD:
      gb.display.drawLine(x-1, y, x+1, y);
      gb.display.drawPixel(x+1, y+1);
      gb.display.drawLine(x-1, y+2, x+1, y+2);
      gb.display.drawPixel(x-1, y+3);
      gb.display.drawLine(x-1, y+4, x+1, y+4);
      break;
  }
}
