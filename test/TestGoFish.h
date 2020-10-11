#ifndef TESTGOFISH_H_INCLUDED
#define TESTGOFISH_H_INCLUDED

#include "gmock/gmock.h"
#include "GoFish.h"

using ::testing;

class MockGoFish : public GoFish {
 public:
    explicit MockGoFish() {}
    virtual ~MockGoFish() {}
}

#endif // TESTGOFISH_H_INCLUDED
