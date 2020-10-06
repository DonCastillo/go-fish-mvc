#include "Card.h"
#include "gtest/gtest.h"
#include <iostream>

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
            std::cout << counter << std::endl;
            delete c;
        }
    }

//    Card* ClubAce = new Card(Club, Ace);
//    EXPECT_EQ(ClubAce->getSuit(), "Club");
//    delete ClubAce;
//
//    Card* DiamondAce = new Card(Diamond, Ace);
//    EXPECT_EQ(DiamondAce->getSuit(), "Diamond");
//    delete DiamondAce;
//
//    Card* HeartAce = new Card(Heart, Ace);
//    EXPECT_EQ(HeartAce->getSuit(), "Heart");
//    delete HeartAce;
//
//    Card* SpadeAce = new Card(Spade, Ace);
//    EXPECT_EQ(SpadeAce->getSuit(), "Spade");
//    delete SpadeAce;
}


TEST(TestCard, getRank) {
    Card* ClubAce = new Card(Club, Ace);
    EXPECT_EQ(ClubAce->getRank(), "Ace");
    delete ClubAce;

    Card* ClubTwo = new Card(Club, Two);
    EXPECT_EQ(ClubTwo->getRank(), "2");
    delete ClubTwo;

    Card* ClubQueen = new Card(Club, Queen);
    EXPECT_EQ(ClubQueen->getRank(), "Queen");
    delete ClubQueen;

    Card* ClubKing = new Card(Club, King);
    EXPECT_EQ(ClubKing->getRank(), "King");
    delete ClubKing;
}


TEST(TestCard, formatRank) {
    Card* DiamondAce = new Card(Diamond, Ace);
    EXPECT_EQ(DiamondAce->formatRank(Ace), "Ace");
    delete DiamondAce;

    Card* DiamondTwo = new Card(Diamond, Two);
    EXPECT_EQ(DiamondTwo->formatRank(Two), "2");
    delete DiamondTwo;

    Card* DiamondQueen = new Card(Diamond, Queen);
    EXPECT_EQ(DiamondQueen->formatRank(Queen), "Queen");
    delete DiamondQueen;

    Card* DiamondKing = new Card(Diamond, King);
    EXPECT_EQ(DiamondKing->formatRank(King), "King");
    delete DiamondKing;
}


TEST(TestCard, formatSuit) {
    Card* DiamondAce = new Card(Diamond, Ace);
    EXPECT_EQ(DiamondAce->formatSuit(Diamond), "Diamond");
    delete DiamondAce;

    Card* ClubAce = new Card(Club, Ace);
    EXPECT_EQ(ClubAce->formatSuit(Club), "Club");
    delete ClubAce;

    Card* HeartAce = new Card(Heart, Ace);
    EXPECT_EQ(HeartAce->formatSuit(Heart), "Heart");
    delete HeartAce;

    Card* SpadeAce = new Card(Spade, Ace);
    EXPECT_EQ(SpadeAce->formatSuit(Spade), "Spade");
    delete SpadeAce;
}



