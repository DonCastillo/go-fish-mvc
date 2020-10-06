#include "gtest/gtest.h"
#include "Player.h"


TEST(TestPlayer, getName) {

    Player* don = new Player("Don");
    EXPECT_EQ(don->getName(), "Don");
    delete don;

    Player* jane = new Player("Jane");
    EXPECT_EQ(jane->getName(), "Jane");
    delete jane;

    Player* michael = new Player("Michael");
    EXPECT_EQ(michael->getName(), "Michael");
    delete michael;
}



