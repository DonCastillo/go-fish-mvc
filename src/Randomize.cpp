#include "Randomize.h"
#include <time.h>
#include <vector>
#include <cstdlib>
#include <algorithm>

Randomize::Randomize() {}

Randomize::~Randomize() {}

int Randomize::randomize(int minInt, int maxInt) {
    if (minInt == maxInt) {
        return minInt;
    } else if (minInt > maxInt) {
        return minInt;
    } else {
        std::vector<int> integers;
        for (int i = minInt; i <= maxInt; ++i) {
            integers.push_back(i);
        }
        for (int i = 0; i < 5; ++i) {
            std::srand(time(0));
            std::random_shuffle(integers.begin(), integers.end());
            std::random_shuffle(integers.begin(), integers.end());
            std::random_shuffle(integers.begin(), integers.end());
        }
        return integers.back();
    }
}
