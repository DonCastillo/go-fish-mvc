#include "GoFish.h"
#include "GoFishUI.h"

int main() {
    GoFishUI* ui = new GoFish();
    GoFish* gf = new GoFish(ui);
    gf->startGame();

    delete ui;
    delete gofish;
}
