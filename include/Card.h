#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <string>

class Card {

 public:
    Card(int s, int r);
    ~Card();

 private:
    std::string cSuit;
    std::string cRank;
    int suitNum;
    int rankNum;
};

#endif // CARD_H_INCLUDED
