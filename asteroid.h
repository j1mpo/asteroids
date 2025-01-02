#pragma once
#include "gameobject.h"
#include "box.h"
#include <sgg/graphics.h>

class Asteroid : public GameObject, public Box
{
    graphics::Brush m_brush_asteroid;
    float m_velocity;

public:
    Asteroid(std::string name = "Asteroid");

    void update(float dt) override;
    void init() override;
    void draw() override;
};
