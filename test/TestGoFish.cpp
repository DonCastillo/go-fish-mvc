#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockGoFish.h"
#include "GoFishUITesting.h"

using ::testing::_;
using ::testing::Return;
using ::testing::Expectation;

TEST(TestGoFish, addingAndGettingPlayers) {
    MockGoFish gf(new GoFishUITesting());

    Expectation e = EXPECT_CALL(gf, addPlayer(_))
    .Times(2);

    EXPECT_CALL(gf, getPlayers())
    .Times(1)
    .After(e)

    gf.addPlayer(new Player(0, "Player 1"));
    gf.addPlayer(new Player(1, "Player 2"));
    gf.getPlayers();

}
