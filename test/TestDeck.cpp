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
    std::vector<Card*>unshuffledCards;
    std::vector<Card*>unshuffledCompare;

    deck->createDeck();
    for (Card* c : deck->getDeck()) {
        unshuffledCards.push_back(c);
    }

    Card* a = new Card(Club, Ace);
    Card* b = new Card(Club, Two);
    Card* c = new Card(Club, Three);
    Card* d = new Card(Club, Four);
    Card* e = new Card(Club, Five);
    Card* f = new Card(Club, Six);
    Card* g = new Card(Club, Seven);
    Card* h = new Card(Club, Eight);
    Card* i = new Card(Club, Nine);
    Card* j = new Card(Club, Ten);

    unshuffledCompare.push_back(a);
    unshuffledCompare.push_back(b);
    unshuffledCompare.push_back(c);
    unshuffledCompare.push_back(d);
    unshuffledCompare.push_back(e);
    unshuffledCompare.push_back(f);
    unshuffledCompare.push_back(g);
    unshuffledCompare.push_back(h);
    unshuffledCompare.push_back(i);
    unshuffledCompare.push_back(j);

    // compare unshuffled cards and unshuffle compare
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(unshuffledCards[i]->getSuit(), unshuffledCompare[i]->getSuit());
        EXPECT_EQ(unshuffledCards[i]->getRank(), unshuffledCompare[i]->getRank());
    }

    for (Card* c : unshuffledCompare) {
        delete c;
    }

    delete deck;
}



