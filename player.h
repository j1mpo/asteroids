#pragma once
#include "gameobject.h"
#include "config.h"
#include "util.h"+


class Player : public GameObject, public Collidable
{

    float speed = 2.0f;
    float pos_x = CANVAS_WIDTH / 2, pos_y = CANVAS_HEIGHT - 50.0f; //topothetish xarakthra sto kentro
    float height = 1.0f;
    float life = 1.0f;


public:

    Player(const class Game& mygame);
    void update() override;
    void init() override;
    void draw() override;
    float getPosY() { return pos_y; }
    float getPosX() { return pos_x; }
    Disk getCollisionHull() const override;
    float getRemainingLife() const { return life; }
    void drainLife(float amount) { life = std::max(0.0f, life - amount); }
    void gainLife(float amount);


};
