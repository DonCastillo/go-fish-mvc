#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include <string>
#include "Card.h"
#include <vector>

class Deck {
 public:
    Deck();
    ~Deck();
    std::vector<Card*> getDeck();
    void shuffle();
    void createDeck();
    Card* getTopCard();
    void clearDeck();

 private:
    enum suits { Club, Diamond, Heart, Spade };
    enum ranks { Ace = 1, Two, Three, Four, Five, Six,
                 Seven, Eight, Nine, Ten, Jack, Queen, King };
    std::vector<Card*> allCards;
};

#endif // DECK_H_INCLUDED
