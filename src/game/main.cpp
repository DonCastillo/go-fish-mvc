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
    Card* a = new Card(0,1); // clubs, ace
    Card* b = new Card(0,2); // clubs, 2
    Card* c = new Card(0,3); // clubs, 3
    Card* d = new Card(0,4); //clubs, 4
    player->addCard(a);
    player->addCard(b);
    player->addCard(c);
    player->addCard(d);
    player->removeCard(new Card(0,3));
    for(Card* h : player->getCards()){
        std::cout << h->getSuit() << "--" << h->getRank() << std::endl;
    }
}
