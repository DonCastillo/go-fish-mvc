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
//    bool fish(Player* pPlayer, Deck* pDeck);
    void addPlayer(Player* pPlayer);
    void deal();
    Card* drawCard(Player* pPlayer);

    /// getters
    Deck* getDeck();
    std::vector<Player*> getPlayers();


 private:
    Deck* deck;
    std::vector<Player*> players;


};

#endif // GOFISH_H_INCLUDED
