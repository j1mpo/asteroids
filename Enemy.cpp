#include "Enemy.h"
#include <sgg/graphics.h>
#include "config.h"
#include <random>
#include "util.h"
#include "game.h"



void Enemy::update() 
{
    pos_x -= speed * graphics::getDeltaTime();
    rotation += 0.05f * graphics::getDeltaTime();
    rotation = fmodf(rotation, 360);

    if (pos_x < -size)
    {
        active = false;
    }
}

void Enemy::draw()
{
    graphics::drawRect(pos_x - 10, pos_y +30, size, size, brush);
    brush.texture = std::string(ASSET_PATH) + "asteroid_1.png.png";
    brush.fill_opacity = 1.0f;
    graphics::drawRect(pos_x, pos_y, size, size, brush);
    graphics::resetPose();




}
    

Disk Enemy::getCollisionHull() const
{
    return Disk();
}

void Enemy::init() 
{

    speed = 0.3f;
    pos_x = CANVAS_WIDTH + 1.1f * size;
    pos_y = CANVAS_HEIGHT * rand0to1();
    size = 50 + 100 * rand0to1();
    rotation = 360 * rand0to1();
    brush.outline_opacity = 0.0f;
    
}

Enemy::Enemy(const Game& mygame)
    : GameObject(mygame)
{
    init();
}

Enemy::~Enemy()
{

}
