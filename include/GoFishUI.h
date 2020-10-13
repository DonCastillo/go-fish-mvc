/*!
   \file GoFishUI class header
   \brief defines the member data and methods of GoFish UI class
   \author Don Castillo
   \date 12/10/2020
*/
#ifndef GOFISHUI_H_INCLUDED
#define GOFISHUI_H_INCLUDED
#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include <vector>
#include <string>

class GoFishUI {
 public:
   /*!
      \brief constructor
   */
    GoFishUI();

    /*!
       \brief destructor
    */
    ~GoFishUI();

    /*!
       \brief prints without new line
       \param message content to be printed
    */
    void print(std::string message);

    /*!
       \brief prints with new line
       \param message content to be printed
    */
    void println(std::string message);

    /*!
       \brief prints players scores
       \param players collection of players
    */
    void printScores(std::vector<Player*> players);

    /*!
       \brief prints message to show player's turn.
       \param pPlayer  player
    */
    void printPlayerTurn(Player* pPlayer);

    /*!
       \brief prints congratulatory message
       \param pPlayer player
    */
    void printCongratulate(Player* pPlayer);

    /*!
       \brief prints deck
       \param current game deck
    */
    void printDeck(Deck* pDeck);

    /*!
       \brief prints player's cards in hand
       \param pPlayer player whose hand to be printed
    */
    void printPlayerHand(Player* pPlayer);

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
       \brief prints welcome message at the start of the game
    */
    void printWelcome();

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

   /*!
      \brief prints title
      \param title  title to be displayed
   */
    void setTitle(std::string title);

    /*!
       \brief prints a row of text with filler characters
              in between
       \param left  text to be displayed in the left side
              right text to be displayed in the right side
    */
    void setRow(std::string left, std::string right);

    /*!
       \brief prints a row of text with filler characters
              in between and a character printed on the far left
       \param index text displayed on the far left of the row
              left  text displayed in the middle
              right text displayed on the far right of the row
    */
    void setRow(int index, std::string left, std::string right);

    /*!
       \brief prints cards with suit printed on the left
              and rank printed on the right
       \param pCards  collection of cards to be printed
    */
    void printCards(std::vector<Card*> pCards);

 protected:
    /** line width */
    const int LINEWIDTH = 35;

    /** character fillers in the title */
    const char TITLEFILL = '=';

    /** character fillers in the line*/
    const char LINEFILL = '.';
};

#endif // GOFISHUI_H_INCLUDED
