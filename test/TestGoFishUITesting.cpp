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
    dummy->addCardHand(new Card(Club, Ace));
    EXPECT_NE(ui->selectCardFromHand(dummy), nullptr);

    // more elements
    dummy->addCardHand(new Card(Diamond, Two));
    Card* returnedCard = ui->selectCardFromHand(dummy);
    EXPECT_TRUE(returnedCard->getSuit() == "Club" ||
                returnedCard->getSuit() == "Diamond");
    EXPECT_TRUE(returnedCard->getRank() == "Ace" ||
                returnedCard->getRank() == "2");

    delete dummy;
    delete ui;
}

TEST(TestRandomize, selectPlayer) {
    GoFishUITesting* ui = new GoFishUITesting();
    Player* dummy1 = new Player(0, "Dummy1");
    Player* dummy2 = new Player(1, "Dummy2");
    Player* dummy3 = new Player(2, "Dummy3");
    std::vector<Player*> allPlayers;
    Player* selectedPlayer;

    // no player to choose
    selectedPlayer = ui->selectPlayer(dummy1, allPlayers);
    EXPECT_EQ(selectedPlayer, nullptr);

    // there is a player to choose
    allPlayers.push_back(dummy2);
    allPlayers.push_back(dummy3);
    selectedPlayer = ui->selectPlayer(dummy1, allPlayers);
    EXPECT_TRUE(selectedPlayer->getID() == 1 ||
                selectedPlayer->getID() == 2);

    EXPECT_TRUE(selectedPlayer->getName() == "Dummy2" ||
                selectedPlayer->getName() == "Dummy3");

    delete dummy1;
    delete dummy2;
    delete dummy3;
    delete ui;
}
