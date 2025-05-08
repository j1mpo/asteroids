#include "player.h"
#include "game.h"
#include <sgg/graphics.h>

Player::Player(const Game& mygame)
    : GameObject(mygame)
{
}


void Player::gainLife(float amount)
{
    life += amount;
    if (life > 1.0f)
    {
        life = 1.0f; //  maximum (1.0)
    }
}

void Player::update() {


    if (graphics::getKeyState(graphics::SCANCODE_A))
    {
        pos_x -= speed * graphics::getDeltaTime() / 7.5f; //kinhsh aristera
    }
    if (graphics::getKeyState(graphics::SCANCODE_D))
    {
        pos_x += speed * graphics::getDeltaTime() / 7.5f; // kinhsh dejia
    }
    if (pos_x < 0)
    {
        pos_x = CANVAS_WIDTH; // Αν βγει αριστερά, μετακινείται στην δεξιά πλευρά
    }
    else if (pos_x > CANVAS_WIDTH)
    {
        pos_x = 0; // Αν βγει δεξιά, μετακινείται στην αριστερή πλευρά
    }
}

void Player::init() 
{
}

void Player::draw()
{

    graphics::Brush br;
    br.outline_opacity = 0.0f;

    
    graphics::setScale(height, height);
    br.fill_opacity = 2.5f;
    br.texture = std::string(ASSET_PATH) + "p.png"; // emfanish tou xarakthra
    graphics::drawRect(pos_x, pos_y, 200, 120, br);

    graphics::resetPose();

    if (game.getDebugModel()) // emfanish tou hitbox an thesw true to DebugModel
    {
        br.outline_opacity = 1.0f;
        br.texture = "";
        br.fill_color[0] = 0.3f;
        br.fill_color[1] = 1.0f;
        br.fill_color[2] = 0.3f;
        br.fill_opacity = 0.3f;
        br.gradient = false;
        Disk hull = getCollisionHull();
        graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);
    }

}

Disk Player::getCollisionHull() const // dhmioyrgia tou hitbox
{
    Disk disk;
    disk.cx = pos_x;
    disk.cy = pos_y;
    disk.radius = 55.0f;
    return disk;
}
