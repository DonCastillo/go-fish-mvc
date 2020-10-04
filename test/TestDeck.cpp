#include "gtest/gtest.h"
#include "Deck.h"
#include "Card.h"
#include <vector>

enum suits { Club, Diamond, Heart, Spade };
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


TEST(TestCard, shuffle) {
    Deck* deck = new Deck();
//    std::vector<Card*>unshuffledCards;
//    std::vector<Card*>unshuffledCompare;
//
//    deck->createDeck();
//    for (Card* c : deck->getDeck()) {
//        unshuffledCards.push_back(c);
//    }
//
//    unshuffledCompare.push_back(new Card(Club, Ace));
//    unshuffledCompare.push_back(new Card(Club, Two));
//    unshuffledCompare.push_back(new Card(Club, Three));
//    unshuffledCompare.push_back(new Card(Club, Four));
//    unshuffledCompare.push_back(new Card(Club, Five));
//    unshuffledCompare.push_back(new Card(Club, Six));
//    unshuffledCompare.push_back(new Card(Club, Seven));
//    unshuffledCompare.push_back(new Card(Club, Eight));
//    unshuffledCompare.push_back(new Card(Club, Nine));
//
//    // compare unshuffled cards and unshuffle compare
//    for (int i = 0; i < 10; ++i) {
//        EXPECT_EQ(unshuffledCards[i]->getSuit(), unshuffledCompare[i]->getSuit());
//        EXPECT_EQ(unshuffledCards[i]->getRank(), unshuffledCompare[i]->getRank());
//    }
//
//    // delete all object pointers
//    for (Card* c : unshuffledCards) {
//        delete c;
//    }
//    for (Card* c : unshuffledCompare) {
//        delete c;
//    }
    delete deck;
}



