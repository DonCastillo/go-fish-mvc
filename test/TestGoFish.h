#ifndef TESTGOFISH_H_INCLUDED
#define TESTGOFISH_H_INCLUDED

#include <vector>
#include "gmock/gmock.h"
#include "GoFish.h"


using ::testing;

class MockGoFish : public GoFish {
 public:
    explicit MockGoFish() {}
    virtual ~MockGoFish() {}

    MOCK_METHOD1(addPlayer, void(Player* pPlayer));
    MOCK_METHOD0(deal, void());
    MOCK_METHOD1(fish, void(Player* pPlayer));
    MOCK_METHOD1(isThereABook, bool(Player* pPlayer));
    MOCK_METHOD3(askCard, bool(Player* p1, Player* p2, Card* targetCard));
    MOCK_METHOD0(getDeck, Deck*());
    MOCK_METHOD0(getPlayers, std::vector<Player*>());
    MOCK_METHOD0(getWinner, std::vector<Player*>());
    MOCK_METHOD0(startGame, void());
    MOCK_METHOD0(anyoneHasCard, bool());
    MOCK_METHOD0(getRandomPlayer, Player*());
}

#endif // TESTGOFISH_H_INCLUDED