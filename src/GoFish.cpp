#include "GoFish.h"
#include "Card.h"
#include "Deck.h"
#include "GoFishUI.h"
#include <time.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <utility>
#include "GoFishUI.h"


GoFish::GoFish() {
    //deck = new Deck();
}


GoFish::~GoFish() {
    delete deck;
    for (Player* p : players) {
        delete p;
    }
}

/// main game
void GoFish::startGame() {
    int numOfPlayers = 0;
    ui = new GoFishUI();
    ui->printWelcome();

    // get num of players
    numOfPlayers = ui->enterNumberOfPlayers();
    //std::cout << numOfPlayers << std::endl;

    // get player info
    int counter = 0;
    while(counter < numOfPlayers) {
        std::string name = ui->enterName();
        Player* p = new Player(name);
        addPlayer(p);
        ++counter;
    }


    std::cout << "...In Progress..." << std::endl;
}


Deck* GoFish::getDeck() {
    return deck;
}

std::vector<Player*> GoFish::getPlayers() {
    return players;
}


/// p1 = requestor, p2 = requestee
/// true if successful
/// if not, player fishes
bool GoFish::askCard(Player* p1, Player* p2) {
    Card* p1RequestedCard;
    Card* p2ProvidedCard;

    p1RequestedCard = p1->selectFromHand();
    if (p1RequestedCard == nullptr) {
        return false;
    }
    p2ProvidedCard = p2->removeCardHand(p1RequestedCard);
    if (p2ProvidedCard == nullptr) {
        return false;
    }
    p1->addCardHand(p2ProvidedCard);
    return true;
}


/// player picks card on top of stack
void GoFish::fish(Player* pPlayer) {
    pPlayer->addCardHand(deck->getTopCard());
}



/// add player
void GoFish::addPlayer(Player* pPlayer) {
    players.push_back(pPlayer);
}



/// distribute cards per player
void GoFish::deal() {
    // how many cards to give per player
    int numOfPlayers = players.size();
    int numOfCards;
    if (numOfPlayers <= 3 && numOfPlayers >= 2) {
        numOfCards = 7;
    } else {
        numOfCards = 5;
    }

    // card distribution
    for (int i = 0; i < numOfCards; ++i) {
        for (Player* p : players) {
            fish(p);
        }
    }
}


/// if yes, remove cards from hand, and returjnn true
/// otherwise, return false
bool GoFish::isThereABook(Player* pPlayer) {
    std::map<std::string, std::vector<int>> board;
    std::map<std::string, std::vector<int>>::iterator itr;
    std::vector<Card*> playerCards = pPlayer->getCardHand();
    bool hasBook = false;


    for (Card* c : playerCards) {
        bool proceed = true;

        // check if c->getRank() is unique in the map
        for (itr = board.begin(); itr != board.end(); ++itr) {
            if ( c->getRank() == itr->first ) {
                proceed = false;
                break;
            } else {
                proceed = true;
            }
        }

        // instert unique key to the map
        if (proceed) {
            std::vector<int> indexes;
            for (int i = 0; i < playerCards.size(); ++i) {
                if (c->getRank().compare(playerCards[i]->getRank()) == 0) {
                    indexes.push_back(i);
                }
            }
            board.insert(std::pair<std::string,
                         std::vector<int>>(c->getRank(), indexes));
        }
    }


    // check if there is a book
    for (itr = board.begin(); itr != board.end(); ++itr) {
        // if there are 4 cards with same ranks, remove card
        // from player and add points
        if (itr->second.size() == 2) {
            for (int n : itr->second) {
                pPlayer->removeCardHand(playerCards[n]);
            }
            hasBook = true;
        }
    }
    return hasBook;
}


















