#include <vector>
#include "gtest/gtest.h"
#include "MockGoFish.h"
#include "MockDeck.h"
#include "MockPlayer.h"
#include "GoFishUI.h"
#include "GoFishUITesting.h"
#include "GoFish.h"
#include "Player.h"

using ::testing::_;
using ::testing::Return;
using ::testing::Expectation;
using ::testing::AtLeast;

TEST(TestGoFish, addingAndGettingPlayers) {
    GoFish* gf = new GoFish(new GoFishUITesting());
    Player* jane = new Player(0, "Jane");
    Player* don = new Player(1, "Don");

    // check for empty player in player's vector
    EXPECT_EQ(gf->getPlayers().size(), 0);

    gf->addPlayer(jane);
    gf->addPlayer(don);

    // check non empty player vector
    EXPECT_EQ(gf->getPlayers().size(), 2);
    delete gf;
}


TEST(TestGoFish, gettingDeck) {
    GoFish* gf = new GoFish(new GoFishUITesting());

    // should have an uninitialized deck
    EXPECT_EQ(gf->getDeck(), nullptr);
    delete gf;
}


TEST(TestGoFish, getWinner) {
    GoFish* gf = new GoFish(new GoFishUITesting());

    // no player
    EXPECT_TRUE(gf->getWinner().empty());

    // one player
    MockPlayer michael(0, "Michael");
    michael->updateScore(1);

    EXPECT_CALL(michael, getScore())
    .Times(AtLeast(2))
    .WillOnce(Return(1))
    .WillRepeatedly(Return(1));

    for (Player* p : gf->getWinner()) {
        EXPECT_EQ(p->getName(), "Michael");
    }


    delete gf;
}


