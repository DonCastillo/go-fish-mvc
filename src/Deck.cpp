#include "Deck.h"
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <time.h>

Deck::Deck() {
    createDeck();
}

Deck::~Deck() {
    for(unsigned int i = 0; i < allCards.size(); ++i) {
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

///shuffle deck
void Deck::shuffle() {
    std::srand(time(0));
    std::random_shuffle(allCards.begin(), allCards.end());

}