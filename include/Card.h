#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <string>

class Card {

 public:
    Card(int s, int r);
    ~Card();
    std::string getSuit();
    std::string getRank();
    //int rankNum;

 private:
    std::string cSuit;
    std::string cRank;
    std::string formatRank(int pRank);
    std::string formatSuit(int pSuit);

};

#endif // CARD_H_INCLUDED
