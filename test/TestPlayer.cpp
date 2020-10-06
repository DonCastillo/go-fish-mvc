#include "gtest/gtest.h"
#include "Player.h"
#include "Deck.h"
#include "GoFish.h"


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


TEST(TestPlayer, scoring) {

    Player* don = new Player("Don");

    // test if score is 0 upon initialization
    EXPECT_EQ(don->getScore(), 0);

    don->updateScore(1);
    EXPECT_EQ(don->getScore(), 1);

    don->updateScore(19);
    EXPECT_EQ(don->getScore(), 20);

    // same value if negative or 0 is passed
    don->updateScore(-1);
    EXPECT_EQ(don->getScore(), 20);

    don->updateScore(-19);
    EXPECT_EQ(don->getScore(), 20);

    don->updateScore(0);
    EXPECT_EQ(don->getScore(), 20);

    don->updateScore(1);
    EXPECT_EQ(don->getScore(), 21);

    delete don;
}


TEST(TestPlayer, getCardHand) {
    Player* don = new Player("Don");
    Player* jane = new Player("Jane");

    // should be empty card hand upon initialization
    EXPECT_EQ(don->getCardHand().size(), 0);
    EXPECT_EQ(jane->getCardHand().size(), 0);

    // test for non empty card hand
    GoFish* gf = new GoFish();
    gf->addPlayer(don);
    gf->addPlayer(jane);
//    gf->deal();

    // Players should have 7 cards each
//    EXPECT_EQ(don->getCardHand().size(), 7);
//    EXPECT_EQ(jane->getCardHand().size(), 7);


    delete gf;
    delete jane;
    delete don;

}
