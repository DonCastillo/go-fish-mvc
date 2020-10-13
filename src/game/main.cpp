#include "GoFish.h"
#include "GoFishUI.h"

int main() {
    GoFishUI* ui = new GoFishUI();
    GoFish* gf = new GoFish(ui);
    gf->startGame();

    delete gf;
}
