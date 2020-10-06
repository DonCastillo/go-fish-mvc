#include "Player.h"
#include "Card.h"
#include <time.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>


Player::Player(std::string pName) {
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

/// get current score
int Player::getScore() {
    return score;
}

/// get all the cards from the player's hands
/// number of cards depends on the the type of card game
void Player::addCardHand(Card* c) {
    hand.push_back(c);
}

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

std::vector<Card*> Player::getCardHand() {
    return hand;
}

/// randomly select a card from the hand
/// todo use rand_r instead of rand
Card* Player::selectFromHand() {
    Card* tempCard = nullptr;
    if (!hand.empty()) {
        std::srand(time(0));
        int randNum = rand()%hand.size();
        tempCard = hand[randNum];
    }
    return tempCard;
}

