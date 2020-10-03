#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Player.h"

using namespace std;

int main()
{
    Deck* deck = new Deck();
    //std::cout << (deck->getDeck()).size();
    deck->shuffle();
    for(Card* c : deck->getDeck())
    {
      //  std::cout << c->getSuit() << "-" << c->getRank() << std::endl;
    }

    Player* player = new Player("Don");
    std::cout << player->getName() << std::endl;
    player->updateScore(1);
    player->updateScore(-12);
    std::cout << player->getScore() << std::endl;
    //std::cout << "Heelo";
}
