#pragma once
#include "gameobject.h"
#include "box.h"
#include <sgg/graphics.h>

class Bullet : public GameObject, public Box
{
    graphics::Brush m_brush_bullet;
    float m_velocity_x, m_velocity_y;

public:
    // ?????????? ?????? ???????? ??? ????????????
    Bullet(float x, float y, float angle, float velocity);
    void update(float dt) override;
    void draw() override;
};
