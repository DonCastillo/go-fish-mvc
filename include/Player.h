#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>

class Player {

 public:
    Player(std::string pName);
    ~Player();
    void updateScore(int adder);
    int getScore();
    std::string getName();

 private:
    std::string name;
    int score = 0;

};

#endif // CARD_H_INCLUDED
