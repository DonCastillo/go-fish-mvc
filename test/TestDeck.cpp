#include <vector>
#include "Deck.h"
#include "Card.h"
#include "gtest/gtest.h"



enum suits { Club, Diamond, Heart, Spade };
enum ranks { Ace = 1, Two, Three, Four, Five, Six,
             Seven, Eight, Nine, Ten, Jack, Queen, King };

TEST(TestDeck, createAndClearDeck) {
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


TEST(TestDeck, shuffle) {
    Deck* deck = new Deck();

    // test unshuffled
    std::vector<Card*>unshuffledCards;
    std::vector<Card*>shuffledCards;
    std::vector<Card*>original;

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

    original.push_back(a);
    original.push_back(b);
    original.push_back(c);
    original.push_back(d);
    original.push_back(e);
    original.push_back(f);
    original.push_back(g);
    original.push_back(h);
    original.push_back(i);
    original.push_back(j);

    // compare unshuffled cards and unshuffle compare
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(unshuffledCards[i]->getSuit(),
                  original[i]->getSuit());
        EXPECT_EQ(unshuffledCards[i]->getRank(),
                  original[i]->getRank());
    }


    // test shuffled
    deck->shuffle();
    for (Card* c : deck->getDeck()) {
        shuffledCards.push_back(c);
    }


    int numberOfTrues = 0;
    for (int i = 0; i < 10; ++i) {
        if (shuffledCards[i]->getSuit() !=
            original[i]->getSuit() ||
            shuffledCards[i]->getRank() !=
            original[i]->getRank()) {
            numberOfTrues++;
        }
    }

    // should have 60% trues to be completely shuffled
    EXPECT_GT(numberOfTrues, 4);

    for (Card* c : original) {
        delete c;
    }

    delete deck;
}


TEST(TestDeck, getTopCard) {
    Deck* deck = new Deck();

    // check empty deck
    deck->clearDeck();
    EXPECT_EQ(deck->getTopCard(), nullptr);

    // check non empty deck
    deck->createDeck();
    Card* original = new Card(Spade, King);
    Card* topCard = deck->getTopCard();

    EXPECT_TRUE(original->getSuit() == topCard->getSuit());
    EXPECT_TRUE(original->getRank() == topCard->getRank());

    delete original;
    delete deck;
}



