#include <vector>
#include "gtest/gtest.h"
#include "MockGoFish.h"
#include "MockDeck.h"
#include "MockPlayer.h"
#include "MockCard.h"
#include "GoFishUI.h"
#include "GoFishUITesting.h"
#include "GoFish.h"
#include "Player.h"
#include "Deck.h"

using ::testing::_;
using ::testing::Return;
using ::testing::Expectation;
using ::testing::AtLeast;
using ::testing::InSequence;

/** collection of suit names */
enum suits { Club, Diamond, Heart, Spade };

/** collection of rank names */
enum ranks { Ace = 1, Two, Three, Four, Five, Six,
             Seven, Eight, Nine, Ten, Jack, Queen, King };

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
    // 1 player, gets 5 cards
    GoFish* game0 = new GoFish(new GoFishUITesting());
    game0->addPlayer(new Player(0, "Vance"));
    game0->setDeck(new Deck());
    game0->deal();

    for (Player* p : game0->getPlayers()) {
        EXPECT_EQ(p->getCardHand().size(), 5);
    }

    delete game0;

    // 3 players, each one gets 7 cards
    GoFish* game1 = new GoFish(new GoFishUITesting());
    game1->addPlayer(new Player(0, "Phyllis"));
    game1->addPlayer(new Player(1, "Creed"));
    game1->addPlayer(new Player(2, "Andy"));
    game1->setDeck(new Deck());
    game1->deal();

    for (Player* p : game1->getPlayers()) {
        EXPECT_EQ(p->getCardHand().size(), 7);
    }

    delete game1;

    // 5 player, each one gets 5 cards each
    GoFish* game2 = new GoFish(new GoFishUITesting());
    game2->addPlayer(new Player(0, "Phyllis"));
    game2->addPlayer(new Player(1, "Creed"));
    game2->addPlayer(new Player(2, "Andy"));
    game2->addPlayer(new Player(3, "Ryan"));
    game2->addPlayer(new Player(4, "Kelly"));
    game2->setDeck(new Deck());
    game2->deal();

    for (Player* p : game2->getPlayers()) {
        EXPECT_EQ(p->getCardHand().size(), 5);
    }

    delete game2;
}


TEST(TestGoFish, gettingRandomPlayer) {
    GoFish* gf = new GoFish(new GoFishUITesting());

    // empty player
    EXPECT_EQ(gf->getRandomPlayer(), nullptr);

    // nonempty player
    gf->addPlayer(new Player(0, "Karen"));
    gf->addPlayer(new Player(1, "Roy"));

    EXPECT_NE(gf->getRandomPlayer(), nullptr);
    delete gf;
}


TEST(TestGoFish, anyoneHasCard) {
    GoFish* gf = new GoFish(new GoFishUITesting());

    // empty player
    EXPECT_FALSE(gf->anyoneHasCard());

    Player* jan = new Player(0, "Jan");
    Player* carol = new Player(1, "Carol");
    Player* holly = new Player(2, "Holly");
    Player* donna = new Player(3, "Donna");
    Player* helene = new Player(4, "Helene");

    gf->addPlayer(jan);
    gf->addPlayer(carol);
    gf->addPlayer(donna);

    // non empty player, no one has card
    EXPECT_FALSE(gf->anyoneHasCard());

    // at least one player has card
    holly->addCardHand(new Card(Club, Ace));
    gf->addPlayer(holly);

    EXPECT_TRUE(gf->anyoneHasCard());

    // two players
    helene->addCardHand(new Card(Club, Diamond));
    gf->addPlayer(helene);

    EXPECT_TRUE(gf->anyoneHasCard());

    delete gf;
}



TEST(TestGoFish, fish) {
    GoFish* gf = new GoFish(new GoFishUITesting());
    gf->setDeck(new Deck());

    Player* deangelo = new Player(0, "Deangelo");
    gf->addPlayer(deangelo);


    // no player has not fished yet
    EXPECT_EQ((gf->getDeck())->getDeck().size(), 52);

    // player fishes one card
    gf->fish(gf->getPlayers()[0]);
    EXPECT_EQ((gf->getDeck())->getDeck().size(), 51);

    // player fishes 10 times
    for (int i = 0; i < 10; ++i) {
        gf->fish(gf->getPlayers()[0]);
    }
    EXPECT_EQ((gf->getDeck())->getDeck().size(), 41);

    // player fishes all card left
    for (int i = 0; i < 41; ++i) {
        gf->fish(gf->getPlayers()[0]);
    }
    EXPECT_EQ((gf->getDeck())->getDeck().size(), 0);

    // fish to an empty deck
    gf->fish(gf->getPlayers()[0]);
    EXPECT_EQ((gf->getDeck())->getDeck().size(), 0);

    delete gf;
}


TEST(TestGoFish, askCard) {
    GoFish* gf = new GoFish(new GoFishUITesting());
    Player* jim = new Player(0, "Jim");
    Player* pam = new Player(1, "Pam");
//    MockPlayer jim(0, "Jim");
//    MockPlayer pam(1, "Pam");
//    MockCard a(Club, Ace);
//    MockCard b(Club, Two);
//    MockCard c(Club, Three);
//    MockCard d(Club, Four);
//    MockCard e(Diamond, Ace);


    // asking someone with an empty hand
    EXPECT_FALSE(gf->askCard(jim, pam, new Card(Club, Ace)));


    // asking someone with one matching card at hand
    pam->addCardHand(new Card(Diamond, Ace));
    EXPECT_TRUE(gf->askCard(jim, pam, new Card(Club, Ace)));

    // asking someone with three matching cards
    pam->addCardHand(new Card(Diamond, Ace));
    pam->addCardHand(new Card(Spade, Ace));
    pam->addCardHand(new Card(Heart, Ace));
    EXPECT_TRUE(gf->askCard(jim, pam, new Card(Club, Ace)));

    // asking someone with nonempty non matching cards
    pam->addCardHand(new Card(Club, Two));
    pam->addCardHand(new Card(Club, Three));
    pam->addCardHand(new Card(Club, Four));
    EXPECT_FALSE(gf->askCard(jim, pam, new Card(Club, Ace)));
    delete gf;
}

















