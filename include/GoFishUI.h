#ifndef GOFISHUI_H_INCLUDED
#define GOFISHUI_H_INCLUDED
#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include <vector>

class GoFishUI {
 public:
    GoFishUI();
    ~GoFishUI();
    void printScores(std::vector<Player*> players);
    void printPlayerTurn(Player* pPlayer);
    void congratulate(Player* pPlayer);
    void printDeck(Deck* pDeck);
    void printPlayerHand(Player* pPlayer);

 private:
    void printCards(std::vector<Card*> pCards);
};

#endif // GOFISHUI_H_INCLUDED
