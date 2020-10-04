#include "Card.h"
#include "gtest/gtest.h"


enum suits { Club = 0, Diamond = 1, Heart = 2, Spade = 3 };
enum ranks { Ace = 1, Two = 2, Three = 3, Four = 4, Five = 5,
             Six = 6, Seven = 7, Eight = 8, Nine = 9, Ten = 10,
             Jack = 11, Queen = 12, King = 13 };


TEST(TestCard, getSuit) {

    Card* ClubAce = new Card(Club, Ace);
    EXPECT_EQ(ClubAce->getSuit(), "Club");
    delete ClubAce;

    Card* DiamondAce = new Card(Diamond, Ace);
    EXPECT_EQ(DiamondAce->getSuit(), "Diamond");
    delete DiamondAce;

    Card* HeartAce = new Card(Heart, Ace);
    EXPECT_EQ(HeartAce->getSuit(), "Heart");
    delete HeartAce;

    Card* SpadeAce = new Card(Spade, Ace);
    EXPECT_EQ(SpadeAce->getSuit(), "Spade");
    delete SpadeAce;
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
    EXPECT_EQ(DiamondAce->formatRank(DiamondAce->getRank()), "Ace");
    delete DiamondAce;

    Card* DiamondTwo = new Card(Diamond, Two);
    EXPECT_EQ(DiamondTwo->formatRank(DiamondTwo->getRank()), "2");
    delete DiamondTwo;

    Card* DiamondQueen = new Card(Diamond, Queen);
    EXPECT_EQ(DiamondQueen->formatRank(DiamondQueen->getRank()), "Queen");
    delete DiamondQueen;

    Card* DiamondKing = new Card(Diamond, King);
    EXPECT_EQ(DiamondKing->formatRank(DiamondKing->getRank()), "King");
    delete DiamondKing;
}


TEST(TestCard, formatSuit) {

    Card* DiamondAce = new Card(Diamond, Ace);
    EXPECT_EQ(DiamondAce->formatSuit(DiamondAce->getSuit()), "Diamond");
    delete DiamondAce;

    Card* ClubAce = new Card(Club, Ace);
    EXPECT_EQ(ClubAce->formatSuit(ClubAce->getSuit()), "Club");
    delete ClubAce;

    Card* HeartAce = new Card(Heart, Ace);
    EXPECT_EQ(HeartAce->formatSuit(HeartAce->getSuit()), "Heart");
    delete HeartAce;

    Card* SpadeAce = new Card(Spade, Ace);
    EXPECT_EQ(SpadeAce->formatSuit(SpadeAce->getSuit()), "Spade");
    delete SpadeAce;
}


