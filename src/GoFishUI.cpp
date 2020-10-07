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

/// print any message
void GoFishUI::print(std::string message) {
    std::cout << message;
}

void GoFishUI::println(std::string message) {
    std::cout << message
              << std::endl;
}

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
    println("");
}

/// print player turn notif
void GoFishUI::printPlayerTurn(Player* pPlayer) {
    println("It is your turn, " + pPlayer->getName() + ".");
}


/// print congratulatory message
void GoFishUI::printCongratulate(Player* pPlayer) {
    println("Congratulations! " + pPlayer->getName() + " wins.");
}


/// print deck
void GoFishUI::printDeck(Deck* pDeck) {
    setTitle("CURRENT DECK");
    println("There are " + std::to_string(pDeck->getDeck().size()) + " cards left.");
    printCards(pDeck->getDeck());
}

/// print player hand
void GoFishUI::printPlayerHand(Player* pPlayer) {
    setTitle("PLAYER HAND");
    println(pPlayer->getName() + "'s cards at hand: ");
    printCards(pPlayer->getCardHand());
}

/// enter name
std::string GoFishUI::enterName() {
    std::string name;
    print("Enter Name: ");
    std::cin >> name;
    return name;
}

/// enter number of players
int GoFishUI::enterNumberOfPlayers() {
    int numOfPlayers = 0;
    print("How many players in this game?: ");
    std::cin >> numOfPlayers;
    return numOfPlayers;
}

/// print welcome message
void GoFishUI::printWelcome() {
    setTitle("GO FISH");
    println("Program created by Don Castillo");
}



/// print card choices and get the chosen card
Card* GoFishUI::selectCardFromHand(Player* pPlayer) {
    setTitle("SELECT CARD FROM HAND");
    println("Hand of " + pPlayer->getName() + ".");
    println("Select a card from your hand that you want \nto ask from another player.");

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
        print("Enter the card index: ");
        std::cin >> index;
    } while (index < minIndex || index > maxIndex);

    return playerCards[index];
}



/// print player choices and get the chosen player
Player* GoFishUI::selectPlayer(Player* currentPlayer,
                               std::vector<Player*> allPlayers) {
    setTitle("SELECT PLAYER");
    println("Select who to ask for the card just selected:");
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
        print("Enter the player index: ");
        std::cin >> index;
    } while (currentPlayerIndex == index ||
            index < minIndex || index > maxIndex);

    return allPlayers[index];
}
