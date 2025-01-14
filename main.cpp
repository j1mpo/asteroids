#include "game.h"
#include "Enemy.h"
#include <sgg/graphics.h>
#include "config.h"



void resize(int w, int h)
{
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    game->setWindowDimensions((unsigned int)w, (unsigned)h);
}

void draw() {
    Game* game = reinterpret_cast<Game *>(graphics::getUserData());
    game->draw();
}

void update(float ms) {
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    game->update();
}

int main() {

    Game mygame;

    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Spaceship Game");
    graphics::setUserData(&mygame);
    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);
    graphics::setCanvasSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);


    mygame.init();
    mygame.setDebugModel(true);
    graphics::startMessageLoop();

    return 0;
}
