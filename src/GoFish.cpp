#include "GoFish.h"
#include "Card.h"
#include "Deck.h"
#include <vector>

GoFish::GoFish() {
    deck = new Deck();
    // todo: asks for player input e.g. name
}

GoFish::~GoFish() {
    delete deck;
    for(Player* p : players) {
        delete p;
    }
}

Deck* GoFish::getDeck() {
    return deck;
}

std::vector<Player*> GoFish::getPlayers() {
    return players;
}


/// check if the card picked from deck has a matching card in the player's hand
/// true/false
//bool GoFish::fish(Player* pPlayer, Deck* pDeck) {
//
//}
//
Card* GoFish::drawCard(Player* pPlayer) {
    pPlayer->addCard(deck->getTopCard());
}




void GoFish::addPlayer(Player* pPlayer) {
    players.push_back(pPlayer);
}



// max players: 7
void GoFish::deal() {
    // how many cards to give per player
    int numOfPlayers = players.size();
    int numOfCards;
    if(numOfPlayers <= 3 && numOfPlayers >= 2) {
        numOfCards = 7;
    } else {
        numOfCards = 5;
    }

    // card distribution
    for(int i = 0; i < numOfCards; ++i) {

    }

}













