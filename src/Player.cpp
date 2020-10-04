#include "Player.h"
#include "Card.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include <algorithm>


Player::Player(std::string pName) {
    name = pName;
}

Player::~Player() {
    for(Card* h : hand) {
        delete h;
    }
}

void Player::updateScore(int adder) {
    score = score + adder;
}

std::string Player::getName() {
    return name;
}

int Player::getScore() {
    return score;
}

void Player::addCardHand(Card* c) {
    hand.push_back(c);
}

Card* Player::removeCardHand(Card* c) {
    Card* cardTemp = nullptr;
    for(int i = 0; i < hand.size(); ++i) {
        if(hand[i]->getSuit() == c->getSuit()) {
            if(hand[i]->getRank() == c->getRank()) {
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
Card* Player::selectFromHand() {
    Card* tempCard = nullptr;
    if(!hand.empty()) {
        std::srand(time(0));
        int randNum = rand()%hand.size();
        tempCard = hand[randNum];
        //removeCardHand(hand[randNum]);
    }
    return tempCard;
}

