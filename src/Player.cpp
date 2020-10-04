#include "Player.h"
#include "Card.h"
#include <vector>
#include <string>


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

void Player::addCard(Card* c) {
    hand.push_back(c);
}

void Player::removeCard(Card* c) {
    for(int i = 0; i < hand.size(); ++i) {
        if(hand[i]->getSuit() == c->getSuit()) {
            if(hand[i]->getRank() == c->getRank()) {
                hand.erase(hand.begin() + i);
            }
        }
    }
}

std::vector<Card*> Player::getCards() {
    return hand;
}

