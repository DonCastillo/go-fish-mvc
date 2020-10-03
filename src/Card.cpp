#include "Card.h"
#include <iostream>

Card::Card(int s, int r) {
    suitNum = s;
    rankNum = r;
    //std::cout << s << " " << r << std::endl;
}

Card::~Card() { }
