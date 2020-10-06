#include "GoFishUI.h"
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include <vector>
#include <iostream>


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

void GoFishUI::congratulate(Player* pPlayer) {
    std::cout << "Congratulations! " << pPlayer->getName() << " wins ." << std::endl;
}

void GoFishUI::printDeck(Deck* pDeck) {
    printCards(pDeck->getDeck());
}

void GoFishUI::printPlayerHand(Player* pPlayer) {
    std::cout << pPlayer->getName() << "'s cards at hand:" << std::endl;
    printCards(pPlayer->getCardHand());
}
