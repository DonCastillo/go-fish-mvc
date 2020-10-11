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

//    // after initializing the deck
//    gf->startGame();
//    EXPECT_NE(gf->getDeck(), nullptr);
}
