/*!
   \file Player class header
   \brief defines the member data and methods of Player class
   \author Don Castillo
   \date 07/10/2020
*/

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string>
#include <vector>
#include "Card.h"

class Player {
 public:
   /*!
      \brief constructor
      \param  pID player's unique identification
      \param  pName player's name
   */
    Player(int pID, std::string pName);

    /*!
       \brief destructor
       \brief deletes all cards in player's hand
    */
    ~Player();

    /*!
       \brief updates score
       \param adder if the value is negative or zero, score remains unchanged
                    if the value is positive, it is added to the current score
    */
    void updateScore(int adder);

    /*!
       \brief get the player's score
       \return current player's score
    */
    int getScore();

    /*!
       \brief get the player's name
       \return player's name
    */
    std::string getName();

    /*!
       \brief get the player's ID
       \return player's ID
    */
    int getID();

    /*!
       \brief adds a card to the player's hand
       \param c Card object to be added
    */
    void addCardHand(Card* c);

    /*!
       \brief removes card from the player's hand
       \param c Card object to be removed
       \return card removed from the player's hand
       \return  nullptr if no card is returned
    */
    Card* removeCardHand(Card* c);

    /*!
       \brief get all the cards from the player's hand
       \return vector<Card*> collection of cards
               currently in the player's hand
    */
    std::vector<Card*> getCardHand();
    //Card* selectFromHand();

 private:
    std::string name;
    int score = 0;
    int id = -1;
    std::vector<Card*> hand;
};

#endif // CARD_H_INCLUDED
