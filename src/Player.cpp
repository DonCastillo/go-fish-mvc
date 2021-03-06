/*!
   \file Player class implementation
   \brief implements the member data and methods of Player class
   \author Don Castillo
   \date 07/10/2020
*/

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
                break; // once a match is found, stop iteration
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

