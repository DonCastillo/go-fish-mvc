#include <vector>
#include "gtest/gtest.h"
#include "MockGoFish.h"
#include "MockDeck.h"
#include "MockPlayer.h"
#include "GoFishUITesting.h"
#include "GoFish.h"
#include "Player.h"

using ::testing::_;
using ::testing::Return;
using ::testing::Expectation;

TEST(TestGoFish, addingAndGettingPlayers) {
    GoFish* gf = new GoFish(new GoFishUITesting());

    // check for empty player in player's vector
    EXPECT_EQ(gf->getPlayers().size(), 0);

    gf->addPlayer(new Player(0, "Jane"));
    gf->addPlayer(new Player(1, "Don"));

    // check non empty player vector
    EXPECT_EQ(gf->getPlayers().size(), 2);

    delete gf;
}
