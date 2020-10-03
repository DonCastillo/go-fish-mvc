#include <iostream>
#include "Deck.h"
#include "Card.h"

using namespace std;

int main()
{
    Deck* deck = new Deck();
    std::cout << (deck->getDeck()).size();
    deck->shuffle();
    for(Card* c : deck->getDeck())
    {
        std::cout << c->getSuit() << "-" << c->getRank() << std::endl;
    }
    //std::cout << "Heelo";
}
