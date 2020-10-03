#include "Deck.h"

Deck::Deck() {
    createDeck();
}

Deck::~Deck() {
    for(int i = 0; i < allCards.size(); ++i) {
        delete allCards[i];
    }
}

/// get complete deck
std::vector<Card*> Deck::getDeck() {
    return allCards;
}

/// create a standard, unshuffled deck of cards
void Deck::createDeck() {
    for(int s = Clubs; s <= Spades; ++s) {
        for(int r = Ace; r <= King; ++r) {
            Card* c = new Card(s, r);
            allCards.push_back(c);
        }
    }
}
