#include "Deck.h"
#include "gtest/gtest.h"

enum ranks { Ace = 1, Two, Three, Four, Five, Six,
             Seven, Eight, Nine, Ten, Jack, Queen, King };

TEST(TestCard, createAndClearDeck) {
    Deck* deck = new Deck();
    deck->createDeck();

    // check of a complete deck of card is created
    EXPECT_EQ(deck->getDeck().size(), 52);
    EXPECT_FALSE(deck->getDeck().empty());

    deck->clearDeck();

    // check if deck is cleared
    EXPECT_EQ(deck->getDeck().size(), 0);
    EXPECT_TRUE(deck->getDeck().empty());

    deck->createDeck();

    // check if deck is created again
    EXPECT_EQ(deck->getDeck().size(), 52);
    EXPECT_FALSE(deck->getDeck().empty());

    delete deck;
}



