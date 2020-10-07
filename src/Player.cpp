#include "Player.h"
#include "Card.h"
#include <time.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>


Player::Player(int pID, std::string pName) {
    id = pID;
    name = pName;
}

Player::~Player() {
    for (Card* h : hand) {
        delete h;
    }
}

/// add/subtract score based on the adder
/// if negative or 0, do nothing
/// if positive, add score
void Player::updateScore(int adder) {
    if (adder > 0) {
        score = score + adder;
    }
}

/// get name
std::string Player::getName() {
    return name;
}

/// getID
int Player::getID() {
    return id;
}

/// get current score
int Player::getScore() {
    return score;
}

/// add a card to the player's hand
void Player::addCardHand(Card* c) {
    hand.push_back(c);
}

/// return card the matches the card passed
/// original card is removed and returned
Card* Player::removeCardHand(Card* c) {
    Card* cardTemp = nullptr;
    for (int i = 0; i < hand.size(); ++i) {
        if (hand[i]->getSuit() == c->getSuit()) {
            if (hand[i]->getRank() == c->getRank()) {
                cardTemp = hand[i];
                hand.erase(hand.begin() + i);
            }
        }
    }
    return cardTemp;
}

/// get all the cards from the player's hands
/// number of cards depends on the the type of card game
std::vector<Card*> Player::getCardHand() {
    return hand;
}

/// randomly select a card from the hand
/// todo use rand_r instead of rand
/// not randomly
/// choice based on card as parameter
Card* Player::selectFromHand() {
    Card* tempCard = nullptr;
    if (!hand.empty()) {
        std::srand(time(0));
        int randNum = rand()%hand.size();
        tempCard = hand[randNum];
    }
    return tempCard;
}

