#ifndef MOCKGOFISH_H_INCLUDED
#define MOCKGOFISH_H_INCLUDED

#include <vector>
#include "gmock/gmock.h"
#include "GoFish.h"
#include "Player.h"
#include "GoFishUITesting.h"
#include "GoFishUI.h"


class MockGoFish : public GoFish {
 public:
    explicit MockGoFish(GoFishUI* pUI) :
        GoFish(pUI) {}
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
};

#endif // MOCKGOFISH_H_INCLUDED
