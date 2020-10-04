#include "GoFish.h"
#include "Card.h"
#include "Deck.h"
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <iterator>

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
void GoFish::drawCard(Player* pPlayer) {
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
        for(Player* p : players) {
            drawCard(p);
        }
    }
}

/// if yes, remove cards from hand, and returjnn true
/// otherwise, return false
bool GoFish::isThereABook(Player* pPlayer) {

    std::map<std::string, std::vector<int>> board;
    std::map<std::string, std::vector<int>>::iterator itr;
    std::vector<Card*> playerCards = pPlayer->getCards();
    bool hasBook = false;


        for(Card* c : playerCards) {

            bool proceed = true;

            // check if c->getRank() is unique in the map
            for(itr = board.begin(); itr != board.end(); ++itr) {
                if( c->getRank() == itr->first ) {
                    proceed = false;
                    break;
                } else {
                    proceed = true;
                }
            }

            // instert unique key to the map
            if(proceed) {
                std::vector<int> indexes;
                for(int i = 0; i < playerCards.size(); ++i) {
                    if( (c->getRank()).compare(playerCards[i]->getRank()) == 0){
                        indexes.push_back(i);
                    }
                }
                board.insert(std::pair<std::string, std::vector<int>>(c->getRank(), indexes));
            }
        }


        // check if there is a book
        for(itr = board.begin(); itr != board.end(); ++itr) {
            // if there are 4 cards with same ranks, remove card from player and add points
            //std::cout << itr->second.size();
            if(itr->second.size() == 2) {
                for(int n : itr->second){
                    pPlayer->removeCard(playerCards[n]);
                }
                hasBook = true;
            }
        }
//        for (Card* g : pPlayer->getCards()) {
//            std::cout << g->getSuit() << "...." << g->getRank() << std::endl;
//        }
        return hasBook;
}


















