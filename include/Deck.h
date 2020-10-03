#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include <string>

class Deck {

 public:
    Deck();
    ~Deck();

 private:
    enum suits { Clubs, Diamonds, Hearts, Spades };
    enum ranks { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine Ten, Jack, Queen, King };
};

#endif // DECK_H_INCLUDED
