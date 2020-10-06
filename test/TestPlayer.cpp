#include "gtest/gtest.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"


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
    enum suits { Club, Diamond, Heart, Spade };
    enum ranks { Ace = 1, Two, Three, Four, Five, Six,
             Seven, Eight, Nine, Ten, Jack, Queen, King };

    Card* a = new Card(Club, Ace);
    Card* b = new Card(Club, Two);
    Card* c = new Card(Club, Three);
    Card* d = new Card(Club, Four);
    Card* e = new Card(Club, Five);

    don->addCardHand(a);
    don->addCardHand(b);
    don->addCardHand(c);
    jane->addCardHand(d);
    jane->addCardHand(e);

    EXPECT_EQ(don->getCardHand().size(), 3);
    EXPECT_EQ(jane->getCardHand().size(), 2);

    delete don;
    delete jane;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
}
