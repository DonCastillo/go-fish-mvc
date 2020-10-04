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
    Card* getTopCard();


 private:
    enum suits { Club, Diamond, Heart, Spade };
    enum ranks { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
    void createDeck();
    std::vector<Card*> allCards;
};

#endif // DECK_H_INCLUDED
