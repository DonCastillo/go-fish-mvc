#include "gtest/gtest.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"

enum suits { Club, Diamond, Heart, Spade };
enum ranks { Ace = 1, Two, Three, Four, Five, Six,
         Seven, Eight, Nine, Ten, Jack, Queen, King };


TEST(TestPlayer, getID) {
    Player* don = new Player(1, "Don");
    EXPECT_EQ(don->getID(), 1);
    delete don;

    Player* jane = new Player(2, "Jane");
    EXPECT_EQ(jane->getID(), 2);
    delete jane;

    Player* michael = new Player(3, "Michael");
    EXPECT_EQ(michael->getID(), 3);
    delete michael;
}


TEST(TestPlayer, getName) {
    Player* don = new Player(1, "Don");
    EXPECT_EQ(don->getName(), "Don");
    delete don;

    Player* jane = new Player(2, "Jane");
    EXPECT_EQ(jane->getName(), "Jane");
    delete jane;

    Player* michael = new Player(3, "Michael");
    EXPECT_EQ(michael->getName(), "Michael");
    delete michael;
}


TEST(TestPlayer, scoring) {
    Player* don = new Player(1, "Don");

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
    Player* don = new Player(1, "Don");
    Player* jane = new Player(2, "Jane");

    // should be empty card hand upon initialization
    EXPECT_EQ(don->getCardHand().size(), 0);
    EXPECT_EQ(jane->getCardHand().size(), 0);

    // test for non empty card hand
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
}


TEST(TestPlayer, removeCardHand) {
    Player* don = new Player(1, "Don");
    Card* lookingFor = new Card(Spade, Seven);

    // empty hand
    EXPECT_EQ(don->getCardHand().size(), 0);
    EXPECT_EQ(don->removeCardHand(lookingFor), nullptr);

    // contains card
    Card* a = new Card(Spade, Five);
    don->addCardHand(a);
    EXPECT_EQ(don->getCardHand().size(), 1);
    EXPECT_EQ(don->removeCardHand(lookingFor), nullptr);
    EXPECT_EQ(don->getCardHand().size(), 1);

    // contains more than one card
    Card* b = new Card(Spade, Six);
    Card* c = new Card(Spade, Seven);
    Card* d = new Card(Spade, Eight);
    don->addCardHand(b);
    don->addCardHand(c);
    don->addCardHand(d);
    EXPECT_EQ(don->getCardHand().size(), 4);
    Card* removedCard = don->removeCardHand(lookingFor);
    EXPECT_TRUE(removedCard->getRank() == "7" &&
                removedCard->getSuit() == "Spade");
    EXPECT_EQ(don->getCardHand().size(), 3);

    delete don;
}
