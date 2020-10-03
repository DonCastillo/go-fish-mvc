#include "Player.h"


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
