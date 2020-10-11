#ifndef TESTGOFISH_H_INCLUDED
#define TESTGOFISH_H_INCLUDED

#include <vector>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "GoFish.h"
#include "Player.h"


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

TEST(TestGoFish, addingAndGettingPlayers) {
    Player* player1 = new Player(0, "Player 1");
    Player* player2 = new Player(1, "Player 2");

    MockGoFish gf = new MockGoFish();

    // no player added
    EXPECT_EQ(gf->getPlayers().size(), 0);
    //gf->addPlayer(player1);
    //gf->addPlayer(player2);
    delete player1;
    delete player2;
    delete gf;
}
#endif // TESTGOFISH_H_INCLUDED
