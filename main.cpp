// main.cpp

#include "gamestate.h"
#include "player.h"
#include "level.h"
#include <sgg/graphics.h>

void init()
{
    GameState::getInstance()->init();  // ?????????? ??? GameState
}

void draw()
{
    GameState::getInstance()->draw();
}

void update(float dt)
{
    GameState::getInstance()->update(dt);
}

int main(int argc, char** argv)
{
    graphics::createWindow(800, 800, "Asteroid Game");

    init();

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(GameState::getInstance()->getCanvasWidth(), GameState::getInstance()->getCanvasHeight());
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::startMessageLoop();

    return 0;
}
