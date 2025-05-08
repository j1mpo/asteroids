#include "game.h"
#include "Enemy.h"
#include <sgg/graphics.h>
#include "config.h"

//main 

void resize(int w, int h)
{
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    game->setWindowDimensions((unsigned int)w, (unsigned)h);
}

void draw() {
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    game->draw();
}

void update(float ms) {
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    game->update();
}
//main methodos edw trexei to paixnidi
int main() {

    Game mygame;

    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Krabby Patties");
    graphics::setUserData(&mygame);
    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);
    graphics::setCanvasSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
    graphics::setResizeFunction(resize);


    mygame.init();
    mygame.setDebugModel(false); //false svinei hitbox kai cords voitha sto development
    graphics::startMessageLoop();

    return 0;
}
