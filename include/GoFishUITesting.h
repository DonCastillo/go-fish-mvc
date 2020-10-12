#ifndef GOFISHUITESTING_H_INCLUDED
#define GOFISHUITESTING_H_INCLUDED
#include "GoFish.h"
#include <string>
#include <vector>

class GoFishUITesting : public GoFishUI {
 public:
   /*!
      \brief constructor
   */
    GoFishUITesting();

    /*!
       \brief destructor
    */
    ~GoFishUITesting();

    /*!
       \brief retrieves player's name from the input
       \return player's name
    */
    virtual std::string enterName();

    /*!
       \brief retrieves an integer indicating the number of
             players in the game
       \return number of players in the game
    */
    virtual int enterNumberOfPlayers();

    /*!
       \brief asks the player to select card from his hand based
              on the card's index
       \param pPlayer player whose hands will contain cards to
                      be selected
       \return card that is selected
    */
    virtual Card* selectCardFromHand(Player* pPlayer);

    /*!
       \brief asks the player to select another player to
              ask for a matching card based on card rank
       \param currentPlayer player who's going to select a player
              allPlayers  all players in the game
       \return player selected
    */
    virtual Player* selectPlayer(Player* currentPlayer,
                         std::vector<Player*> allPlayers);
};

#endif // GOFISHUITESTING_H_INCLUDED
