/*!
   \file Deck class header
   \brief defines the member data and methods of Deck class
   \author Don Castillo
   \date 07/10/2020
*/
#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include <string>
#include "Card.h"
#include <vector>

class Deck {
 public:
   /*!
      \brief constructor
      \brief  creates and shuffles deck upon creation
   */
    Deck();

    /*!
       \brief destructor
       \brief deletes all cards in the deck
    */
    ~Deck();

    /*!
       \brief returns the current deck, creted and shuffled
       \return vector<Card*> collection of cards in the deck
    */
    std::vector<Card*> getDeck();

    /*!
       \brief shuffles the current cards in the deck
    */
    void shuffle();

    /*!
       \brief creates a complete deck of unshuffled cards
    */
    void createDeck();

    /*!
       \brief pick a card from the deck
       \return  Card* returns the card on the top of the stack
    */
    Card* getTopCard();

    /*!
       \brief removes all the cards from the deck
       \brief results to an empty deck
    */
    void clearDeck();

 private:
   /** collection of suit names */
   enum suits { Club, Diamond, Heart, Spade };

   /** collection of rank names */
   enum ranks { Ace = 1, Two, Three, Four, Five, Six,
                 Seven, Eight, Nine, Ten, Jack, Queen, King };

   /** collection of cards in the deck */
   std::vector<Card*> allCards;
};

#endif // DECK_H_INCLUDED
