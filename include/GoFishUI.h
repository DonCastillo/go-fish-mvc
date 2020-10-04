#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <vector>
#include "Card.h"

class Player {

 public:
    Player(std::string pName);
    ~Player();
    void updateScore(int adder);
    int getScore();
    std::string getName();
    void addCard(Card* c);
    void removeCard(Card* c);
    std::vector<Card*> getCards();


 private:
    std::string name;
    int score = 0;
    std::vector<Card*> hand;

};

#endif // CARD_H_INCLUDED