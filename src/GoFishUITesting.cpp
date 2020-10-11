#include "GoFishUITesting.h"
#include "Randomize.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

GoFishUITesting::GoFishUITesting() {}

GoFishUITesting::~GoFishUITesting() {}

/// enter name
std::string GoFishUITesting::enterName() {
    return "Dummy";
}

/// enter number of players
int GoFishUITesting::enterNumberOfPlayers() {
    return 2;
}


/// print card choices and get the chosen card
Card* GoFishUITesting::selectCardFromHand(Player* pPlayer) {
    // variables
    std::vector<Card*> playerCards = pPlayer->getCardHand();

    // check if player's hand is empty or not
    if (!playerCards.empty()) {
        int randomIndex = Randomize::randomize(0, playerCards.size() - 1);
        return playerCards[randomIndex];
    }

    return nullptr; // if no card exist in the hand
}



/// print player choices and get the chosen player
Player* GoFishUITesting::selectPlayer(Player* currentPlayer,
                               std::vector<Player*> allPlayers) {
    // always select the first player
    if (!allPlayers.empty()) {
        std::vector<int> indexes;
        // collect all indexes aside from the player's
        for (int i = 0; i < allPlayers.size(); ++i) {
            if (currentPlayer->getID() != allPlayers[i]->getID()) {
                indexes.push_back(i);
            }
        }

        int randomIndex = Randomize::randomize(indexes);
        return allPlayers[randomIndex];
    }

    return nullptr;
}
