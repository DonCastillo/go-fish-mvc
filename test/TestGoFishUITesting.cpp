#include <vector>
#include "gtest/gtest.h"
#include "GoFishUITesting.h"
#include "Player.h"
#include "Card.h"

enum suits { Club, Diamond, Heart, Spade };
enum ranks { Ace = 1, Two, Three, Four, Five, Six,
             Seven, Eight, Nine, Ten, Jack, Queen, King };

TEST(TestRandomize, enterName) {
    GoFishUITesting* ui = new GoFishUITesting();
    EXPECT_EQ(ui->enterName(), "Dummy");
    delete ui;
}


TEST(TestRandomize, enterNumberOfPlayers) {
    GoFishUITesting* ui = new GoFishUITesting();
    EXPECT_EQ(ui->enterNumberOfPlayers(), 2);
    delete ui;
}

TEST(TestRandomize, selectCardFromHand) {
    GoFishUITesting* ui = new GoFishUITesting();
    Player* dummy = new Player(0, "Dummy");

    // empty hand
    EXPECT_EQ(ui->selectCardFromHand(dummy), nullptr);

    // one element
    dummy->addCard(new Card(Club, Ace));
    EXPECT_NE(ui->selectCardFromHand(dummy), nullptr);

    // more elements
    dummy->addCard(new Card(Diamond, Two));
    Card* returnedCard = ui->selectCardFromHand(dummy);
    EXPECT_TRUE(returnedCard->getSuit() == "Club" ||
                returnedCard->getSuit() == "Diamond");
    EXPECT_TRUE(returnedCard->getRank() == "Ace" ||
                returnedCard->getRank() == "2");

    delete dummy;
    delete ui;
}
