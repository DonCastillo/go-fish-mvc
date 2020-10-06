#include "Card.h"
#include "gtest/gtest.h"

enum suits { Club = 0, Diamond = 1, Heart = 2, Spade = 3 };
enum ranks { Ace = 1, Two = 2, Three = 3, Four = 4, Five = 5,
             Six = 6, Seven = 7, Eight = 8, Nine = 9, Ten = 10,
             Jack = 11, Queen = 12, King = 13 };


TEST(TestCard, getSuit) {
    int counter = 1;
    for (int s = Club; s <= Spade; ++s) {
        for (int r = Ace; r <= King; ++r) {
            Card* c = new Card(s, r);

            if (counter <= 13) {
                EXPECT_EQ(c->getSuit(), "Club");
            } else if (counter <= 26) {
                EXPECT_EQ(c->getSuit(), "Diamond");
            } else if (counter <= 39) {
                EXPECT_EQ(c->getSuit(), "Heart");
            } else {
                EXPECT_EQ(c->getSuit(), "Spade");
            }

            ++counter;
            delete c;
        }
    }
}


TEST(TestCard, getRank) {
    int counter = 1;
    for (int r = Ace; r <= King; ++r) {
        for (int s = Club; s <= Spade; ++s) {
            Card* c = new Card(s, r);

            if (counter <= 4) {
                EXPECT_EQ(c->getRank(), "Ace");
            } else if (counter <= 8) {
                EXPECT_EQ(c->getRank(), "2");
            } else if (counter <= 12) {
                EXPECT_EQ(c->getRank(), "3");
            } else if (counter <= 16) {
                EXPECT_EQ(c->getRank(), "4");
            } else if (counter <= 20) {
                EXPECT_EQ(c->getRank(), "5");
            } else if (counter <= 24) {
                EXPECT_EQ(c->getRank(), "6");
            } else if (counter <= 28) {
                EXPECT_EQ(c->getRank(), "7");
            } else if (counter <= 32) {
                EXPECT_EQ(c->getRank(), "8");
            } else if (counter <= 36) {
                EXPECT_EQ(c->getRank(), "9");
            } else if (counter <= 40) {
                EXPECT_EQ(c->getRank(), "10");
            } else if (counter <= 44) {
                EXPECT_EQ(c->getRank(), "Jack");
            } else if (counter <= 48) {
                EXPECT_EQ(c->getRank(), "Queen");
            } else {
                EXPECT_EQ(c->getRank(), "King");
            }

            ++counter;
            delete c;
        }
    }
}


TEST(TestCard, formatRank) {
    int counter = 1;
    for (int r = Ace; r <= King; ++r) {
        for (int s = Club; s <= Spade; ++s) {
            Card* c = new Card(s, r);

            if (counter <= 4) {
                EXPECT_EQ(c->formatRank(Ace), "Ace");
            } else if (counter <= 8) {
                EXPECT_EQ(c->formatRank(Two), "2");
            } else if (counter <= 12) {
                EXPECT_EQ(c->formatRank(Three), "3");
            } else if (counter <= 16) {
                EXPECT_EQ(c->formatRank(Four), "4");
            } else if (counter <= 20) {
                EXPECT_EQ(c->formatRank(Five), "5");
            } else if (counter <= 24) {
                EXPECT_EQ(c->formatRank(Six), "6");
            } else if (counter <= 28) {
                EXPECT_EQ(c->formatRank(Seven), "7");
            } else if (counter <= 32) {
                EXPECT_EQ(c->formatRank(Eight), "8");
            } else if (counter <= 36) {
                EXPECT_EQ(c->formatRank(Nine), "9");
            } else if (counter <= 40) {
                EXPECT_EQ(c->formatRank(Ten), "10");
            } else if (counter <= 44) {
                EXPECT_EQ(c->formatRank(Jack), "Jack");
            } else if (counter <= 48) {
                EXPECT_EQ(c->formatRank(Queen), "Queen");
            } else {
                EXPECT_EQ(c->formatRank(King), "King");
            }

            ++counter;
            delete c;
        }
    }
}


TEST(TestCard, formatSuit) {
    int counter = 1;
    for (int s = Club; s <= Spade; ++s) {
        for (int r = Ace; r <= King; ++r) {
            Card* c = new Card(s, r);

            if (counter <= 13) {
                EXPECT_EQ(c->formatSuit(Club), "Club");
            } else if (counter <= 26) {
                EXPECT_EQ(c->formatSuit(Diamond), "Diamond");
            } else if (counter <= 39) {
                EXPECT_EQ(c->formatSuit(Heart), "Heart");
            } else {
                EXPECT_EQ(c->formatSuit(Spade), "Spade");
            }

            ++counter;
            delete c;
        }
    }
}



