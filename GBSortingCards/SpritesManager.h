// author: chris-scientist
// created at: 28/07/2019

#ifndef SHUFFLING_SPRITES_MANAGER
#define SHUFFLING_SPRITES_MANAGER

#include <Gamebuino-Meta.h>

class SpritesManager {
  private:
    static bool heartInitialized;
    static Image heart;
    static bool diamondInitialized;
    static Image diamond;
    static bool cloverInitialized;
    static Image clover;
    static bool spadeInitialized;
    static Image spade;
  public:
    static const uint16_t WIDTH_CARD;
    static const uint16_t HEIGHT_CARD;

    static Image& getHeart();
    static Image& getDiamond();
    static Image& getClover();
    static Image& getSpade();
};

#endif
