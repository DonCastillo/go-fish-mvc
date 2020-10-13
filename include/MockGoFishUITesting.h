/*!
   \file MockGoFishUITesting class header
*/
#ifndef MOCKGOFISHUITESTING_H_INCLUDED
#define MOCKGOFISHUITESTING_H_INCLUDED

#include <string>
#include <vector>
#include "GoFishUITesting.h"
#include "gmock/gmock.h"

class MockGoFishUITesting : public GoFishUITesting {
 public:
    explicit MockGoFishUITesting() {}
    virtual ~MockGoFishUITesting() {}

    MOCK_METHOD0(enterName, std::string());
    MOCK_METHOD0(enterNumberOfPlayers, int());
    MOCK_METHOD1(selectCardFromHand, Card*(Player* pPlayer));
    MOCK_METHOD2(selectPlayer, Player*(Player* currentPlayer,
                                       std::vector<Player*> allPlayers));
};

#endif // GOFISHUITESTING_H_INCLUDED
