#ifndef MOCKDECK_H_INCLUDED
#define MOCKDECK_H_INCLUDED

#include <vector>
#include "gmock/gmock.h"
#include "Card.h"
#include "Deck.h"


class MockDeck : public Deck {
 public:
    explicit MockDeck() {}
    virtual ~MockDeck() {}

    MOCK_METHOD0(getDeck, std::vector<Card*>());
    MOCK_METHOD0(shuffle, void());
    MOCK_METHOD0(createDeck, void());
    MOCK_METHOD0(getTopCard, Card*());
    MOCK_METHOD0(clearDeck, void());
};

#endif // MOCKDECK_H_INCLUDED
