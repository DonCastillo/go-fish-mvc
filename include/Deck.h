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

 private:
    enum suits { Clubs, Diamonds, Hearts, Spades };
    enum ranks { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
    void createDeck();
    std::vector<Card*> allCards;
};

#endif // DECK_H_INCLUDED
