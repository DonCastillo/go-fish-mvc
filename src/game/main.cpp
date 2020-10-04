#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "GoFish.h"
#include <vector>
#include <string>


void printCards(std::vector<Card*> cards) {
    for (Card* d : cards) {
    std::cout << "---------------" << std::endl;
        std::cout << d->getSuit() << " : " << d->getRank() << std::endl;
    }
}

int main() {
//    Deck* deck = new Deck();
//    //std::cout << (deck->getDeck()).size();
//    deck->shuffle();
//    for(Card* c : deck->getDeck())
//    {
//      //  std::cout << c->getSuit() << "-" << c->getRank() << std::endl;
//    }
//
//    Player* player = new Player("Don");
//    std::cout << player->getName() << std::endl;
//    player->updateScore(1);
//    player->updateScore(-12);
//    std::cout << player->getScore() << std::endl;
//    Card* a = new Card(0,1); // clubs, ace
//    Card* b = new Card(0,2); // clubs, 2
//    Card* c = new Card(0,3); // clubs, 3
//    Card* d = new Card(0,4); //clubs, 4
//    player->addCard(a);
//    player->addCard(b);
//    player->addCard(c);
//    player->addCard(d);
//    player->removeCard(new Card(0,3));
//    for(Card* h : player->getCards()){
//        std::cout << h->getSuit() << "--" << h->getRank() << std::endl;
//    }
    GoFish* gf = new GoFish();
    Player* don = new Player("Don");
    Player* jane = new Player("Jane");
    gf->addPlayer(don);
    gf->addPlayer(jane);
    gf->deal();

    std::cout << "******" << std::endl;
    std::cout << don->getName() << std::endl;
    printCards(don->getCardHand());
    gf->isThereABook(don);
    std::cout << "******" << std::endl;
    std::cout << jane->getName() << std::endl;
    printCards(jane->getCardHand());
    gf->isThereABook(jane);
    std::cout << "******" << std::endl;
    std::cout << "******" << std::endl;
    Card* donCard = don->selectFromHand();
    std::cout << donCard->getSuit() << std::endl;
    std::cout << donCard->getRank() << std::endl;

    std::cout << "******" << std::endl;
    std::cout << "******" << std::endl;
    printCards(don->getCardHand());

    std::cout << std::boolalpha << gf->askCard(don, jane);

//std::vector<int>nums;
//nums.push_back(1);
//nums.push_back(2);
//nums.push_back(3);
//std::cout << "Front: " << nums.front() << std::endl;
//nums.erase(nums.begin());
//for(int i : nums){
//    std::cout << i << std::endl;
//}
}
