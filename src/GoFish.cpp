#include "GoFish.h"
#include "Card.h"
#include "Deck.h"
#include "GoFishUI.h"
#include "Player.h"
#include <time.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <utility>


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


    do {
        numOfPlayers = ui->enterNumberOfPlayers();
    } while(numOfPlayers < 2 || numOfPlayers > 5);

    // get player info
    for(int i = 0; i < numOfPlayers; ++i) {
        //std::cout << "Hello" << std::endl;
        std::string name = ui->enterName();
        Player* p = new Player(i, name);
        addPlayer(p);
    }

    // initialize deck and shuffle deck
    deck = new Deck();

    // distribute cards to players
    deal();
    ui->printDeck(deck);
    ui->printScores(players);

    // keep playing while current deck isnt empty
    // and at least 1 player still has cards
    Player* currentPlayer = getRandomPlayer();
    while(!deck->getDeck().empty() && anyoneHasCard()){
        bool proceed = true;

        while(proceed){

            if (isThereABook(currentPlayer)) {

                // if player has any book
                currentPlayer->updateScore(1);
                continue;

            } else {

                // if player does not have any book
                // select from a card from hand
                Card* selectedCard;
                selectedCard = ui->selectCardFromHand(currentPlayer);

                //select player
                Player* selectedPlayer;
                selectedPlayer = ui->selectPlayer(currentPlayer, players);

                std::cout << selectedPlayer->getID() << "..." << selectedPlayer->getName() << std::endl;



                //std::cout << cd->getSuit() << "..." << cd->getRank() << std::endl;

            }

        }


    }

    //ui->printDeck(deck);


    /*for(Player* p : players){
        ui->printPlayerHand(p);
    }*/


//    std::cout << "...In Progress..." << std::endl;
}

/// get any random player
Player* GoFish::getRandomPlayer() {
    Player* tempPlayer = nullptr;
    if (!players.empty()) {
        std::srand(time(0));
        int randPlayer = rand()%players.size();
        tempPlayer = players[randPlayer];
    }
    return tempPlayer;
}

/// select player execept the one passed
//std::vector<Player*> GoFish::playersSelection(Player* pPlayer){
//    std::vector<Player*> tempPlayers;
//    for (Player* p : players) {
//        if (p->getID() != pPlayer->getID()) {
//            tempPlayers.push_back(p);
//        }
//    }
//    return tempPlayers;
//}

Deck* GoFish::getDeck() {
    return deck;
}

std::vector<Player*> GoFish::getPlayers() {
    return players;
}

/// check if anybody has at least one card in their hands
bool GoFish::anyoneHasCard(){
    for (Player* p : players) {
        if (!p->getCardHand().empty())
            return true;
    }
    return false;
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

    switch (numOfPlayers) {
        case 2:
        case 3:
            numOfCards = 7;
            break;
        case 4:
        case 5:
            numOfCards = 5;
            break;
        default:
            numOfCards = 5;
            break;
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
        if (itr->second.size() == 4) {
            for (int n : itr->second) {
                Card* thisCard = playerCards[n];
                books.push_back(thisCard);
                pPlayer->removeCardHand(playerCards[n]);
            }
            hasBook = true;
        }
    }
    return hasBook;
}


















