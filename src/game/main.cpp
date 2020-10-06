#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "GoFish.h"
#include <vector>
#include <string>


int main() {
    /*
        welcome sign
        how many players
        enter names
        insert players to gofish controller
        new deck
        shuffle deck
        deal cards
        all players check for books
        randomly select a players turn

        ** iterate while !deck.empty() && all players cards are not yet empty
        check if deck is not empty &&
        check if all players have cards left
            Y:

                bool askedPlayer = false

                A.
                if player cards isnt empty
                    B. player checks for books
                            yes => remove all books
                                   add score to player
                                   go to A
                            no =>

                                if askedPlayer = false
                                   C. select a card from the player's own hands
                                      select player
                                      ask the selected player for a card
                                      bool: askedPlayer = true
                                      go to A.

                                if askedPlayer  = true
                                    fish
                                    break

                else,
                    fish


            next Player
            go to Y

    */
}
