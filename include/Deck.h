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


 private:
    enum suits { Clubs, Diamonds, Hearts, Spades };
    enum ranks { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
    void createDeck();
    std::vector<Card*> allCards;
    int randomizer();
};

#endif // DECK_H_INCLUDED
