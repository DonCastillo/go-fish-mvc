/*!
   \file Card class header
   \brief defines the member data and methods of Card class
   \author Don Castillo
   \date 07/10/2020
*/

#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <string>

class Card {
 public:
   /*!
      \brief  constructor
      \param  s suit number
      \param  r rank number
   */
    Card(int s, int r);

    /*!
       \brief destructor
    */
    ~Card();

    /*!
       \brief get the card's suit identifier
       \return card suit identifier
    */
    std::string getSuit();

    /*!
       \brief get the card's rank identifier
       \return card rank identifier
    */
    std::string getRank();

    /*!
       \brief formats rank from integer to string equivalent
       \param pRank card rank in integer
       \return string equivalent of the rank in integer
    */
    std::string formatRank(int pRank);

    /*!
       \brief formats suit from integer to string equivalent
       \param pSuit card suit in integer
       \return  string equivalent of the suit in integer
    */
    std::string formatSuit(int pSuit);

 private:
    /** card suit */
    std::string cSuit;

    /** card rank*/
    std::string cRank;
};

#endif // CARD_H_INCLUDED
