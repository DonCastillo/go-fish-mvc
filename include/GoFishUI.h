#ifndef GOFISHUI_H_INCLUDED
#define GOFISHUI_H_INCLUDED
#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include <vector>
#include <string>

class GoFishUI {
 public:
    GoFishUI();
    ~GoFishUI();
    void print(std::string message);
    void println(std::string message);
    void printScores(std::vector<Player*> players);
    void printPlayerTurn(Player* pPlayer);
    void printCongratulate(Player* pPlayer);
    void printDeck(Deck* pDeck);
    void printPlayerHand(Player* pPlayer);
    std::string enterName();
    int enterNumberOfPlayers();
    void printWelcome();
    Card* selectCardFromHand(Player* pPlayer);
    Player* selectPlayer(Player* currentPlayer,
                         std::vector<Player*> allPlayers);
    void setTitle(std::string title);
    void setRow(std::string left, std::string right);
    void setRow(int index, std::string left, std::string right);

 private:
    void printCards(std::vector<Card*> pCards);
    const int LINEWIDTH = 35;
    const char TITLEFILL = '=';
    const char LINEFILL = '.';
};

#endif // GOFISHUI_H_INCLUDED
