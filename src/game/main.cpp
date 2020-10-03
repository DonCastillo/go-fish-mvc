#include <iostream>
#include "Deck.h"

using namespace std;

int main()
{
    Deck* deck = new Deck();
    std::cout << (deck->getDeck()).size();
}
