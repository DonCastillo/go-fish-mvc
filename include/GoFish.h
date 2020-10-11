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
   /*!
      \brief constructor
   */
    GoFish(GoFishUI* pUI);

    /*!
       \brief destructor
       \brief deletes all GoFish pointers (i.e. deck, ui, players, books)
    */
    ~GoFish();

    /*!
       \brief adds player to the game
       \param pPlayer player
    */
    virtual void addPlayer(Player* pPlayer);

    /*!
       \brief distributes cards to players
              2 - 3 players get 7 cards each
              4 - 5 players get 5 cards each
    */
    virtual void deal();

    /*!
       \brief lets the player draw a card from the deck
       \param pPlayer player
    */
    virtual void fish(Player* pPlayer);

    /*!
       \brief finds out if there is a book in the player's hands
       \brief if there is a book, removed the cards from the
              player's hands and put them into the books container
       \param pPlayer player
       \return true if there is a book, otherwise false
    */
    virtual bool isThereABook(Player* pPlayer);

    /*!
       \brief asks player from the other player if he has a card
       \param p1  requestor
              p2  requestee
              targetCard  card that is asked
       \return true if there is at least one matching card
               from the requestee that matches the targetCard (the rank)
               asked by the requestor, otherwise false
    */
    virtual bool askCard(Player* p1, Player* p2, Card* targetCard);

    /*!
       \brief gets the current deck of the game
       \return game's deck
    */
    virtual Deck* getDeck();

    /*!
       \brief returns all the players of the game
       \param all players
    */
    virtual std::vector<Player*> getPlayers();

    /*!
       \brief returns all the winners
       \return winners
    */
    virtual std::vector<Player*> getWinner();

    /*!
       \brief main game
    */
    virtual void startGame();

    /*!
       \brief finds out if at least one player has at least one
              card in his hand
       \return true if at least one player has at least one card
               in his hand, otherwise false
    */
    virtual bool anyoneHasCard();

    /*!
       \brief finds out who gets to play first
       \return random player
    */
    virtual Player* getRandomPlayer();


 private:
    /** game deck */
    Deck* deck;

    /** collection of books, cards with same ranks
    removed from the player's hands */
    std::vector<Card*> books;

    /** players in the game */
    std::vector<Player*> players;

    /** user interface of GoFish */
    GoFishUI* ui;
};

#endif // GOFISH_H_INCLUDED
