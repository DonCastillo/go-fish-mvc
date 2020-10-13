/*!
   \file MockCard class header
*/
#ifndef MOCKCARD_H_INCLUDED
#define MOCKCARD_H_INCLUDED

#include <string>
#include "gmock/gmock.h"


class MockCard : public Card {
 public:
    explicit MockCard(int s, int r) :
        Card(s, r) {}
    virtual ~MockCard() {}

    MOCK_METHOD0(getSuit, std::string());
    MOCK_METHOD0(getRank, std::string());
    MOCK_METHOD1(formatRank, std::string(int pRank));
    MOCK_METHOD1(formatSuit, std::string(int pSuit));
};

#endif // MOCKCARD_H_INCLUDED
