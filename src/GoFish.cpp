#include "GoFish.h"
#include "Card.h"
#include "Deck.h"
#include "GoFishUI.h"
#include "Player.h"
#include "Randomize.h"
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <utility>


GoFish::GoFish() {}


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
    } while (numOfPlayers < 2 || numOfPlayers > 5);

    // get player info
    for (int i = 0; i < numOfPlayers; ++i) {
        std::string name = ui->enterName();
        Player* p = new Player(i, name);
        addPlayer(p);
        ui->println("Adding a player...");
    }

    // initialize deck and shuffle deck
    deck = new Deck();

    // distribute cards to players
    deal();
    ui->println("Cards have been dealt.");
    ui->printDeck(deck);
    ui->printScores(players);

    // keep playing while current deck isnt empty
    // and at least 1 player still has cards
    Player* currentPlayer = getRandomPlayer();
    ui->println("Current player's been selected!");

    while (!deck->getDeck().empty() && anyoneHasCard()) {
        bool proceed = true;
        bool hasNotFished = true;
        ui->printPlayerTurn(currentPlayer);
        ui->println("Current deck has " +
                    std::to_string(deck->getDeck().size()) + " cards left.");

        /*********/
        while (proceed) {
            if (!(currentPlayer->getCardHand()).empty()) {
                // proceed as normal

                /// todo: check first to see if player's hand is not empty
                /// if yes, proceed
                /// it no, fish, then proceed
                ui->println(currentPlayer->getName() +
                            ": Checking for a book...");

                if (isThereABook(currentPlayer)) {
                    /// IF THE PLAYER HAS A BOOK
                    currentPlayer->updateScore(1);
                    ui->println(currentPlayer->getName() +
                                ": A book has been found!");
                    ui->println(currentPlayer->getName() +
                                ": I earned a point");
                    ui->printScores(players);
                    proceed = true;
                    continue;   // re-loop

                } else {
                    /// IF THE PLAYER DOESNT HAVE ANY BOOK
                    ui->println(currentPlayer->getName() + ": No book found.");

                    if (hasNotFished) {
                        // print all players hands (for testing)
                        ui->println("Showing all player's hands...");
                        for (Player* p : players) {
                            ui->printPlayerHand(p);
                        }

                        // select a card from hand
                        Card* selectedCard;
                        selectedCard = ui->selectCardFromHand(currentPlayer);
                        ui->println(currentPlayer->getName() +
                                    ": I have chosen the card:");
                        ui->setRow(selectedCard->getSuit(),
                                   selectedCard->getRank());

                        // select player
                        Player* selectedPlayer;
                        selectedPlayer = ui->selectPlayer(currentPlayer,
                                                          players);
                        ui->println(currentPlayer->getName() +
                                    ": I chose " +
                                    selectedPlayer->getName());

                        // ask the selectedPlayer for a card,
                        // add the matching cards to the currentPlayer's
                        ui->println(currentPlayer->getName() +
                                    ": Hey " + selectedPlayer->getName() +
                                    ", do you have a");
                        ui->println("card with a rank of " +
                                    selectedCard->getRank());

                        bool hasMatch = askCard(currentPlayer,
                                                selectedPlayer,
                                                selectedCard);

                        if (hasMatch) {
                            // with match
                            ui->println(currentPlayer->getName() +
                                ": I got at least one matching card from " +
                                selectedPlayer->getName());
                            proceed = true;
                            continue; // re-loop

                        } else {
                            // no match
                            ui->println(currentPlayer->getName() +
                                        ": I got no matching card from " +
                                        selectedPlayer->getName());
                            ui->println(selectedPlayer->getName() + ": " +
                                        currentPlayer->getName() +
                                        ", go fish!");

                            // fish
                            ui->println(currentPlayer->getName() +
                                        ": I'm fishing...");
                            fish(currentPlayer);

                            hasNotFished = false;
                            proceed = true;
                            continue; // re-loop
                        }
                    } else {
                        // if the has fished and no more books are found
                        proceed = false;
                        break;
                    }
                }
                // proceed as normal
            } else {
                fish(currentPlayer);
                continue;
            }
        }
        /*********/

        // determine currentPlayer index from the players vector
        int currentPlayerIndex = -1;
        for (int i = 0; i < numOfPlayers; ++i) {
            if (players[i]->getID() == currentPlayer->getID()) {
                currentPlayerIndex = i;
            }
        }

        // change player turn
        int nextPlayerIndex = (currentPlayerIndex + 1) % numOfPlayers;
        currentPlayer = players[nextPlayerIndex];
    }

    // identify winners
    for (Player* p : getWinner()) {
        ui->printCongratulate(p);
    }
}


