#include "Card.h"
#include <iostream>
#include <string>

Card::Card(int s, int r) {
    cRank = formatRank(r);
    cSuit = formatSuit(s);
    //std::cout << cSuit << " : " << cRank << std::endl;
    //rankNum = r;
}

Card::~Card() { }

std::string Card::getSuit() {
    return cSuit;
}

std::string Card::getRank() {
    return cRank;
}

std::string Card::formatRank(int pRank) {
    std::string temp;

    switch (pRank) {
        case 1:
            temp = "Ace";
            break;
        case 2:
            temp = "2";
            break;
        case 3:
            temp = "3";
            break;
        case 4:
            temp = "4";
            break;
        case 5:
            temp = "5";
            break;
        case 6:
            temp = "6";
            break;
        case 7:
            temp = "7";
            break;
        case 8:
            temp = "8";
            break;
        case 9:
            temp = "9";
            break;
        case 10:
            temp = "10";
            break;
        case 11:
            temp = "Jack";
            break;
        case 12:
            temp = "Queen";
            break;
        case 13:
            temp = "King";
            break;
    }
    return temp;
}


std::string Card::formatSuit(int pSuit) {
    std::string temp;

    switch (pSuit) {
        case 0:
            temp = "Club";
            break;
        case 1:
            temp = "Diamond";
            break;
        case 2:
            temp = "Heart";
            break;
        case 3:
            temp = "Spade";
            break;
    }
    return temp;
}
