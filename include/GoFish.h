#ifndef GOFISH_H_INCLUDED
#define GOFISH_H_INCLUDED
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "GoFishUI.h"

class GoFish {
 public:
    GoFish();
    ~GoFish();
    void addPlayer(Player* pPlayer);
    void deal();
    void fish(Player* pPlayer);
    bool isThereABook(Player* pPlayer);
    bool askCard(Player* p1, Player* p2, Card* targetCard);
    Deck* getDeck();
    std::vector<Player*> getPlayers();
    std::vector<Player*> getWinner();
    void startGame();
    bool anyoneHasCard();
    Player* getRandomPlayer();


 private:
    Deck* deck;
    std::vector<Card*> books;
    std::vector<Player*> players;
    GoFishUI* ui;
};

#endif // GOFISH_H_INCLUDED
