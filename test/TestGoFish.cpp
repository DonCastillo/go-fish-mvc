#include <vector>
#include "gtest/gtest.h"
#include "MockGoFish.h"
#include "MockDeck.h"
#include "MockPlayer.h"
#include "GoFishUI.h"
#include "GoFishUITesting.h"
#include "GoFish.h"
#include "Player.h"
#include "Deck.h"

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

    // after initializing the deck
    Deck* deck = new Deck();
    gf->setDeck(deck);
    EXPECT_NE(gf->getDeck(), nullptr);
    delete gf;
}


TEST(TestGoFish, getWinner) {
    //    MockPlayer michael(0, "Michael");
//    michael.updateScore(1);
//
//    EXPECT_CALL(michael, getScore())
//    .Times(AtLeast(2))
//    .WillOnce(Return(1))
//    .WillRepeatedly(Return(1));
    GoFish* gf = new GoFish(new GoFishUITesting());

    // no player
    EXPECT_TRUE(gf->getWinner().empty());

    // one player
    Player* michael = new Player(0, "Michael");
    michael->updateScore(1);
    gf->addPlayer(michael);

    for (Player* p : gf->getWinner()) {
        EXPECT_EQ(p->getName(), "Michael");
    }

    // three players
    Player* jim = new Player(1, "Jim");
    Player* pam = new Player(2, "Pam");
    jim->updateScore(4);
    pam->updateScore(2);
    gf->addPlayer(jim);
    gf->addPlayer(pam);

    for (Player* p : gf->getWinner()) {
        EXPECT_EQ(p->getName(), "Jim");
    }

    delete gf;
}



TEST(TestGoFish, deal) {
    Player* phyllis = new Player(0, "Phyllis");
    Player* creed = new Player(1, "Creed");
    Player* andy = new Player(2, "Andy");
    Player* ryan = new Player(3, "Ryan");
    Player* kelly = new Player(4, "Kelly");

    // 3 players, each one gets 7 cards
    GoFish* game1 = new GoFish(new GoFishUITesting());
    game1->addPlayer(phyllis);
    game1->addPlayer(creed);
    game1->addPlayer(andy);
    game1->setDeck(new Deck());
    game1->deal();

    EXPECT_EQ(phyllis->getCardHand().size(), 7);
    EXPECT_EQ(creed->getCardHand().size(), 7);
    EXPECT_EQ(andy->getCardHand().size(), 7);
    delete game1;

    // 5 player, each one gets 5 cards each
    GoFish* game2 = new GoFish(new GoFishUITesting());
    game2->addPlayer(phyllis);
    game2->addPlayer(creed);
    game2->addPlayer(andy);
    game2->addPlayer(ryan);
    game2->addPlayer(ryan);
    game2->setDeck(new Deck());
    game2->deal();
    EXPECT_EQ(phyllis->getCardHand().size(), 5);
    EXPECT_EQ(creed->getCardHand().size(), 5);
    EXPECT_EQ(andy->getCardHand().size(), 5);
    EXPECT_EQ(ryan->getCardHand().size(), 5);
    EXPECT_EQ(kelly->getCardHand().size(), 5);
    delete game2;
}
