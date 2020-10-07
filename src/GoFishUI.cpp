#include "GoFishUI.h"
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

GoFishUI::GoFishUI() {}

GoFishUI::~GoFishUI() {}

/// format and print title
void GoFishUI::setTitle(std::string title) {
    std::cout << std::endl;
    title = " " + title;
    std::cout << std::setw(LINEWIDTH)
              << std::setfill(TITLEFILL)
              << title
              << std::endl;
}

/// format row
void GoFishUI::setRow(std::string left, std::string right) {
    std::cout << std::setfill(LINEFILL)
              << std::left
              << std::setw(LINEWIDTH/2)
              << left
              << std::setfill(LINEFILL)
              << std::right
              << std::setw(LINEWIDTH/2)
              << right
              << std::endl;
}

/// format row with index
void GoFishUI::setRow(int index, std::string left, std::string right) {
    std::cout << "["
              << std::setfill(' ')
              << std::right
              << std::setw(2)
              << index
              << "] ";
    std::cout << std::setfill(LINEFILL)
              << std::left
              << std::setw((LINEWIDTH/2) - 2)
              << left
              << std::setfill(LINEFILL)
              << std::right
              << std::setw((LINEWIDTH/2) - 2)
              << right
              << std::endl;
}

/// print cards
void GoFishUI::printCards(std::vector<Card*> pCards) {
    for (Card* c : pCards) {
        setRow(c->getSuit(), c->getRank());
    }
}

/// print score board
void GoFishUI::printScores(std::vector<Player*> players) {
    setTitle("SCORE BOARD");
    for (Player* p : players) {
        setRow(p->getName(), std::to_string(p->getScore()));
    }
}

/// print player turn notif
void GoFishUI::printPlayerTurn(Player* pPlayer) {
    std::cout << "It is your turn, "
              << pPlayer->getName()
              << "."
              << std::endl;
}


/// print congratulatory message
void GoFishUI::printCongratulate(Player* pPlayer) {
    std::cout << "Congratulations! "
              << pPlayer->getName()
              << " wins ."
              << std::endl;
}


/// print deck
void GoFishUI::printDeck(Deck* pDeck) {
    setTitle("CURRENT DECK");
    std::cout << "There are "
              << pDeck->getDeck().size()
              << " cards left."
              << std::endl;
    printCards(pDeck->getDeck());
}

/// print player hand
void GoFishUI::printPlayerHand(Player* pPlayer) {
    setTitle("PLAYER HAND");
    std::cout << pPlayer->getName()
              << "'s cards at hand:"
              << std::endl;
    printCards(pPlayer->getCardHand());
}

/// enter name
std::string GoFishUI::enterName() {
    std::string name;
    std::cout << "Enter Name: ";
    std::cin >> name;
    return name;
}

/// enter number of players
int GoFishUI::enterNumberOfPlayers() {
    int numOfPlayers = 0;
    std::cout << "How many players in this game?: ";
    std::cin >> numOfPlayers;
    return numOfPlayers;
}

/// print welcome message
void GoFishUI::printWelcome() {
    setTitle("GO FISH");
    std::cout << "Program created by Don Castillo"
              << std::endl;
}



/// print card choices and get the chosen card
Card* GoFishUI::selectCardFromHand(Player* pPlayer) {
    setTitle("SELECT CARD FROM HAND");

    // variables
    std::vector<Card*> playerCards = pPlayer->getCardHand();
    int index = -1;
    int minIndex = 0;
    int maxIndex = playerCards.size() - 1;

    // display options
    for (int i = minIndex; i <= maxIndex; ++i) {
        setRow(i, playerCards[i]->getSuit(), playerCards[i]->getRank());
    }

    // keep looping while answer is invalid
    do {
        std::cout << "Enter the card index: ";
        std::cin >> index;
    } while (index < minIndex || index > maxIndex);

    return playerCards[index];
}



/// print player choices and get the chosen player
Player* GoFishUI::selectPlayer(Player* currentPlayer,
                               std::vector<Player*> allPlayers) {
    setTitle("SELECT PLAYER");

    // variables
    int index = -1;
    int minIndex = 0;
    int maxIndex = allPlayers.size() - 1;
    int currentPlayerIndex;

    // display options
    for (int i = minIndex; i <= maxIndex; ++i) {
        if (allPlayers[i]->getID() != currentPlayer->getID()) {
            setRow(i, "...", allPlayers[i]->getName());
        } else {
            currentPlayerIndex = i;
        }
    }

    // keep looping while answer is invalid
    do {
        std::cout << "Enter the player index: ";
        std::cin >> index;
    } while (currentPlayerIndex == index ||
            index < minIndex || index > maxIndex);

    return allPlayers[index];
}