std::vector<Player*> GoFish::getWinner() {
    int maxScore = -1;
    std::vector<Player*> winners;

    // determine highest scores
    for (Player* p : players) {
        if (p->getScore() > maxScore) {
            maxScore = p->getScore();
        }
    }

    // determine who gets the highest scores
    for (Player* p : players) {
        if (p->getScore() == maxScore) {
            winners.push_back(p);
        }
    }

    return winners;
}

/// get any random player
Player* GoFish::getRandomPlayer() {
    Player* tempPlayer = nullptr;
    if (!players.empty()) {
        int randPlayer = Randomize::randomize(0, players.size() - 1);
        tempPlayer = players[randPlayer];
    }
    return tempPlayer;
}


Deck* GoFish::getDeck() {
    return deck;
}

std::vector<Player*> GoFish::getPlayers() {
    return players;
}

/// check if anybody has at least one card in their hands
bool GoFish::anyoneHasCard() {
    for (Player* p : players) {
        if (!p->getCardHand().empty())
            return true;
    }
    return false;
}


/// p1 = requestor, p2 = requestee
/// true if successful
/// if not, player fishes
bool GoFish::askCard(Player* p1, Player* p2, Card* targetCard) {
    bool hasMatch = false;
    std::vector<Card*> matchingCards;

    // get all matching cards from requestee
    for (Card* c : p2->getCardHand()) {
        //bool matchedSuit = c->getSuit() == targetCard->getSuit();
        bool matchedRank = c->getRank() == targetCard->getRank();

        if (matchedRank) {
           matchingCards.push_back(p2->removeCardHand(c));
           hasMatch = true;
        }
    }

    // add all matching cards to requestor's hand
    for (Card* c : matchingCards) {
        p1->addCardHand(c);
    }

    ui->println(p1->getName() + " got " +
                std::to_string(matchingCards.size()) +
                " matching cards from " +
                p2->getName());

    return hasMatch;
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

    // iterate through player's cards
    for (Card* c : playerCards) {
        bool proceed = true;

        // check if c->getRank() is unique in the map
        for (itr = board.begin(); itr != board.end(); ++itr) {
            if ( c->getRank() == itr->first ) {
                proceed = false;
                break; // exit this look
            } else {
                proceed = true;
            }
        }

        // instert unique key to the map
        if (proceed) {
            std::vector<int> indexes;
            for (int i = 0; i < playerCards.size(); ++i) {
                if (c->getRank() == playerCards[i]->getRank()) {
                    indexes.push_back(i);
                }
            }
            board.insert(std::pair<std::string,
                         std::vector<int>>(c->getRank(), indexes));
            indexes.clear();
        }
    }


    // check if there is a book
    for (itr = board.begin(); itr != board.end(); ++itr) {
        // if there are 4 cards with same ranks, remove card
        // from player and add points
        if (itr->second.size() == 4) {
            for (int n : itr->second) {
                //Card* thisCard = playerCards[n];[*]
                Card* thisCard = pPlayer->removeCardHand(playerCards[n]);
                books.push_back(thisCard);
                //pPlayer->removeCardHand(playerCards[n]);[*]
            }
            hasBook = true;
        }
    }
    return hasBook;
}
