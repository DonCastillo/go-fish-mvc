#ifndef GOFISH_H_INCLUDED
#define GOFISH_H_INCLUDED

#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

class GoFish {
 public:
    GoFish();
    ~GoFish();
    void addPlayer(Player* pPlayer);
    void deal();
    void fish(Player* pPlayer);
    bool isThereABook(Player* pPlayer);
    bool askCard(Player* p1, Player* p2);
    Deck* getDeck();
    std::vector<Player*> getPlayers();


 private:
    Deck* deck;
    std::vector<Player*> players;
};

#endif // GOFISH_H_INCLUDED
