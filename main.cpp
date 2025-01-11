#include "gamestate.h"
#include "spaceship.h"
#include <sgg/graphics.h>

void init() {
    GameState::getInstance()->init();  // Initialize the game state
}

void draw() {
    GameState::getInstance()->draw();  // Draw game objects
}

void update(float dt) {
    GameState::getInstance()->update(dt);  // Update the game objects
}

int main(int argc, char** argv) {
    graphics::createWindow(800, 600, "Spaceship Game");

    init();

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::startMessageLoop();

    return 0;
}
