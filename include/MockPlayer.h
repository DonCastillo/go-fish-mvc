#ifndef MOCKPLAYER_H_INCLUDED
#define MOCKPLAYER_H_INCLUDED

#include <string>
#include <vector>
#include "gmock/gmock.h"
#include "Card.h"
#include "Player.h"


class MockPlayer : public Player {
 public:
    explicit MockPlayer(int pID, std::string);
    virtual ~MockPlayer() {}

    MOCK_METHOD1(updateScore, void(int adder));
    MOCK_METHOD0(getScore, int());
    MOCK_METHOD0(getName, std::string());
    MOCK_METHOD0(getID, int());
    MOCK_METHOD1(addCardHand, void(Card* c));
    MOCK_METHOD1(removeCardHand, Card*(Card* c));
    MOCK_METHOD0(getCardHand, std::vector<Card*>());
};

#endif // MOCKPLAYER_H_INCLUDED
