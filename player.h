#pragma once
#include "gameobject.h"
#include "config.h"


class Player : public GameObject, public Collidable
{
   
    //graphics::Brush m_brush_player;  // Brush ??? ?? ???????? sprite
    //graphics::Brush m_brush_glow;    // Brush ??? ?? glow effect
    //graphics::Brush m_brush_player;
    //Box m_box;
    float speed = 2.0f;
    float pos_x = CANVAS_WIDTH / 2, pos_y = CANVAS_HEIGHT / 2;
    float height = 1.0f;
    float life = 1.0f;


public:
    // Default Constructor
    //Player() : GameObject("Default"), m_box(0, 0, 1, 1) {}

    // Constructor ?? ???????????
    Player(const class Game& mygame);
    void update() override;
    void init() override;
    void draw() override;
    float getPosY() { return pos_y; }
    float getPosX() { return pos_x; }
    Disk getCollisionHull() const override;
    float getRemainingLife() const { return life;  }
    void drainLife(float amount) { life = std::max(0.0f, life - amount); }




};
