#include "Player.h"
#include "Card.h"
#include <vector>


Player::Player(std::string pName) {
    name = pName;
}

Player::~Player() {

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
                hand.erase(hand.begin() + (i - 0));
            }
        }
    }
}

std::vector<Card*> Player::getCards() {
    return hand;
}

