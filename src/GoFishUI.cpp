#include "GoFishUI.h"
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include <vector>
#include <iostream>
#include <string>

GoFishUI::GoFishUI() {}

GoFishUI::~GoFishUI() {}

void GoFishUI::printCards(std::vector<Card*> pCards) {
    for (Card* c: pCards) {
        std::cout << c->getSuit() << "..." << c->getRank() << std::endl;
    }
}

void GoFishUI::printScores(std::vector<Player*> players) {
    for (Player* p : players) {
        std::cout << p->getName() << std::endl;
        std::cout << p->getScore() << std::endl;
    }
}

void GoFishUI::printPlayerTurn(Player* pPlayer) {
    std::cout << "It is your turn, " << pPlayer->getName() << "." << std::endl;
}

void GoFishUI::printCongratulate(Player* pPlayer) {
    std::cout << "Congratulations! " << pPlayer->getName() << " wins ." << std::endl;
}

void GoFishUI::printDeck(Deck* pDeck) {
    std::cout << std::endl;
    std::cout << "============== Current Deck ===============" << std::endl;
    std::cout << "There are " << pDeck->getDeck().size() << " cards left." << std::endl;
    printCards(pDeck->getDeck());
}

void GoFishUI::printPlayerHand(Player* pPlayer) {
    std::cout << std::endl;
    std::cout << "============== Player Hand ===============" << std::endl;
    std::cout << pPlayer->getName() << "'s cards at hand:" << std::endl;
    printCards(pPlayer->getCardHand());
}

std::string GoFishUI::enterName() {
    std::string name;
    std::cout << "Enter Name:" << std::endl;
    std::cin >> name;
    return name;
}

int GoFishUI::enterNumberOfPlayers() {
    int numOfPlayers = 0;
    std::cout << "How many players in this game?:" << std::endl;
    std::cin >> numOfPlayers;
    return numOfPlayers;
}

void GoFishUI::printWelcome() {
    std::cout << "========== GO FISH ============" << std::endl;
    std::cout << "Program created by Don Castillo" << std::endl;
}

Card* GoFishUI::selectCardFromHand(Player* pPlayer) {
    int index = -1;
    std::cout << "==== SELECT CARD FROM HAND ====" << std::endl;
    std::cout << "Enter the card index:" << std::endl;

    std::vector<Card*> playerCards = pPlayer->getCardHand();
    for (int i = 0; i < playerCards.size(); ++i) {
        std::cout << "[" << i << "] " << playerCards[i]->getSuit() << "..." << playerCards[i]->getRank() << std::endl;
    }
    std::cin >> index;
    return playerCards[index];
}
