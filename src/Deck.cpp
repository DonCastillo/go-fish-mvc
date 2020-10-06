#include "Deck.h"
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <vector>



Deck::Deck() {
    createDeck();
    shuffle();
}

Deck::~Deck() {
    for (unsigned int i = 0; i < allCards.size(); ++i) {
        delete allCards[i];
    }
}

/// get complete deck
std::vector<Card*> Deck::getDeck() {
    return allCards;
}

/// create a standard, unshuffled deck of cards
void Deck::createDeck() {
    clearDeck();
    for (int s = Club; s <= Spade; ++s) {
        for (int r = Ace; r <= King; ++r) {
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

/// remove top card from the Deck
Card* Deck::getTopCard() {
    Card* topCard = nullptr;

    if(!allCards.empty()) {
        topCard = allCards.back();
        allCards.pop_back();
        return topCard;
    }
    return topCard;
    //Card* topCard = allCards.pop_back();
    //return topCard;
}

/// clear or empty the deck
void Deck::clearDeck() {
    allCards.clear();
}
