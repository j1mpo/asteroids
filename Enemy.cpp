#include "Enemy.h"
#include <sgg/graphics.h>
#include "config.h"
#include <random>
#include "util.h"
#include "game.h"



void Enemy::update()
{
    pos_y += speed * graphics::getDeltaTime(); //metakinhsh katheta
    rotation += 0.05f * graphics::getDeltaTime(); //peristrofh
    rotation = fmodf(rotation, 360);

    if (pos_y > CANVAS_HEIGHT + size)
    {
        active = false; //false otan vgei ektos oriwn
    }

}

void Enemy::draw()
{
    graphics::setOrientation(rotation);
    brush.texture = std::string(ASSET_PATH) + "b.png.png";
    brush.fill_opacity = 1.0f;
    graphics::drawRect(pos_x, pos_y, size, size, brush);
    graphics::resetPose();

    if (game.getDebugModel()) //emfanizei hitbox otan thesw DebugModel true
    {
        graphics::Brush br;
        br.outline_opacity = 1.0f;
        br.texture = "";
        br.fill_color[0] = 1.0f;
        br.fill_color[1] = 0.3f;
        br.fill_color[2] = 0.3f;
        br.fill_opacity = 0.3f;
        br.gradient = false;
        Disk hull = getCollisionHull();
        graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);
    }

}

float Enemy::getPosY() const
{
    return pos_y; //getter
}

Disk Enemy::getCollisionHull() const //hitbox
{
    Disk disk;
    disk.cx = pos_x;
    disk.cy = pos_y;
    disk.radius = size * 0.45f;
    return disk;
}

void Enemy::init() //diamorfvsh megethwn
{

    speed = 0.5f;
    pos_y = -size;
    pos_x = CANVAS_WIDTH * rand0to1();
    size = 50 + 100 * rand0to1();
    rotation = 360 * rand0to1();
    brush.outline_opacity = 0.0f;

}

Enemy::Enemy(const Game& mygame) //dhmiourgia antikeikenoy
    : GameObject(mygame)
{
    init();
}

Enemy::~Enemy()
{

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
